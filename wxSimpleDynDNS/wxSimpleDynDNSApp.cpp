/***************************************************************
 * Name:      wxDynDNSApp.cpp
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

#include "wxSimpleDynDNSApp.h"
#include "wxSimpleDynDNSMain.h"
#include "tcpsocket.h"
#include "Thread.h"

#define TCP_PORT 3001

#include <iostream>
#include <string>
using namespace std;

IMPLEMENT_APP(wxSimpleDynDNSApp);

bool wxSimpleDynDNSApp::OnInit()
{
    tcpSocket mytcpserver;
    tcpSocket* mycc;

    string* entry = new string[2];

    mytcpserver.openserver(TCP_PORT, 5);

    while (true)
    {
        cout << "\nDynDNS is listening on port " << TCP_PORT << endl;
        mycc = mytcpserver.acceptclient();

        ServerThread* t = new ServerThread(mycc,entry);
        t->Create();
        t->Run();
    }

    return true;
}
