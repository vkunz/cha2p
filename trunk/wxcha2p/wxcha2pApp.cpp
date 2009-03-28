/***************************************************************
 * Name:      wxcha2pApp.cpp
 * Purpose:   Code for Application Class
 * Author:     ()
 * Created:   2009-03-19
 * Copyright:  ()
 * License:
 **************************************************************/

#include "wxcha2pApp.h"

#include <iostream>

#include "Sender.h"
#include "GenerateOutput.h"
#include "EvaluateInput.h"
#include "SocketData.h"
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
    	wxSocketBase::Initialize(); //needed to get sockets in other threads working
    }
    //*)

    // Server-Socket erstellen
    server = SocketServer::getInstance(3000);

    return wxsOK;
}

/*
 * Reagiert auf MessageEvent-Events und leitet die Verarbeitung ein
 */
void wxcha2pApp::OnMessageEvent(MessageEvent& event) {
    switch(event.getMessageType()) {
        case RECEIVE: {
            EvaluateInput input;
            input.evaluate(event.getSocketData());
            break;
        }
        case SENDMSG:
            if(event.getMessage() != wxT("")) {
                GenerateOutput output;
                Sender snd;
                snd.SendMessage(wxT("localhost"), 3000, output.SendChannelMessage(event.getMessage()));
            }
            break;
    }
}

#include <wx/msgdlg.h>

void wxcha2pApp::OnGUIEvent(GUIEvent& event) {
    switch(event.getEventType()) {
        case DISPLAYMESSAGE:
            Frame->addMessage(event.getText());
            break;
        case CONNECT:
            ConnectDialog dialog(0);
            GenerateOutput output;
            Sender snd;

            dialog.ShowModal();
            snd.SendMessage(dialog.getAddress(), 3000, output.requestContacts());
            break;
    }
}
