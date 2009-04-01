#ifndef CONTACTLIST_H_INCLUDED
#define CONTACTLIST_H_INCLUDED

#include <wx/string.h>
#include <wx/tokenzr.h>
#include <list>

struct Buddy
{
    Buddy(wxString ip,wxString nickname) : m_ip(ip), m_name(nickname){};
    wxString m_ip;
    wxString m_name;
};

typedef std::list<Buddy*> Buddies;

class ContactList {
public:
    static ContactList* getInstance();
    wxString serialize();
    void unserialize(wxString list);
    void add(wxString ip, wxString nickname);
    bool inList(wxString ip);
protected:
    ContactList();
private:
    static ContactList* pinstance;
    std::list<Buddy*> buddy_list;
    Buddies::iterator it;
};

#endif // CONTACTLIST_H_INCLUDED
