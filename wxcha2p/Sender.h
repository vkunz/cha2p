#ifndef SENDER_H_INCLUDED
#define SENDER_H_INCLUDED

#include "socketClient.h"

class Sender {
public:
    void SendMessage(wxString hostname, int port, wxString message);
private:
    SocketClient socket;
};

#endif // SENDER_H_INCLUDED
