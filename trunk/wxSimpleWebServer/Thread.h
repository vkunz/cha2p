#ifndef THREAD_H_INCLUDED
#define THREAD_H_INCLUDED

#include <wx/thread.h>
#include "tcpsocket.h"

class ServerThread: public wxThread {
public:
    ServerThread(tcpSocket* mysock);
    virtual void *Entry();
private:
    void OnExit();

    tcpSocket m_sock;
};




#endif // THREAD_H_INCLUDED
