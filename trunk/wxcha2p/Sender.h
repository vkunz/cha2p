#ifndef SENDER_H_INCLUDED
#define SENDER_H_INCLUDED

#include "socketClient.h"
#include "OutputData.h"

class Sender {
public:
    void SendMessage(wxString hostname, int port, OutputData* output);
private:
    SocketClient socket;
};

#endif // SENDER_H_INCLUDED
