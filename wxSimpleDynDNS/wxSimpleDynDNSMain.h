/***************************************************************
 * Name:      wxDynDNSMain.h
 * Purpose:   Defines Application Frame
 * Author:     ()
 * Created:   2009-03-26
 * Copyright:  ()
 * License:
 **************************************************************/

#ifndef WXSSIMPLEDYNDNSFRAME_H
#define WXSSIMPLEDYNDNSFRAME_H

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include "wxSimpleDynDNSApp.h"

class wxSimpleDynDNSFrame: public wxFrame
{
    public:
        wxSimpleDynDNSFrame(wxFrame *frame, const wxString& title);
        ~wxSimpleDynDNSFrame();
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


#endif // WXSSIMPLEDYNDNSFRAME_H
