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
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/statusbr.h>
//*)

class wxcha2pFrame: public wxFrame
{
    public:

        wxcha2pFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~wxcha2pFrame();

        void addMessage(wxString message);

    private:

        //(*Handlers(wxcha2pFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnButton_SendClick(wxCommandEvent& event);
        void OnListBox1Select(wxCommandEvent& event);
        //*)
        void OnConnect(wxCommandEvent& event);

        //(*Identifiers(wxcha2pFrame)
        static const long ID_TEXTCTRL1;
        static const long ID_TEXTCTRL2;
        static const long ID_BUTTON1;
        static const long idMenuConnect;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(wxcha2pFrame)
        wxButton* Button_Send;
        wxTextCtrl* m_text_output;
        wxMenuItem* MenuItem3;
        wxStatusBar* StatusBar1;
        wxTextCtrl* m_text_input;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // WXCHA2PMAIN_H
