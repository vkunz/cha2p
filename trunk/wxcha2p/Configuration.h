#ifndef CONFIGURATION_H_INCLUDED
#define CONFIGURATION_H_INCLUDED

#include <wx/string.h>

class Configuration {
public:
    static Configuration* getInstance();
    void setNickname(wxString nick);
    wxString getNickname();
    wxString getLocalIP();
protected:
    Configuration();
private:
    static Configuration* pinstance;
    wxString m_nickname;
    wxString m_localIP;
};

#endif // CONFIGURATION_H_INCLUDED
