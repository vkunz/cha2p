/***************************************************************
 * Name:      wxcha2pApp.cpp
 * Purpose:   Code for Application Class
 * Author:     ()
 * Created:   2009-03-19
 * Copyright:  ()
 * License:
 **************************************************************/

#include "wxcha2pApp.h"

#include "ConnectDialog.h"

//(*AppHeaders
#include <wx/image.h>
//*)

BEGIN_EVENT_TABLE(wxcha2pApp, wxApp)
	EVT_MESSAGE(0, wxcha2pApp::OnMessageEvent)
	EVT_GUI(0, wxcha2pApp::OnGUIEvent)
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
    }
    //*)

    wxSocketBase::Initialize(); //needed to get sockets in other threads working

    // Server-Socket erstellen
    m_server = SocketServer::getInstance(3000);

    m_genOutput = GenerateOutput::getInstance();
    m_evalInput = new EvaluateInput;

    return wxsOK;
}

/*
 * Reagiert auf MessageEvent-Events und leitet die Verarbeitung ein
 */
void wxcha2pApp::OnMessageEvent(MessageEvent& event) {
    switch(event.getMessageType()) {
        case RECEIVE: {
            m_evalInput->evaluate(event);
            break;
        }
        case SENDMSG:
            if(event.getMessage() != wxT("")) {
                m_genOutput->SendChannelMessage(event.getMessage());
            }
            break;
    }
}

void wxcha2pApp::OnGUIEvent(GUIEvent& event) {
    switch(event.getEventType()) {
        case DISPLAYMESSAGE:
            Frame->addMessage(event.getText());
            break;
        case CONNECT:
            // ask for server-ip
            ConnectDialog dialog(0);
            dialog.ShowModal();

            m_genOutput->requestContacts(dialog.getAddress(), 3000);
            break;
    }
}
