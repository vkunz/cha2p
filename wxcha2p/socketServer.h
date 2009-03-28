#ifndef SOCKET_H_INCLUDED
#define SOCKET_H_INCLUDED

#include <wx/socket.h>
#include <wx/event.h>
#include "SocketData.h"


class SocketServer : private wxEvtHandler {
public:
    static SocketServer* getInstance(int port);
    ~SocketServer();
    void AnswerRequest(wxSocketBase* sock, SocketData* output);

protected:
    SocketServer(int port);
private:
    void OnServerEvent(wxSocketEvent& event);
    void OnSocketEvent(wxSocketEvent& event);

    wxSocketServer* m_server;

    static SocketServer* pinstance;
    static const long SERVER_ID;
    static const long SOCKET_ID;

//    wxMenu         *m_menuFile;  //???????????????????????
//    wxMenuBar      *m_menuBar;  //?????????????????????
//    bool            m_busy;  //???????????

    DECLARE_EVENT_TABLE();
};

#endif // SOCKET_H_INCLUDED
