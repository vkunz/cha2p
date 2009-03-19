/***************************************************************
 * Name:      wxcha2pApp.cpp
 * Purpose:   Code for Application Class
 * Author:     ()
 * Created:   2009-03-19
 * Copyright:  ()
 * License:
 **************************************************************/

#include "wxcha2pApp.h"

//(*AppHeaders
#include "wxcha2pMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(wxcha2pApp);

bool wxcha2pApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	wxcha2pFrame* Frame = new wxcha2pFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)

    server = new SocketServer(3000);

    return wxsOK;

}
