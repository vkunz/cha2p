/*
 * Stellt Grundfunktionen zum Erstellen eines Server-Sockets zur Verf�gung.
 * Ist als Singleton-Klasse realisiert, da nie mehr als ein Server ben�tigt wird.
 */

#include "socketServer.h"

#include "MessageEvent.h"
#include "SocketData.h"
#include "enum.h"

#if defined(__WXLINUX__)

#include <netinet/in.h>

#endif

const long SocketServer::SERVER_ID = wxNewId();
const long SocketServer::SOCKET_ID = wxNewId();

BEGIN_EVENT_TABLE(SocketServer,wxEvtHandler)
    EVT_SOCKET(SERVER_ID, SocketServer::OnServerEvent)
    EVT_SOCKET(SOCKET_ID, SocketServer::OnSocketEvent)
END_EVENT_TABLE()

/*
 * Constructor
 * Erstellt den Socket, bindet ihn an einen Port und f�hrt zus�tzliche Initialisierungen durch
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
 * Destructor
 */
SocketServer::~SocketServer() {
    delete m_server;
}

/*
 * Reagiert auf Events am Socket. Dies geschieht bei eingehenden Verbindungen. Diese wird
 * akzeptiert und es werden weitere Handler angegeben, die auf diesen speziellen Socket h�ren
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
 * z�hlen das Empfangen einer Nachricht, ein Verbindungsabbruch, ...
 */
void SocketServer::OnSocketEvent(wxSocketEvent& event) {
    wxSocketBase* sock = event.GetSocket();
    // Now we process the event
    switch(event.GetSocketEvent()) {
        case wxSOCKET_INPUT: {
            break;
        }
        case wxSOCKET_LOST: {
            // We disable input events, so that it doesn't trigger
            // wxSocketEvent again.
            sock->SetNotify(wxSOCKET_LOST_FLAG);

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

            buf[len] = '\0';

            data->setMessage(wxString::From8BitData(buf));

            // get client ip
            wxIPV4address addr;
            sock->GetPeer(addr);
            wxString clientIP = addr.IPAddress();

            // get host ip
            sock->GetLocal(addr);
            wxString hostIP = addr.IPAddress();

            std::cout << "-------------INCOMING--------------" << std::endl;
            std::cout << "Protokoll: " << (int) *data->getComProtocol() << std::endl;
            std::cout << "Laenge: " << len << std::endl;
            std::cout << "Message: " << buf << std::endl;
            std::cout << "Client-IP: " << clientIP.mb_str() << std::endl;
            std::cout << "-----------------------------------" << std::endl;

            delete[] buf;

            // Send Event with Message
            MessageEvent myevent(wxEVT_COMMAND_MESSAGE);
            myevent.setSocketData(data);
            myevent.setClientIP(clientIP);
            myevent.setHostIP(hostIP);
            myevent.setMessageType(RECEIVE);
            myevent.SetEventObject(this);
            ProcessEvent(myevent);

            // Enable input events again.
            sock->SetNotify(wxSOCKET_LOST_FLAG | wxSOCKET_INPUT_FLAG);

            sock->Destroy();
            break;
        }
        default: ;
    }
}
