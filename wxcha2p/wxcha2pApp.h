/***************************************************************
 * Name:      wxcha2pApp.h
 * Purpose:   Defines Application Class
 * Author:     ()
 * Created:   2009-03-19
 * Copyright:  ()
 * License:
 **************************************************************/

#ifndef WXCHA2PAPP_H
#define WXCHA2PAPP_H

#include <wx/app.h>

#include "wxcha2pMain.h"
#include "socketServer.h"
#include "MessageEvent.h"

class wxcha2pApp : public wxApp
{
    public:
        virtual bool OnInit();

    private:
        SocketServer* server;
        void OnMessageEvent(MessageEvent& event);

        wxcha2pFrame* Frame;

        DECLARE_EVENT_TABLE();
};

#endif // WXCHA2PAPP_H
