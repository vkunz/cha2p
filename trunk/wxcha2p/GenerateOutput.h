#ifndef GENERATEOUTPUT_H_INCLUDED
#define GENERATEOUTPUT_H_INCLUDED

#include <wx/string.h>
#include "SocketData.h"

class GenerateOutput {
public:
    static GenerateOutput* getInstance();
    SocketData* requestContacts();
    SocketData* sendContacts();
    SocketData* SendChannelMessage(wxString message);
protected:
    GenerateOutput();
private:
    static GenerateOutput* pinstance;

};


#endif // GENERATEOUTPUT_H_INCLUDED
