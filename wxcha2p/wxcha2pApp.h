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

#include "socketServer.h"

class wxcha2pApp : public wxApp
{
    public:
        virtual bool OnInit();

    private:
        SocketServer* server;
};

#endif // WXCHA2PAPP_H
