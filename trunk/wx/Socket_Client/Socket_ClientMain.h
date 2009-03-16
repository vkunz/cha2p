/***************************************************************
 * Name:      Socket_ClientMain.h
 * Purpose:   Defines Application Frame
 * Author:     ()
 * Created:   2009-03-12
 * Copyright:  ()
 * License:
 **************************************************************/

#ifndef SOCKET_CLIENTMAIN_H
#define SOCKET_CLIENTMAIN_H

//(*Headers(Socket_ClientFrame)
#include <wx/menu.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/statusbr.h>
//*)
#include "wx/wx.h"
#include "wx/socket.h"
#include "wx/url.h"
#include "wx/wfstream.h"

class Socket_ClientFrame: public wxFrame
{
    public:

        Socket_ClientFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~Socket_ClientFrame();

    private:

        //(*Handlers(Socket_ClientFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnButton1Click(wxCommandEvent& event);
        //*)
        void OnOpenConnection(wxCommandEvent& event);
        void OnTest(wxCommandEvent& event);
        // socket event handler
        void OnSocketEvent(wxSocketEvent& event);

        void initSocket();

        //(*Identifiers(Socket_ClientFrame)
        static const long ID_BUTTON1;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(Socket_ClientFrame)
        wxButton* Button1;
        wxStatusBar* StatusBar1;
        //*)

        wxSocketClient *m_sock;
        bool            m_busy;

        DECLARE_EVENT_TABLE()
};

#endif // SOCKET_CLIENTMAIN_H
