/***************************************************************
 * Name:      wxcha2pMain.cpp
 * Purpose:   Code for Application Frame
 * Author:     ()
 * Created:   2009-03-19
 * Copyright:  ()
 * License:
 **************************************************************/

#include "wxcha2pMain.h"
#include <wx/msgdlg.h>
#include "MessageEvent.h"
#include "GUIEvent.h"

//(*InternalHeaders(wxcha2pFrame)
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

//(*IdInit(wxcha2pFrame)
const long wxcha2pFrame::ID_TEXTCTRL1 = wxNewId();
const long wxcha2pFrame::ID_TEXTCTRL2 = wxNewId();
const long wxcha2pFrame::ID_BUTTON1 = wxNewId();
const long wxcha2pFrame::idMenuConnect = wxNewId();
const long wxcha2pFrame::idMenuQuit = wxNewId();
const long wxcha2pFrame::idMenuAbout = wxNewId();
const long wxcha2pFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(wxcha2pFrame,wxFrame)
    //(*EventTable(wxcha2pFrame)
    //*)
END_EVENT_TABLE()

wxcha2pFrame::wxcha2pFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(wxcha2pFrame)
    wxMenuItem* MenuItem2;
    wxMenuItem* MenuItem1;
    wxMenu* Menu1;
    wxMenuItem* MenuItem3;
    wxMenuBar* MenuBar1;
    wxMenu* Menu2;

    Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    SetClientSize(wxSize(400,490));
    m_text_output = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxPoint(0,0), wxSize(400,320), wxTE_MULTILINE|wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    m_text_input = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxPoint(0,336), wxSize(352,112), 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    Button_Send = new wxButton(this, ID_BUTTON1, _("Send"), wxPoint(352,336), wxSize(48,112), 0, wxDefaultValidator, _T("ID_BUTTON1"));
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem3 = new wxMenuItem(Menu1, idMenuConnect, _("Connect"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(MenuItem3);
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

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&wxcha2pFrame::OnButton_SendClick);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&wxcha2pFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&wxcha2pFrame::OnAbout);
    //*)
    Connect(idMenuConnect,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&wxcha2pFrame::OnConnect);
}

wxcha2pFrame::~wxcha2pFrame()
{
    //(*Destroy(wxcha2pFrame)
    //*)
}

void wxcha2pFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void wxcha2pFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

/*
 * Fügt eine übergebene Nachricht dem Output-Control hinzu
 */
void wxcha2pFrame::addMessage(wxString message) {
    m_text_output->AppendText(message + wxT("\n"));
}

/*
 * Handled einen Klick auf den Senden Button
 */
void wxcha2pFrame::OnButton_SendClick(wxCommandEvent& event) {
    //Nachrict versenden
    MessageEvent myevent(wxEVT_COMMAND_MESSAGE);
	myevent.setMessageType(SENDMSG);
	myevent.setMessage(m_text_input->GetValue());
	myevent.SetEventObject(this);
	GetEventHandler()->ProcessEvent(myevent);

	m_text_input->Clear();
}

/*
 * Handled einen Klick auf den Menu-Punkt Connect
 */
void wxcha2pFrame::OnConnect(wxCommandEvent& event) {
    // Event senden
    GUIEvent myevent(wxEVT_COMMAND_GUIEvent);
    myevent.setEventType(CONNECT);
    myevent.SetEventObject(this);
    GetEventHandler()->ProcessEvent(myevent);
}
