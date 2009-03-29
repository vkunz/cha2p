#ifndef GENERATEOUTPUT_H_INCLUDED
#define GENERATEOUTPUT_H_INCLUDED

#include <wx/string.h>
#include "MessageEvent.h"
#include "Sender.h"
#include "SocketData.h"

class GenerateOutput {
public:
    static GenerateOutput* getInstance();
    void requestContacts(wxString hostname, int port);
    void sendContacts(MessageEvent& event);
    void sayHello();
    void SendChannelMessage(wxString message);
protected:
    GenerateOutput();
private:
    static GenerateOutput* pinstance;
    Sender* m_sender;

};


#endif // GENERATEOUTPUT_H_INCLUDED
