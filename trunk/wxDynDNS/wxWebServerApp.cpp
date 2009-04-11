/***************************************************************
 * Name:      wxWebServerApp.cpp
 * Purpose:   Code for Application Class
 * Author:     ()
 * Created:   2009-03-26
 * Copyright:  ()
 * License:
 **************************************************************/

#ifdef WX_PRECOMP
#include "wx_pch.h"
#define _WIN32_WINNT 0x0501
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#include "wxWebServerApp.h"
#include "wxWebServerMain.h"
#include "tcpsocket.h"
#include "Thread.h"

#include <iostream>
using namespace std;

IMPLEMENT_APP(wxWebServerApp);

bool wxWebServerApp::OnInit()
{
    tcpSocket mytcpserver;
    tcpSocket* mycc;

    mytcpserver.openserver(80, 5);

    while (true)
    {
        cout << "\n\nWaiting for incoming requests on port " << 80 <<endl;
        mycc = mytcpserver.acceptclient();

        ServerThread* t = new ServerThread(mycc);
        t->Create();
        t->Run();

    } // while true

    /*wxWebServerFrame* frame = new wxWebServerFrame(0L, _("wxWidgets Application Template"));
    frame->SetIcon(wxICON(aaaa)); // To Set App Icon
    frame->Show();*/

    return true;
}
