#ifndef SOCKETDATA_H_INCLUDED
#define SOCKETDATA_H_INCLUDED

#include <wx/string.h>

class SocketData {
public:
    SocketData();
    SocketData(const SocketData& data);

    void setComProtocol(unsigned char com);
    void setMessage(wxString message);

    unsigned char* getComProtocol();
    unsigned int getNumBytes();
    wxString getMessage();

private:
    unsigned char m_comProtocol;
    unsigned int m_numBytes;
    wxString m_message;

};

#endif // SOCKETDATA_H_INCLUDED
