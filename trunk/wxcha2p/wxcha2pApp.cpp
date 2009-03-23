/***************************************************************
 * Name:      wxcha2pApp.cpp
 * Purpose:   Code for Application Class
 * Author:     ()
 * Created:   2009-03-19
 * Copyright:  ()
 * License:
 **************************************************************/

#include "wxcha2pApp.h"

#include "Sender.h"

//(*AppHeaders
#include <wx/image.h>
//*)

BEGIN_EVENT_TABLE(wxcha2pApp, wxApp)
	EVT_MESSAGE(0, wxcha2pApp::OnMessageEvent)
END_EVENT_TABLE()

IMPLEMENT_APP(wxcha2pApp);

bool wxcha2pApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	Frame = new wxcha2pFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    	wxSocketBase::Initialize(); //needed to get sockets in other threads working
    }
    //*)

    // Server-Socket erstellen
    server = new SocketServer(3000);

    return wxsOK;
}

/*
 * Reagiert auf MessageEvent-Events und leitet die Verarbeitung ein
 */
void wxcha2pApp::OnMessageEvent(MessageEvent& event) {
    switch(event.getMessageType()) {
        case RECEIVE:
            Frame->addMessage(event.getMessage());
            break;
        case SENDMSG:
            if(event.getMessage() != wxT("")) {
                Sender snd;
                snd.SendMessage(wxT("localhost"), 3000, event.getMessage());
            }
            break;
    }
}
