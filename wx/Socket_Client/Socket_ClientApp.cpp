/***************************************************************
 * Name:      Socket_ClientApp.cpp
 * Purpose:   Code for Application Class
 * Author:     ()
 * Created:   2009-03-12
 * Copyright:  ()
 * License:
 **************************************************************/

#include "Socket_ClientApp.h"

//(*AppHeaders
#include "Socket_ClientMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(Socket_ClientApp);

bool Socket_ClientApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	Socket_ClientFrame* Frame = new Socket_ClientFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
