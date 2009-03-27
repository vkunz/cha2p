/*
 * Diese Klasse beeinhaltet die Kontaktliste des eigenen Clients. Diese kann von einem anderen Client
 * kopiert werden. Ebenso k�nnen einzelne Kontakte hinzugef�gt oder wieder entfernt werden.
 * Wichtig f�r die Weitergabe der Kontaktliste ist die Serialisierungsm�glichkeit
 */

#include "ContactList.h"

/*
 * privater Constructor, der wegen der Singleton-Eigenschaft nicht von au�en
 * aufgerufen werden darf
 */
ContactList::ContactList() {
    // zun�chst sich selber hinzuf�gen
}

/*
 * statische Funktion um eine Instanz der Singleton-Klasse zu bekommen
 */
ContactList* ContactList::getInstance() {

}

/*
 * serialisiert die aktuelle Kontaktliste in einen String um diesen anderen Clients zur
 * Verf�gung zu stellen
 */
wxString ContactList::serialize() {

}