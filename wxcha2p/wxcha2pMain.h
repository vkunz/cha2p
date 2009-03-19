/***************************************************************
 * Name:      wxcha2pMain.h
 * Purpose:   Defines Application Frame
 * Author:     ()
 * Created:   2009-03-19
 * Copyright:  ()
 * License:
 **************************************************************/

#ifndef WXCHA2PMAIN_H
#define WXCHA2PMAIN_H

//(*Headers(wxcha2pFrame)
#include <wx/menu.h>
#include <wx/textctrl.h>
#include <wx/frame.h>
#include <wx/statusbr.h>
//*)

class wxcha2pFrame: public wxFrame
{
    public:

        wxcha2pFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~wxcha2pFrame();

    private:

        //(*Handlers(wxcha2pFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        //*)

        //(*Identifiers(wxcha2pFrame)
        static const long ID_TEXTCTRL1;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(wxcha2pFrame)
        wxTextCtrl* m_text;
        wxStatusBar* StatusBar1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // WXCHA2PMAIN_H
