/***************************************************************
 * Name:      SocketMain.h
 * Purpose:   Defines Application Frame
 * Author:     ()
 * Created:   2009-03-12
 * Copyright:  ()
 * License:
 **************************************************************/

#ifndef SOCKETMAIN_H
#define SOCKETMAIN_H

//(*Headers(SocketFrame)
#include <wx/menu.h>
#include <wx/frame.h>
#include <wx/statusbr.h>
//*)

// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

#ifdef __BORLANDC__
#  pragma hdrstop
#endif

// for all others, include the necessary headers
#ifndef WX_PRECOMP
#  include "wx/wx.h"
#endif

#include "wx/socket.h"

class SocketFrame: public wxFrame
{
    public:
        SocketFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~SocketFrame();

    private:
        //(*Handlers(SocketFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnServerEvent(wxSocketEvent& event);
        void OnSocketEvent(wxSocketEvent& event);
        //*)

        void initServer();
        void TestConnection(wxSocketBase *sock);
        void UpdateStatusBar();

        //(*Identifiers(SocketFrame)
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(SocketFrame)
        wxStatusBar* StatusBar1;
        //*)

        wxSocketServer *m_server;
        wxMenu         *m_menuFile;
        wxMenuBar      *m_menuBar;
        bool            m_busy;
        int             m_numClients;

        DECLARE_EVENT_TABLE()
};

#endif // SOCKETMAIN_H
