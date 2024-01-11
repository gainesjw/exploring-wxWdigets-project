#ifndef __BASE_H__
#define __BASE_H__

namespace App {

    class MainApp : public wxApp
    {
        public:
            virtual bool OnInit();
    };

    class MainFrame : public wxFrame
    {
        public:
            MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
            wxButton* HelloWorld;
            wxTextCtrl* HeyWorld;
            void OnExit(wxCommandEvent& event);
            void DeclareText(wxCommandEvent& event);

            DECLARE_EVENT_TABLE()
    };

    enum
    {
        BUTTON_HELLO = wxID_HIGHEST + 1,
        TEXT_HELLO = wxID_HIGHEST + 2
    };

DECLARE_APP(MainApp)

}

#endif