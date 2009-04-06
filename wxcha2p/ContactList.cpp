/*
 * Diese Klasse beeinhaltet die Kontaktliste des eigenen Clients. Diese kann von einem anderen Client
 * kopiert werden. Ebenso können einzelne Kontakte hinzugefügt oder wieder entfernt werden.
 * Wichtig für die Weitergabe der Kontaktliste ist die Serialisierungsmöglichkeit
 */

#include "ContactList.h"

ContactList* ContactList::pinstance = 0;

/*
 * privater Constructor, der wegen der Singleton-Eigenschaft nicht von außen
 * aufgerufen werden darf
 */
ContactList::ContactList()
{
    // zunächst sich selber hinzufügen
}

/*
 * statische Funktion um eine Instanz der Singleton-Klasse zu bekommen
 */
ContactList* ContactList::getInstance()
{
    if (pinstance == 0)
    {
		pinstance = new ContactList;
	}

	return pinstance;
}

/*
 * serialisiert die aktuelle Kontaktliste in einen String um diesen anderen Clients zur
 * Verfügung zu stellen
 */
wxString ContactList::serialize()
{
    wxString serialized = wxT("");

    for ( it = buddy_list.begin() ; it != buddy_list.end(); it++ )
    {
        if ( ! serialized.IsEmpty() )
        {
            serialized += wxT(SEPARATOR_BUDDIES);
        }
        serialized += (*it)->m_ip + wxT(SEPARATOR_IP_NAME) + (*it)->m_nickname;
    }

    return serialized;
}

/*
 * liest einen String ein und generiert daraus eine Kontaktliste
 */
void ContactList::unserialize(wxString list)
{
    wxString ip, name, token;
    wxStringTokenizer btok(list, wxT(SEPARATOR_BUDDIES));

    while ( btok.HasMoreTokens() )
    {
        /*hole naechsten token <IP:NAME> aus dem string*/
        token = btok.GetNextToken();

        /*annahme dass token immer <IP>SEPARATOR_IP_NAME<NAME> ist*/
        wxStringTokenizer dtok(token, wxT(SEPARATOR_IP_NAME));

        #warning "Nicknames duerfen KEINEN der verwendeten Separatoren enthalten!!"

        /*falls fehlformatiert rest skippen*/
        if ( ! dtok.HasMoreTokens() ) continue;
        ip   = dtok.GetNextToken();

        /*falls fehlformatiert rest skippen*/
        if ( ! dtok.HasMoreTokens() ) continue;
        name = dtok.GetNextToken();

        /*trage buddy in liste ein*/
        add(ip,name);
    }
}
#include <iostream>
/*
 * fuegt einen neuen Kontakt der Liste zu
 */
void ContactList::add(wxString ip, wxString nickname)
{
    /* falls ip noch nicht in der liste, fuege buddy ein */
    if ( ! inList(ip) )
    {
        buddy_list.push_back( new Buddy( ip, nickname ) );
    }
}

/*
 * loescht einen Kontakt aus der Liste
 */
void ContactList::remove(wxString ip)
{
    wxString nickname = getName(ip);

    /* falls kein name gefunden muss auch nicht geloescht werden */
    if ( ! nickname.IsEmpty() )
    {
        buddy_list.remove( new Buddy( ip, nickname ) );
    }
}

/*
 * ip zu nickname aufloesung
 */
wxString ContactList::getName(wxString ip)
{
    /* falls ip in der liste, gib name zurueck */
    for ( it = buddy_list.begin() ; it != buddy_list.end(); it++ )
    {
        if ((*it)->m_ip == ip )
        {
            return (*it)->m_nickname;
        }
    }
    return wxT("");
}

/*
 * sucht IP in der Buddy-Liste und gibt bei Treffer true
 * zurueck
 */
bool ContactList::inList(wxString ip)
{
    for ( it = buddy_list.begin() ; it != buddy_list.end(); it++ )
    {
        if ((*it)->m_ip == ip )
        {
            return true;
        }
    }
    return false;
}
