#include "socketServer.h"

BEGIN_EVENT_TABLE(SocketServer,wxEvtHandler)
    EVT_SOCKET(SERVER_ID, SocketServer::OnServerEvent)
    EVT_SOCKET(SOCKET_ID, SocketServer::OnSocketEvent)
END_EVENT_TABLE()

const long SocketServer::SERVER_ID = wxNewId();
const long SocketServer::SOCKET_ID = wxNewId();

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

//    m_busy = false;
}

SocketServer::~SocketServer() {
    delete m_server;
}

void SocketServer::OnServerEvent(wxSocketEvent& event) {
    wxSocketBase *sock;
    sock = m_server->Accept(false);

    sock->SetEventHandler(*this, SOCKET_ID);
    sock->SetNotify(wxSOCKET_INPUT_FLAG | wxSOCKET_LOST_FLAG);
    sock->Notify(true);
}

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

            // Which test are we going to run?
            unsigned char c;
            sock->Read(&c, 1);

            switch (c)
            {
//                case 0xBE: TestConnection(sock); break;
//                case 0xCE: TestConnection(sock); break;
//                case 0xDE: TestConnection(sock); break;
            }

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