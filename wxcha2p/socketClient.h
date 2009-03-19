#ifndef SOCKETCLIENT_H_INCLUDED
#define SOCKETCLIENT_H_INCLUDED

#include <wx/socket.h>
#include <wx/event.h>

class SocketClient : private wxEvtHandler{
public:
    SocketClient();
    ~SocketClient();
    void OpenConnection(wxString hostname, int port);

private:
    wxSocketClient *m_sock;

    void OnSocketEvent(wxSocketEvent& event);

    static const long SOCKET_ID;

    DECLARE_EVENT_TABLE()
};

#endif // SOCKETCLIENT_H_INCLUDED
