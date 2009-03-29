#ifndef SENDER_H_INCLUDED
#define SENDER_H_INCLUDED

#include <wx/socket.h>
#include "socketClient.h"
#include "SocketData.h"

class Sender {
public:
    void SendMessage(wxString hostname, int port, SocketData* output, bool keepAlive);
private:
    SocketClient m_socket;
};

#endif // SENDER_H_INCLUDED
