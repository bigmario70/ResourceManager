//  Resource Loader application with Observer Design Pattern
//  Written by Mario Cei
//  09/2023

#ifndef WX_PRECOMP
#include <wx/wxprec.h>
#include <wx/wx.h>
#endif

//Model and controller Classes
#include "Observer.h"
#include "Model.h"
#include "Controller.h"

// Declaration of the Application Class
class MyApp: public wxApp
{
public:
    bool OnInit() override;
};

// Tells wxWidgets which is the application class to instantiate
wxIMPLEMENT_APP(MyApp);

enum
{
    ID_LoadFromFile = 1,
    ID_ResListBox=3,
    ID_DeleteItem=4,
    ID_InsertItem=5,
    ID_NewItem_TextCtrl=6
};

class MyFrame : public wxFrame, public Observer {
public:
    MyFrame(Model* m, Controller* c);
    virtual ~MyFrame(){
        resModel->unsubscribe(this);
    }
    void update() override;

private:
    void OnLoadFromFile(wxCommandEvent& event);
    void OnSaveToFile(wxCommandEvent& event);
    void OnDeleteItem(wxCommandEvent& event);
    void OnInsertItem(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    wxListBox* resListBox;
    wxTextCtrl* newItemTextCtrl;
    Model* resModel;
    Controller* controller;
};

bool MyApp::OnInit() {
    Model*  myModel = new Model();
    Controller *myController = new Controller(myModel);
    MyFrame *frame = new MyFrame(myModel,myController);
    frame->Show(true);
    return true;
}

MyFrame::MyFrame(Model* m, Controller* c):resModel(m),controller(c),
         wxFrame(nullptr, wxID_ANY, "Resource Manager",wxDefaultPosition,wxSize(500,600),wxDEFAULT_FRAME_STYLE,"ResourceManager")
{
    resModel->subscribe(this);

    // FRAME COMPOSITION

    //    Menù bar composition

    auto *menuFile = new wxMenu;
    menuFile->Append(ID_LoadFromFile, "&Load from file...\tCtrl-L",
                     "Load data from file");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_SAVE, "&Save to file...\tCtrl-S",
                     "Save data to file");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);

    auto *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);

    auto *menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuHelp, "&Help");

    SetMenuBar( menuBar );

    //    Status bar definition

    CreateStatusBar();
    SetStatusText("Welcome to wxWidgets!");

    wxArrayString initialResources;


    auto resListBoxLabel = new wxStaticText(this, wxID_ANY,"Resource list", wxPoint(10,30),wxSize(200,30),wxALIGN_CENTRE_HORIZONTAL);
    resListBox = new wxListBox(this, ID_ResListBox, wxPoint(10, 60), wxSize(200, 400), initialResources, wxLB_SINGLE);
    auto deleteButton=new wxButton(this, ID_DeleteItem, wxT("DELETE"), wxPoint(250, 100), wxDefaultSize);
    auto insertButton=new wxButton(this, ID_InsertItem, wxT("INSERT"), wxPoint(250, 150), wxDefaultSize);
    newItemTextCtrl = new wxTextCtrl(this, ID_NewItem_TextCtrl, wxEmptyString, wxPoint(400, 150), wxDefaultSize);

    Bind(wxEVT_MENU, &MyFrame::OnLoadFromFile, this, ID_LoadFromFile);
    Bind(wxEVT_MENU, &MyFrame::OnSaveToFile, this, wxID_SAVE);
    Bind(wxEVT_MENU, &MyFrame::OnAbout, this, wxID_ABOUT);
    Bind(wxEVT_MENU, &MyFrame::OnExit, this, wxID_EXIT);
    Bind(wxEVT_BUTTON, &MyFrame::OnDeleteItem, this, ID_DeleteItem);
    Bind(wxEVT_BUTTON, &MyFrame::OnInsertItem, this, ID_InsertItem);
}

void MyFrame::update(){
    auto resources =resModel->getResList();
    wxArrayString loadedResources;
    for (const auto& resource: resources){
        //wxString loadedLine(resource);
        loadedResources.Add(wxString(resource));
    }
    resListBox->Clear();
    resListBox->Set(loadedResources);
    if(resListBox->GetCount()>0)
        resListBox->SetSelection(0);
}

void MyFrame::OnExit(wxCommandEvent& event)
{
    Close(true);
}

void MyFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox("Laboratory Application that manages a list of resources","About Resource Manager"
                 , wxOK | wxICON_INFORMATION);
}

void MyFrame::OnLoadFromFile(wxCommandEvent& event)
{
    wxString defaultDir = wxT("~/CLionProjects/ResourceLoader");
    wxString defaultFileName = wxT("prova.txt");
    wxFileDialog fileDialog(this,"File Selection",defaultDir, defaultFileName,wxFileSelectorDefaultWildcardStr, wxFD_OPEN);
    if(fileDialog.ShowModal() != wxID_OK)
        return;
    wxString fileName=fileDialog.GetFilename();
    wxString dirName=fileDialog.GetDirectory();
    std::string compFileName=dirName.ToStdString()+"/"+fileName.ToStdString();
    int exitCode = controller->loadFromFile(compFileName);
    if (exitCode !=0 )
        wxMessageBox(wxT("Failed To Open File: "+compFileName),wxT("Error"),wxOK|wxCENTRE,this);
}

void MyFrame::OnSaveToFile(wxCommandEvent &event) {

    wxString defaultDir = wxT("~/CLionProjects/ResourceLoader");
    wxString defaultFileName = wxT("prova.txt");
    wxFileDialog fileDialog(this,"File Selection",defaultDir, defaultFileName,wxFileSelectorDefaultWildcardStr, wxFD_SAVE);
    if(fileDialog.ShowModal() != wxID_OK)
        return;
    wxString fileName=fileDialog.GetFilename();
    wxString dirName=fileDialog.GetDirectory();
    std::string compFileName= dirName.ToStdString() + "/" + fileName.ToStdString();
    int exitCode = controller->saveToFile(compFileName);
    if (exitCode !=0 )
        wxMessageBox(wxT("Failed To Save To File: " + compFileName), wxT("Error"), wxOK | wxCENTRE, this);
}

void MyFrame::OnDeleteItem(wxCommandEvent &event) {
    controller->deleteItemAt(resListBox->GetSelection());
}

void MyFrame::OnInsertItem(wxCommandEvent &event) {
    int position=resListBox->GetSelection();
    if(position==-1)position=0;
    controller->insertItemAt(position,newItemTextCtrl->GetValue().ToStdString());
    newItemTextCtrl->Clear();
}


