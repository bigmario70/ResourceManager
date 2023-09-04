#include <iostream>

// For compilers that support pre-compilation, includes "wx/wx.h".

#ifndef WX_PRECOMP
#include <wx/wxprec.h>
#include <wx/wx.h>
#endif

#include "ResourceLoader.h"
#include "ProgressBar.h"

class MyApp: public wxApp
{
public:
    virtual bool OnInit();
};

wxIMPLEMENT_APP(MyApp);


class MyFrame : public wxFrame
{
public:
    MyFrame();

private:
    void OnLoadFromFile(wxCommandEvent& event);
    void OnSaveToFile(wxCommandEvent& event);
    void OnDeleteItem(wxCommandEvent& event);
    void OnInsertItem(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    wxListBox* resListBox;
    wxTextCtrl* newResource;
};

enum
{
    ID_LoadFromFile = 1,
    ID_SaveToFile=2,
    ID_ListBox=3,
    ID_DeleteItem=4,
    ID_InsertItem=5,
    ID_NewItem=6
};


bool MyApp::OnInit() {
    MyFrame *frame = new MyFrame();
    frame->Show(true);
    return true;
}

MyFrame::MyFrame()
        : wxFrame(nullptr, wxID_ANY, "Resource Loader",wxDefaultPosition,wxSize(500,600),wxDEFAULT_FRAME_STYLE,"ResourceLoader")
{
    //Composizione della Barra dei Menù

    auto *menuFile = new wxMenu;
    menuFile->Append(ID_LoadFromFile, "&Load from file...\tCtrl-L",
                     "Load data from file");
    menuFile->AppendSeparator();
    menuFile->Append(ID_SaveToFile, "&Save to file...\tCtrl-S",
                     "Save data to file");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);

    auto *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);

    auto *menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuHelp, "&Help");

    SetMenuBar( menuBar );

    //Impostazione StatusBar
    CreateStatusBar();
    SetStatusText("Welcome to wxWidgets!");

    wxArrayString initialResources;
    initialResources.Add(wxT("lista vuota"));

    resListBox = new wxListBox(this, ID_ListBox, wxDefaultPosition, wxSize(200, 400), initialResources, wxLB_SINGLE);
    wxButton* deleteButton=new wxButton(this,ID_DeleteItem,wxT("DELETE"),wxPoint(250,100),wxDefaultSize);
    wxButton* insertButton=new wxButton(this,ID_InsertItem,wxT("INSERT"),wxPoint(250,150),wxDefaultSize);
    newResource = new wxTextCtrl(this,ID_NewItem,wxEmptyString,wxPoint(400,150),wxDefaultSize);

    Bind(wxEVT_MENU, &MyFrame::OnLoadFromFile, this, ID_LoadFromFile);
    Bind(wxEVT_MENU, &MyFrame::OnSaveToFile, this, ID_SaveToFile);
    Bind(wxEVT_MENU, &MyFrame::OnAbout, this, wxID_ABOUT);
    Bind(wxEVT_MENU, &MyFrame::OnExit, this, wxID_EXIT);
    Bind(wxEVT_BUTTON, &MyFrame::OnDeleteItem, this, ID_DeleteItem);
    Bind(wxEVT_BUTTON, &MyFrame::OnInsertItem, this, ID_InsertItem);


}

void MyFrame::OnExit(wxCommandEvent& event)
{
    Close(true);
}

void MyFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox("Applicazione di Laboratorio che carica risorse da un file","About Resource Loader"
                 , wxOK | wxICON_INFORMATION);
}


void MyFrame::OnLoadFromFile(wxCommandEvent& event)
{

    ResourceLoader myLoader("../prova.txt");
    ProgressBar myPB(&myLoader,this);
    try {
        myLoader.loadLines();
    }
    catch(const std::exception& e){
        return;
    }
    resListBox->Clear();
    auto resources =myLoader.getLines();
    wxArrayString loadedResources;
    for (const auto& resource: resources){
        wxString lineacaricata(resource);
        loadedResources.Add(lineacaricata);
    }

    //resListBox->Clear();
    resListBox->Set(loadedResources);
}

void MyFrame::OnSaveToFile(wxCommandEvent &event) {

}

void MyFrame::OnDeleteItem(wxCommandEvent &event) {

    resListBox->Delete(resListBox->GetSelection());

}

void MyFrame::OnInsertItem(wxCommandEvent &event) {

    resListBox->Insert(newResource->GetValue(), resListBox->GetSelection());

}