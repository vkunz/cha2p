#ifndef SOCKETDATA_H_INCLUDED
#define SOCKETDATA_H_INCLUDED

#include <wx/string.h>

class SocketData {
public:
    void setComProtocol(unsigned char com);
    void setNumBytes(unsigned char num);
    void setMessage(wxString message);

    unsigned char* getComProtocol();
    unsigned char* getNumBytes();
    wxString getMessage();

private:
    unsigned char m_comProtocol;
    unsigned char m_numBytes;
    wxString m_message;

};

#endif // SOCKETDATA_H_INCLUDED
