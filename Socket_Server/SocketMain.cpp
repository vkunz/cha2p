/***************************************************************
 * Name:      SocketMain.cpp
 * Purpose:   Code for Application Frame
 * Author:     ()
 * Created:   2009-03-12
 * Copyright:  ()
 * License:
 **************************************************************/

#include "SocketMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(SocketFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(SocketFrame)
const long SocketFrame::idMenuQuit = wxNewId();
const long SocketFrame::idMenuAbout = wxNewId();
const long SocketFrame::ID_STATUSBAR1 = wxNewId();
//*)

// IDs for the controls and the menu commands
enum
{
  // id for sockets
  SERVER_ID = 100,
  SOCKET_ID
};

BEGIN_EVENT_TABLE(SocketFrame,wxFrame)
    //EVT_MENU(SERVER_QUIT,  MyFrame::OnQuit)
    //EVT_MENU(SERVER_ABOUT, MyFrame::OnAbout)
    EVT_SOCKET(SERVER_ID, SocketFrame::OnServerEvent)
    EVT_SOCKET(SOCKET_ID, SocketFrame::OnSocketEvent)
END_EVENT_TABLE()

SocketFrame::SocketFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(SocketFrame)
    wxMenuItem* MenuItem2;
    wxMenuItem* MenuItem1;
    wxMenu* Menu1;
    wxMenuBar* MenuBar1;
    wxMenu* Menu2;

    Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);

    initServer();

    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&SocketFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&SocketFrame::OnAbout);
    //*)
}

SocketFrame::~SocketFrame()
{
    //(*Destroy(SocketFrame)
    //*)
}

void SocketFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void SocketFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void SocketFrame::initServer() {
    // Create the address - defaults to localhost:0 initially
    wxIPV4address addr;
    addr.Service(3000);

    // Create the socket
    m_server = new wxSocketServer(addr);

    // We use Ok() here to see if the server is really listening
    if (! m_server->Ok())
    {
        return;
    }

    // Setup the event handler and subscribe to connection events
    m_server->SetEventHandler(*this, SERVER_ID);
    m_server->SetNotify(wxSOCKET_CONNECTION_FLAG);
    m_server->Notify(true);

    m_busy = false;
    m_numClients = 0;
    UpdateStatusBar();
}

void SocketFrame::TestConnection(wxSocketBase *sock) {
    unsigned char len;
    char *buf;

    // Receive data from socket and send it back. We will first
    // get a byte with the buffer size, so we can specify the
    // exact size and use the wxSOCKET_WAITALL flag. Also, we
    // disabled input events so we won't have unwanted reentrance.
    // This way we can avoid the infamous wxSOCKET_BLOCK flag.

    sock->SetFlags(wxSOCKET_WAITALL);

    // Read the size
    sock->Read(&len, 1);
    buf = new char[len];

    // Read the data
    sock->Read(buf, len);

    // Write it back
//    sock->Write(buf, len);
//    delete[] buf;
}

void SocketFrame::OnServerEvent(wxSocketEvent& event) {
    wxSocketBase *sock;
    sock = m_server->Accept(false);

    sock->SetEventHandler(*this, SOCKET_ID);
    sock->SetNotify(wxSOCKET_INPUT_FLAG | wxSOCKET_LOST_FLAG);
    sock->Notify(true);

    m_numClients++;
    UpdateStatusBar();
}

void SocketFrame::OnSocketEvent(wxSocketEvent& event) {
    wxSocketBase *sock = event.GetSocket();
    // Now we process the event
    switch(event.GetSocketEvent())
    {
        case wxSOCKET_INPUT:
        {
            // We disable input events, so that the test doesn't trigger
            // wxSocketEvent again.
            sock->SetNotify(wxSOCKET_LOST_FLAG);

            // Which test are we going to run?
            unsigned char c;
            sock->Read(&c, 1);

            switch (c)
            {
                case 0xBE: TestConnection(sock); break;
                case 0xCE: TestConnection(sock); break;
                case 0xDE: TestConnection(sock); break;
            }

            // Enable input events again.
            sock->SetNotify(wxSOCKET_LOST_FLAG | wxSOCKET_INPUT_FLAG);
            break;
        }
        case wxSOCKET_LOST:
        {
            m_numClients--;

            // Destroy() should be used instead of delete wherever possible,
            // due to the fact that wxSocket uses 'delayed events' (see the
            // documentation for wxPostEvent) and we don't want an event to
            // arrive to the event handler (the frame, here) after the socket
            // has been deleted. Also, we might be doing some other thing with
            // the socket at the same time; for example, we might be in the
            // middle of a test or something. Destroy() takes care of all
            // this for us.

            sock->Destroy();
            break;
        }
        default: ;
    }

    UpdateStatusBar();
}

void SocketFrame::UpdateStatusBar() {
    wxString s;
    s.Printf(_("%d clients connected"), m_numClients);
    SetStatusText(s, 0);
}
