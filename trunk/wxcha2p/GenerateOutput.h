#ifndef GENERATEOUTPUT_H_INCLUDED
#define GENERATEOUTPUT_H_INCLUDED

#include <wx/string.h>
#include "SocketData.h"

class GenerateOutput {
public:
    SocketData* requestContacts();
    SocketData* sendContacts();
    SocketData* SendChannelMessage(wxString message);

private:

};


#endif // GENERATEOUTPUT_H_INCLUDED
