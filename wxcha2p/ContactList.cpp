/*
 * Diese Klasse beeinhaltet die Kontaktliste des eigenen Clients. Diese kann von einem anderen Client
 * kopiert werden. Ebenso können einzelne Kontakte hinzugefügt oder wieder entfernt werden.
 * Wichtig für die Weitergabe der Kontaktliste ist die Serialisierungsmöglichkeit
 */

#include "ContactList.h"

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

}

/*
 * serialisiert die aktuelle Kontaktliste in einen String um diesen anderen Clients zur
 * Verfügung zu stellen
 */
wxString ContactList::serialize() {

}
