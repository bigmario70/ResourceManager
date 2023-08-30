#include <iostream>

// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include "LinesLoader.h"
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
    void OnHello(wxCommandEvent& event);
    void OnStart(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    LinesLoader myLoader;
};

enum
{
    ID_Hello = 1,ID_Start=2
};


bool MyApp::OnInit() {


    MyFrame *frame = new MyFrame();
    frame->Show(true);

    return true;
}

MyFrame::MyFrame()
        : wxFrame(nullptr, wxID_ANY, "Lines Loader"),myLoader(LinesLoader("../prova.txt"))
{
    ProgressBar myPB(&myLoader);
    wxMenu *menuFile = new wxMenu;
    menuFile->Append(ID_Hello, "&Hello...\tCtrl-H",
                     "Help string shown in status bar for this menu item");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);

    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);

    wxMenu *menuAction = new wxMenu;
    menuAction ->Append(ID_Start, "&Start Loading...\tCtrl-S",
                    "Start Loading");

    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuAction, "&Action");
    menuBar->Append(menuHelp, "&Help");

    SetMenuBar( menuBar );

    CreateStatusBar();
    SetStatusText("Welcome to wxWidgets!");

    Bind(wxEVT_MENU, &MyFrame::OnHello, this, ID_Hello);
    Bind(wxEVT_MENU, &MyFrame::OnStart, this, ID_Start);
    Bind(wxEVT_MENU, &MyFrame::OnAbout, this, wxID_ABOUT);
    Bind(wxEVT_MENU, &MyFrame::OnExit, this, wxID_EXIT);
}

void MyFrame::OnExit(wxCommandEvent& event)
{
    myLoader.print();
    Close(true);
}

void MyFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox("This is a wxWidgets Hello World example",
                 "About Hello World", wxOK | wxICON_INFORMATION);
}

void MyFrame::OnHello(wxCommandEvent& event)
{
    wxLogMessage("Hello world from wxWidgets!");
}

void MyFrame::OnStart(wxCommandEvent& event)
{
    wxLogMessage("Hello world from wxWidgets!");
    myLoader.loadLines();
}