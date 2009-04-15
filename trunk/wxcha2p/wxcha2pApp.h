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

#include "Configuration.h"
#include "EvaluateInput.h"
#include "GenerateOutput.h"
#include "GUIEvent.h"
#include "MessageEvent.h"
#include "socketServer.h"
#include "wxcha2pMain.h"

class wxcha2pApp : public wxApp
{
    public:
        virtual bool OnInit();

    private:
        void OnMessageEvent(MessageEvent& event);
        void OnGUIEvent(GUIEvent& event);

        void connect();

        wxcha2pFrame* Frame;
        Configuration* m_config;
        SocketServer* m_server;
        GenerateOutput* m_genOutput;
        EvaluateInput* m_evalInput;


        DECLARE_EVENT_TABLE();
};

//DECLARE_APP(wxcha2pApp)

#endif // WXCHA2PAPP_H
