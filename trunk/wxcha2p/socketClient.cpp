/*
 * Diese Klasse implementiert die grundlegenden Funktionen für einen Client-Socket,
 * wie den Aufbau einer Verbindung, das Versenden von Nachrichten, den Verbindungsabbau
 */

#include "socketClient.h"
#include "MessageEvent.h"

#include <wx/string.h>

const long SocketClient::SOCKET_ID = wxNewId();

BEGIN_EVENT_TABLE(SocketClient,wxEvtHandler)
    EVT_SOCKET(SOCKET_ID, SocketClient::OnSocketEvent)
END_EVENT_TABLE()

/*
 * Constructor
 * Socket registrieren und notwendige Initialisierungen durchführen
 */
SocketClient::SocketClient() {
    // Create the socket
    m_sock = new wxSocketClient();

    // set timeout
    m_sock->SetTimeout(20);

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
 * Verarbeitet Events, die vom Socket ausgelöst wurden.
 * Gegebenenfalls kann auf diese Fälle gesondert eingegangen werden
 */
void SocketClient::OnSocketEvent(wxSocketEvent& event) {
    switch(event.GetSocketEvent()) {
        case wxSOCKET_INPUT:
            //s.Append(wxT("wxSOCKET_INPUT\n"));
            break;
        case wxSOCKET_LOST:
            //s.Append(wxT("wxSOCKET_LOST\n"));
            break;
        case wxSOCKET_CONNECTION:
            //s.Append(wxT("wxSOCKET_CONNECTION\n"));
            break;
        default:
            //s.Append(wxT("Unexpected event !\n"));
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
 * Sendet eine übergegebene Nachricht zum Server
 * Momentan werden hier auch noch Protokoll-Aufgaben mit übernommen
 */
void SocketClient::SendMessage(SocketData* output) {
    // send communication protocoll
    m_sock->Write(output->getComProtocol(), 1);
    // send message-length
    m_sock->Write(output->getNumBytes(), sizeof(int));
    // send message
    m_sock->Write(output->getMessage().mb_str(), *output->getNumBytes());

    delete output;
}

/*
 * Schliesst die Verbindung
 */
void SocketClient::CloseConnection() {
    m_sock->Close();
}
