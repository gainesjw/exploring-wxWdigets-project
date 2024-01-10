#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#   include <wx/wx.h>
#endif
#include "base.h"
// Beginning base developement of first widget

IMPLEMENT_APP(App::MainApp)

bool App::MainApp::OnInit()
{
    App::MainFrame* MainWin = new App::MainFrame(_("Hello World!"), wxDefaultPosition, wxSize(300, 200));
    MainWin->Show(true);
    SetTopWindow(MainWin);
    return true;
}

App::MainFrame::MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size) : wxFrame((wxFrame*) NULL, -1, title, pos, size)
{

}