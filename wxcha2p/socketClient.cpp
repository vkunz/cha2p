/*
 * Diese Klasse implementiert die grundlegenden Funktionen f�r einen Client-Socket,
 * wie den Aufbau einer Verbindung, das Versenden von Nachrichten, den Verbindungsabbau
 */

#include "socketClient.h"

#include <wx/string.h>

BEGIN_EVENT_TABLE(SocketClient,wxEvtHandler)
    EVT_SOCKET(SOCKET_ID, SocketClient::OnSocketEvent)
END_EVENT_TABLE()

const long SocketClient::SOCKET_ID = wxNewId();

/*
 * Constructor
 * Socket registrieren und notwendige Initialisierungen durchf�hren
 */
SocketClient::SocketClient() {
    // Create the socket
    m_sock = new wxSocketClient();
    // Setup the event handler and subscribe to most events
    m_sock->SetEventHandler(*this, SOCKET_ID);
    m_sock->SetNotify(wxSOCKET_CONNECTION_FLAG | wxSOCKET_INPUT_FLAG | wxSOCKET_LOST_FLAG);
    m_sock->Notify(true);
}

/*
 * Destructor
 */
SocketClient::~SocketClient() {
    delete m_sock;
}

/*
 * Verarbeitet Events, die vom Socket ausgel�st wurden.
 * Gegebenenfalls kann auf diese F�lle gesondert eingegangen werden
 */
void SocketClient::OnSocketEvent(wxSocketEvent& event) {
    wxString s = wxT("OnSocketEvent: ");

    switch(event.GetSocketEvent()) {
        case wxSOCKET_INPUT:
            s.Append(wxT("wxSOCKET_INPUT\n"));
            break;
        case wxSOCKET_LOST:
            s.Append(wxT("wxSOCKET_LOST\n"));
            break;
        case wxSOCKET_CONNECTION:
            s.Append(wxT("wxSOCKET_CONNECTION\n"));
            break;
        default:
            s.Append(wxT("Unexpected event !\n"));
            break;
    }
}

/*
 * Baut eine Verbindung zum angegebenen Host auf
 */
void SocketClient::OpenConnection(wxString hostname, int port) {
  wxIPV4address addr;

  addr.Hostname(hostname);
  addr.Service(port);

  m_sock->Connect(addr, false);

  while ( !m_sock->WaitOnConnect(0, 200) ) {}

  if (! m_sock->IsConnected()) {
    m_sock->Close();
  }
}

/*
 * Sendet eine �bergegebene Nachricht zum Server
 * Momentan werden hier auch noch Protokoll-Aufgaben mit �bernommen
 */
void SocketClient::SendMessage(const wxChar* message) {
    unsigned char len = (unsigned char)((wxStrlen(message) + 1) * sizeof(wxChar));

    // Communication Protocoll
    unsigned char c = 0xBE;
    m_sock->Write(&c, 1);

    m_sock->Write(&len, 1);
    m_sock->Write(message, len);
}

/*
 * Schliesst die Verbindung
 */
void SocketClient::CloseConnection() {
    m_sock->Close();
}