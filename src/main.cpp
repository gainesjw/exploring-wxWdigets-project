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
    EVT_BUTTON(App::BUTTON_HELLO, App::MainFrame::OnExit)
        EVT_TEXT(App::TEXT_HELLO, App::MainFrame::DeclareText)
END_EVENT_TABLE()

App::MainFrame::MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size) : wxFrame((wxFrame*) NULL, -1, title, pos, size)
{
    HelloWorld = new wxButton(this, App::BUTTON_HELLO, _T("Why Hello There!"), wxDefaultPosition, wxDefaultSize, 0);
    HeyWorld = new wxTextCtrl(this, App::TEXT_HELLO, _T("Why Hey There!"), wxPoint(600, 400), wxDefaultSize, 0);
}

void App::MainFrame::OnExit(wxCommandEvent& event)
{
    Close(true);
}

void App::MainFrame::DeclareText(wxCommandEvent& event)
{
    if(!HeyWorld->IsModified())
        return;
    long insertionPoint = HeyWorld->GetInsertionPoint();
    HeyWorld->ChangeValue(HeyWorld->GetValue().Upper());
    HeyWorld->SetInsertionPoint(insertionPoint);
}