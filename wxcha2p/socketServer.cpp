/*
 * Stellt Grundfunktionen zum Erstellen eines Server-Sockets zur Verfügung.
 * Ist als Singleton-Klasse realisiert, da nie mehr als ein Server benötigt wird.
 */

#include "socketServer.h"

#include "MessageEvent.h"
#include "SocketData.h"
#include "enum.h"

#if defined(__WXLINUX__)

#include <netinet/in.h>

#endif

SocketServer* SocketServer::pinstance = 0;
const long SocketServer::SERVER_ID = wxNewId();
const long SocketServer::SOCKET_ID = wxNewId();

BEGIN_EVENT_TABLE(SocketServer,wxEvtHandler)
    EVT_SOCKET(SERVER_ID, SocketServer::OnServerEvent)
    EVT_SOCKET(SOCKET_ID, SocketServer::OnSocketEvent)
END_EVENT_TABLE()

/*
 * protected Constructor für Singleton-Klasse
 * Erstellt den Socket, bindet ihn an einen Port und führt zusätzliche Initialisierungen durch
 */
SocketServer::SocketServer(int port) {
    // Create the address - defaults to localhost:0 initially
    wxIPV4address addr;
    addr.Service(port);

    // Create the socket
    m_server = new wxSocketServer(addr);

    // We use Ok() here to see if the server is really listening
    if (! m_server->Ok()) {
        return;
    }

    // Setup the event handler and subscribe to connection events
    m_server->SetEventHandler(*this, SERVER_ID);
    m_server->SetNotify(wxSOCKET_CONNECTION_FLAG);
    m_server->Notify(true);
}

/*
 * Wird zur Erstellung der Singleton-Klasse genutzt. Erstellt eine neue Instanz, wenn noch
 * keine vorhanden ist oder liefert einen Pointer auf eine vorhandene Instanz zurück
 */
SocketServer* SocketServer::getInstance(int port) {
    if (pinstance == 0) {
		pinstance = new SocketServer(port);
	}
	return pinstance;
}

/*
 * Destructor
 */
SocketServer::~SocketServer() {
    delete m_server;
}

/*
 * Reagiert auf Events am Socket. Dies geschieht bei eingehenden Verbindungen. Diese wird
 * akzeptiert und es werden weitere Handler angegeben, die auf diesen speziellen Socket hören
 */
void SocketServer::OnServerEvent(wxSocketEvent& event) {
    wxSocketBase *sock;
    sock = m_server->Accept(false);

    sock->SetEventHandler(*this, SOCKET_ID);
    sock->SetNotify(wxSOCKET_INPUT_FLAG | wxSOCKET_LOST_FLAG);
    sock->Notify(true);
}
#include <iostream>
/*
 * Reagiert auf Events, die an einem bereits verbundenen Socket entstehen. Hierzu
 * zählen das Empfangen einer Nachricht, ein Verbindungsabbruch, ...
 */
void SocketServer::OnSocketEvent(wxSocketEvent& event) {
    wxSocketBase* sock = event.GetSocket();
    // Now we process the event
    switch(event.GetSocketEvent())
    {
        case wxSOCKET_INPUT:
        {
            // We disable input events, so that it doesn't trigger
            // wxSocketEvent again.
            sock->SetNotify(wxSOCKET_LOST_FLAG);
            sock->SetFlags(wxSOCKET_WAITALL);

            SocketData* data = new SocketData;

            // read protocoll byte
            sock->Read(data->getComProtocol(), 1);

            // read the size
            unsigned int len;
            sock->Read(&len, 4);
            len = ntohl(len);

            std::cout << sock->LastCount() << std::endl;

            // Read the data
            char* buf = new char[len];
            sock->Read(buf, len);
            data->setMessage(wxString::From8BitData(buf));

            // get client ip
            wxIPV4address addr;
            sock->GetPeer(addr);
            wxString ip = addr.IPAddress();

            std::cout << "----------SERVER-SOCKET------------" << std::endl;
            std::cout << "Protokoll: " << (int) *data->getComProtocol() << std::endl;
            std::cout << "Laenge: " << len << std::endl;
            std::cout << "Message: " << buf << std::endl;
            std::cout << "Client-IP: " << ip.mb_str() << std::endl;
            std::cout << "-----------------------------------" << std::endl;

            delete[] buf;

            // Send Event with Message
            MessageEvent myevent(wxEVT_COMMAND_MESSAGE);
            myevent.setSocketData(data);
            myevent.setClientIP(ip);
            myevent.setMessageType(RECEIVE);
            myevent.SetEventObject(this);
            ProcessEvent(myevent);

            // Enable input events again.
            sock->SetNotify(wxSOCKET_LOST_FLAG | wxSOCKET_INPUT_FLAG);
            break;
        }
        case wxSOCKET_LOST:
        {
            sock->Destroy();
            break;
        }
        default: ;
    }
}
