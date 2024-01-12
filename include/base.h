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
            wxTextCtrl* MainEditBox;
            wxMenuBar* MainMenu;
            void Quit(wxCommandEvent& event);
            void NewFile(wxCommandEvent& event);
            void OpenFile(wxCommandEvent& event);
            void SaveFile(wxCommandEvent& event);
            void SaveFileAs(wxCommandEvent& event);
            void CloseFile(wxCommandEvent& event);

            DECLARE_EVENT_TABLE()
    };

    enum
    {
        TEXT_MAIN = wxID_HIGHEST + 1,
        MENU_NEW,
        MENU_OPEN,
        MENU_CLOSE,
        MENU_SAVE,
        MENU_SAVEAS,
        MENU_QUIT
    };

DECLARE_APP(MainApp)

}

#endif