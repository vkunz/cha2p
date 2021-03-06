/*
 * Diese Klasse implementiert die grundlegenden Funktionen f�r einen Client-Socket,
 * wie den Aufbau einer Verbindung, das Versenden von Nachrichten, den Verbindungsabbau
 */

#include "socketClient.h"
#include "MessageEvent.h"

#include <iostream>
#include <wx/string.h>

#if defined(__WXLINUX__)

#include <netinet/in.h>

#endif

const long SocketClient::SOCKET_ID = wxNewId();

BEGIN_EVENT_TABLE(SocketClient,wxEvtHandler)
    EVT_SOCKET(SOCKET_ID, SocketClient::OnSocketEvent)
END_EVENT_TABLE()

/*
 * Constructor
 * Socket registrieren und notwendige Initialisierungen durchf�hren
 */
SocketClient::SocketClient() {
    // Create the socket
    m_sock = new wxSocketClient();

    // set timeout
    m_sock->SetTimeout(10);

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
bool SocketClient::OpenConnection(wxString hostname, int port) {
  wxIPV4address addr;
  addr.Hostname(hostname);
  addr.Service(port);

  m_sock->Connect(addr, false);

  // wait for connect or timeout
  m_sock->WaitOnConnect(5, 0);

  if (! m_sock->IsConnected()) {
    m_sock->Close();
    return false;
  }

  return true;
}

/*
 * Sendet eine �bergegebene Nachricht zum Server
 * Momentan werden hier auch noch Protokoll-Aufgaben mit �bernommen
 */
void SocketClient::SendMessage(SocketData* output) {
    while(!m_sock->WaitForWrite(0, 200)) {}

    m_sock->SetFlags(wxSOCKET_WAITALL);

    // send communication protocoll
    m_sock->Write(output->getComProtocol(), 1);

    // send message-length
    unsigned int len = output->getNumBytes();
    len = htonl(len);
    m_sock->Write(&len, 4);

    char* buf = new char[output->getNumBytes()];
    strcpy(buf, (const char*)output->getMessage().mb_str(wxConvUTF8));

    // send message
    m_sock->Write(buf, output->getNumBytes());

    delete[] buf;
    delete output;
}

/*
 * Schliesst die Verbindung
 */
void SocketClient::CloseConnection() {
    m_sock->Close();
}
