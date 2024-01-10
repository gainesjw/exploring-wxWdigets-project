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
    };

DECLARE_APP(MainApp)

}

#endif