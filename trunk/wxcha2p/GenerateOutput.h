#ifndef GENERATEOUTPUT_H_INCLUDED
#define GENERATEOUTPUT_H_INCLUDED

#include <wx/string.h>
#include "Sender.h"
#include "SocketData.h"

class GenerateOutput {
public:
    static GenerateOutput* getInstance();
    SocketData* requestContacts(wxString hostname, int port);
    SocketData* sendContacts();
    void SendChannelMessage(wxString message);
protected:
    GenerateOutput();
private:
    static GenerateOutput* pinstance;
    Sender* m_sender;

};


#endif // GENERATEOUTPUT_H_INCLUDED
