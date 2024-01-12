#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#   include <wx/wx.h>
#endif
#include "base.h"
// Beginning base developement of first widget

IMPLEMENT_APP(App::MainApp)

bool App::MainApp::OnInit()
{
    App::MainFrame* MainWin = new App::MainFrame(_("Hello World!"), wxDefaultPosition, wxSize(1200, 800));
    MainWin->Show(true);
    SetTopWindow(MainWin);
    return true;
}

BEGIN_EVENT_TABLE(App::MainFrame, wxFrame)
    EVT_MENU(MENU_NEW, App::MainFrame::NewFile)
        EVT_MENU(MENU_OPEN, App::MainFrame::OpenFile)
        EVT_MENU(MENU_CLOSE, App::MainFrame::CloseFile)
        EVT_MENU(MENU_SAVE, App::MainFrame::SaveFile)
        EVT_MENU(MENU_SAVEAS, App::MainFrame::SaveFileAs)
        EVT_MENU(MENU_QUIT, App::MainFrame::Quit)
END_EVENT_TABLE()

App::MainFrame::MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size) : wxFrame((wxFrame*) NULL, -1, title, pos, size)
{
    CreateStatusBar(2);
    MainMenu = new wxMenuBar();
    wxMenu *FileMenu = new wxMenu();

    FileMenu->Append(MENU_NEW, wxT("&New"),
      wxT("Create a new file"));
    FileMenu->Append(MENU_OPEN, wxT("&Open"),
      wxT("Open an existing file"));
    FileMenu->Append(MENU_CLOSE, wxT("&Close"),
      wxT("Close the current document"));
    FileMenu->Append(MENU_SAVE, wxT("&Save"),
      wxT("Save the current document"));
    FileMenu->Append(MENU_SAVEAS, wxT("Save &As"),
      wxT("Save the current document under a new file name"));
    FileMenu->Append(MENU_QUIT, wxT("&Quit"),
      wxT("Quit the editor"));

    MainMenu->Append(FileMenu, wxT("File"));
    SetMenuBar(MainMenu);

    MainEditBox = new wxTextCtrl(this, TEXT_MAIN,
      wxT("Hi!"), wxDefaultPosition, wxDefaultSize,
      wxTE_MULTILINE | wxTE_RICH , wxDefaultValidator, wxTextCtrlNameStr);
      Maximize();
}

void App::MainFrame::NewFile(wxCommandEvent& WXUNUSED(event))
{
}

void App::MainFrame::OpenFile(wxCommandEvent& WXUNUSED(event))
{
//MainEditBox->LoadFile(wxT("base.h"));
}

void App::MainFrame::CloseFile(wxCommandEvent& WXUNUSED(event))
{
MainEditBox->Clear();
}

void App::MainFrame::SaveFile(wxCommandEvent& WXUNUSED(event))
{
MainEditBox->SaveFile(wxT("base.h"));
}

void App::MainFrame::SaveFileAs(wxCommandEvent& WXUNUSED(event))
{
}

void App::MainFrame::Quit(wxCommandEvent& WXUNUSED(event))
{
Close(TRUE); // Tells the OS to quit running this process
}
