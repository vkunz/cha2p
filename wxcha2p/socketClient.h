#ifndef SOCKETCLIENT_H_INCLUDED
#define SOCKETCLIENT_H_INCLUDED

#include <wx/socket.h>
#include <wx/event.h>

#include "OutputData.h"

class SocketClient : private wxEvtHandler{
public:
    SocketClient();
    ~SocketClient();
    void OpenConnection(wxString hostname, int port);
    void SendMessage(OutputData* output);
    void CloseConnection();

private:
    void OnSocketEvent(wxSocketEvent& event);

    wxSocketClient *m_sock;

    static const long SOCKET_ID;

    DECLARE_EVENT_TABLE()
};

#endif // SOCKETCLIENT_H_INCLUDED
