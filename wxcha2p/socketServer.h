#ifndef SOCKET_H_INCLUDED
#define SOCKET_H_INCLUDED

#include <wx/socket.h>
#include <wx/event.h>
#include "SocketData.h"


class SocketServer : private wxEvtHandler {
public:
    SocketServer(int port);
    ~SocketServer();

protected:

private:
    void OnServerEvent(wxSocketEvent& event);
    void OnSocketEvent(wxSocketEvent& event);

    wxSocketServer* m_server;

    static const long SERVER_ID;
    static const long SOCKET_ID;

    DECLARE_EVENT_TABLE();
};

#endif // SOCKET_H_INCLUDED
