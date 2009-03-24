#ifndef OUTPUTDATA_H_INCLUDED
#define OUTPUTDATA_H_INCLUDED

#include <wx/string.h>

class OutputData {
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

#endif // OUTPUTDATA_H_INCLUDED
