#ifndef DISPATCHER_H_INCLUDED
#define DISPATCHER_H_INCLUDED

#include <wx/string.h>
#include "Sender.h"
#include "SocketData.h"

class Dispatcher {
public:
    Dispatcher();
    void sendToAll(SocketData* output);
    void sendToOne(wxString hostname, int port, SocketData* output);

private:
    Sender* m_sender;

};


#endif // DISPATCHER_H_INCLUDED
