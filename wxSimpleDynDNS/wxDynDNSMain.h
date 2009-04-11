/***************************************************************
 * Name:      wxDynDNSMain.h
 * Purpose:   Defines Application Frame
 * Author:     ()
 * Created:   2009-03-26
 * Copyright:  ()
 * License:
 **************************************************************/

#ifndef WXWEBSERVERMAIN_H
#define WXWEBSERVERMAIN_H

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include "wxDynDNSApp.h"

class wxDynDNSFrame: public wxFrame
{
    public:
        wxDynDNSFrame(wxFrame *frame, const wxString& title);
        ~wxDynDNSFrame();
    private:
        enum
        {
            idMenuQuit = 1000,
            idMenuAbout
        };
        void OnClose(wxCloseEvent& event);
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        DECLARE_EVENT_TABLE()
};


#endif // WXWEBSERVERMAIN_H
