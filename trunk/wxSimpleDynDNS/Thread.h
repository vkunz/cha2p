#ifndef THREAD_H_INCLUDED
#define THREAD_H_INCLUDED

#include <wx/thread.h>
#include <string>
#include "tcpsocket.h"

using namespace std;

class ServerThread: public wxThread
{
public:
    ServerThread(tcpSocket* mysock, string* entry);
    virtual void *Entry();
private:
    void OnExit();

    tcpSocket m_sock;
    string* m_entry;
};




#endif // THREAD_H_INCLUDED
