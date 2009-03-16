/***************************************************************
 * Name:      Socket_ClientMain.cpp
 * Purpose:   Code for Application Frame
 * Author:     ()
 * Created:   2009-03-12
 * Copyright:  ()
 * License:
 **************************************************************/

#include "Socket_ClientMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(Socket_ClientFrame)
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

enum {
    SOCKET_ID
};

//(*IdInit(Socket_ClientFrame)
const long Socket_ClientFrame::ID_BUTTON1 = wxNewId();
const long Socket_ClientFrame::idMenuQuit = wxNewId();
const long Socket_ClientFrame::idMenuAbout = wxNewId();
const long Socket_ClientFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(Socket_ClientFrame,wxFrame)
    //(*EventTable(Socket_ClientFrame)
    //*)
END_EVENT_TABLE()

Socket_ClientFrame::Socket_ClientFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(Socket_ClientFrame)
    wxMenuItem* MenuItem2;
    wxMenuItem* MenuItem1;
    wxMenu* Menu1;
    wxMenuBar* MenuBar1;
    wxMenu* Menu2;

    Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    Button1 = new wxButton(this, ID_BUTTON1, _("Connect"), wxPoint(20,20), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
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

    initSocket();

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Socket_ClientFrame::OnButton1Click);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&Socket_ClientFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&Socket_ClientFrame::OnAbout);
    //*)
}

Socket_ClientFrame::~Socket_ClientFrame()
{
    //(*Destroy(Socket_ClientFrame)
    //*)
}

void Socket_ClientFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void Socket_ClientFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void Socket_ClientFrame::OnOpenConnection(wxCommandEvent& event) {
  wxIPV4address addr;

  // Ask user for server address
  wxString hostname = wxGetTextFromUser(
    _("Enter the address of the wxSocket demo server:"),
    _("Connect ..."),
    _("localhost"));

  addr.Hostname(hostname);
  addr.Service(3000);

  // Mini-tutorial for Connect() :-)
  // ---------------------------
  //
  // There are two ways to use Connect(): blocking and non-blocking,
  // depending on the value passed as the 'wait' (2nd) parameter.
  //
  // Connect(addr, true) will wait until the connection completes,
  // returning true on success and false on failure. This call blocks
  // the GUI (this might be changed in future releases to honour the
  // wxSOCKET_BLOCK flag).
  //
  // Connect(addr, false) will issue a nonblocking connection request
  // and return immediately. If the return value is true, then the
  // connection has been already successfully established. If it is
  // false, you must wait for the request to complete, either with
  // WaitOnConnect() or by watching wxSOCKET_CONNECTION / LOST
  // events (please read the documentation).
  //
  // WaitOnConnect() itself never blocks the GUI (this might change
  // in the future to honour the wxSOCKET_BLOCK flag). This call will
  // return false on timeout, or true if the connection request
  // completes, which in turn might mean:
  //
  //   a) That the connection was successfully established
  //   b) That the connection request failed (for example, because
  //      it was refused by the peer.
  //
  // Use IsConnected() to distinguish between these two.
  //
  // So, in a brief, you should do one of the following things:
  //
  // For blocking Connect:
  //
  //   bool success = client->Connect(addr, true);
  //
  // For nonblocking Connect:
  //
  //   client->Connect(addr, false);
  //
  //   bool waitmore = true;
  //   while (! client->WaitOnConnect(seconds, millis) && waitmore )
  //   {
  //     // possibly give some feedback to the user,
  //     // update waitmore if needed.
  //   }
  //   bool success = client->IsConnected();
  //
  // And that's all :-)

  m_sock->Connect(addr, false);
  m_sock->WaitOnConnect(10);

  if (! m_sock->IsConnected())
  {
    m_sock->Close();
    wxMessageBox(_("Can't connect to the specified host"), _("Alert !"));
  }

}

void Socket_ClientFrame::OnTest(wxCommandEvent& event) {

}

void Socket_ClientFrame::OnSocketEvent(wxSocketEvent& event) {

}

void Socket_ClientFrame::initSocket() {
    // Create the socket
  m_sock = new wxSocketClient();

  // Setup the event handler and subscribe to most events
  m_sock->SetEventHandler(*this, SOCKET_ID);
  m_sock->SetNotify(wxSOCKET_CONNECTION_FLAG |
                    wxSOCKET_INPUT_FLAG |
                    wxSOCKET_LOST_FLAG);
  m_sock->Notify(true);

  m_busy = false;
}

void Socket_ClientFrame::OnButton1Click(wxCommandEvent& event)
{
    OnOpenConnection(event);
}

