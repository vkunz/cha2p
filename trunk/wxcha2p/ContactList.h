#ifndef CONTACTLIST_H_INCLUDED
#define CONTACTLIST_H_INCLUDED

/* some global defines for specific things */
#define SEPARATOR_BUDDIES ";"
#define SEPARATOR_IP_NAME ":"

#include <wx/string.h>
#include <wx/tokenzr.h>
#include <list>

struct Buddy
{
    Buddy(wxString ip,wxString nickname) : m_ip(ip), m_nickname(nickname){};
    wxString m_ip;
    wxString m_nickname;
};

typedef std::list<Buddy*> Buddies;

class ContactList {
public:
    static ContactList* getInstance();
    wxString serialize();
    void unserialize(wxString list);
    void add(wxString ip, wxString nickname);
    void remove(wxString ip);
    bool inList(wxString ip);
    wxString getName(wxString ip);
protected:
    ContactList();
private:
    static ContactList* pinstance;
    std::list<Buddy*> buddy_list;
    Buddies::iterator it;
};

#endif // CONTACTLIST_H_INCLUDED
