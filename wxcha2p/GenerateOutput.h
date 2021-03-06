#ifndef GENERATEOUTPUT_H_INCLUDED
#define GENERATEOUTPUT_H_INCLUDED

#include <wx/string.h>
#include "Dispatcher.h"
#include "MessageEvent.h"
#include "SocketData.h"

class GenerateOutput {
public:
    static GenerateOutput* getInstance();
    void setDispatcher(Dispatcher* dis);
    void requestContacts(wxString hostname, int port);
    void sendContacts(wxString hostname, int ip);
    void sayHello();
    void sayGoodbye();
    void SendChannelMessage(wxString message);
    void requestEntry(wxString hostname, int port, wxString channel);
protected:
    GenerateOutput();
private:
    static GenerateOutput* pinstance;
    Dispatcher* m_dispatcher;

};


#endif // GENERATEOUTPUT_H_INCLUDED
