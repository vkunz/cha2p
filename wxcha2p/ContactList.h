#ifndef CONTACTLIST_H_INCLUDED
#define CONTACTLIST_H_INCLUDED

#include <wx/string.h>

class ContactList {
public:
    static ContactList* getInstance();
    wxString serialize();
    void unserialize(wxString list);
    void add();
    bool inList(wxString ip);
private:
    ContactList();

};

#endif // CONTACTLIST_H_INCLUDED
