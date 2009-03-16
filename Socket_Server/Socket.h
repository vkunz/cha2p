#ifndef SOCKET_H_INCLUDED
#define SOCKET_H_INCLUDED

class Socket {
public:


    void Test1(wxSocketBase *sock);

private:
    wxSocketServer *m_server;
    wxTextCtrl     *m_text;
    wxMenu         *m_menuFile;
    wxMenuBar      *m_menuBar;
    bool            m_busy;
    int             m_numClients;

    // any class wishing to process wxWidgets events must use this macro
    DECLARE_EVENT_TABLE()

};

#endif // SOCKET_H_INCLUDED
