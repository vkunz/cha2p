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
ContactList::ContactList() {
    // zunächst sich selber hinzufügen
}

/*
 * statische Funktion um eine Instanz der Singleton-Klasse zu bekommen
 */
ContactList* ContactList::getInstance() {
    if (pinstance == 0) {
		pinstance = new ContactList;
	}
	return pinstance;
}

/*
 * serialisiert die aktuelle Kontaktliste in einen String um diesen anderen Clients zur
 * Verfügung zu stellen
 */
wxString ContactList::serialize() {
    wxString str = wxT("ip1:nick1;ip2:nick2");
    return str;
}

#include <wx/msgdlg.h>
/*
 * liest einen String ein und generiert daraus eine Kontaktliste
 */
void ContactList::unserialize(wxString list) {
    wxMessageBox(list);
}

/*
 * fuegt einen neuen Kontakt der Liste zu
 */
void ContactList::add(wxString ip, wxString nickname) {

}
