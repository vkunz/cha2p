/*
 * Stellt Grundfunktionen zum Erstellen eines Server-Sockets zur Verfügung.
 */

#include "socketServer.h"

#include "MessageEvent.h"
#include "SocketData.h"
#include "enum.h"

const long SocketServer::SERVER_ID = wxNewId();
const long SocketServer::SOCKET_ID = wxNewId();

BEGIN_EVENT_TABLE(SocketServer,wxEvtHandler)
    EVT_SOCKET(SERVER_ID, SocketServer::OnServerEvent)
    EVT_SOCKET(SOCKET_ID, SocketServer::OnSocketEvent)
END_EVENT_TABLE()

/*
 * Constructor
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

/*
 * Reagiert auf Events, die an einem bereits verbundenen Socket entstehen. Hierzu
 * zählen das Empfangen einer Nachricht, ein Verbindungsabbruch, ...
 */
void SocketServer::OnSocketEvent(wxSocketEvent& event) {
    wxSocketBase *sock = event.GetSocket();
    // Now we process the event
    switch(event.GetSocketEvent())
    {
        case wxSOCKET_INPUT:
        {
            // We disable input events, so that the test doesn't trigger
            // wxSocketEvent again.
            sock->SetNotify(wxSOCKET_LOST_FLAG);

            sock->SetFlags(wxSOCKET_WAITALL);

            //read out temp value
            // Which test are we going to run?

            SocketData* data = new SocketData;

            // read protocoll byte
            sock->Read(data->getComProtocol(), 1);

            // read the size
            unsigned char len;
            sock->Read(&len, 1);
            data->setNumBytes(len);

            // Read the data
            char* buf = new char[len];
            sock->Read(buf, len);
            data->setMessage(wxString::FromAscii(buf));
            delete[] buf;

            // Send Event with Message
            MessageEvent myevent(wxEVT_COMMAND_MESSAGE);
            myevent.setSocketData(data);
            myevent.setSocket(sock);
            myevent.setMessageType(RECEIVE);
            myevent.SetEventObject(this);
            ProcessEvent(myevent);

/*            // Which test are we going to run?
            unsigned char c;
            sock->Read(&c, 1);

            switch (c)
            {
                case 0xBE: TestConnection(sock); break;
                case 0xCE: TestConnection(sock); break;
                case 0xDE: TestConnection(sock); break;
            }
*/
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
