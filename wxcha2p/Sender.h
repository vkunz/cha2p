#ifndef SENDER_H_INCLUDED
#define SENDER_H_INCLUDED

#include "socketClient.h"
#include "SocketData.h"

class Sender {
public:
    void SendMessage(wxString hostname, int port, SocketData* output);
private:
    SocketClient socket;
};

#endif // SENDER_H_INCLUDED
