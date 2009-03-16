/***************************************************************
 * Name:      SocketApp.cpp
 * Purpose:   Code for Application Class
 * Author:     ()
 * Created:   2009-03-12
 * Copyright:  ()
 * License:
 **************************************************************/

#include "SocketApp.h"

//(*AppHeaders
#include "SocketMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(SocketApp);

bool SocketApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	SocketFrame* Frame = new SocketFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
