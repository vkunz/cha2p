#include "Configuration.h"

#include <wx/socket.h>

Configuration* Configuration::pinstance = 0;

/*
 * protected Constructor, der wegen der Singleton-Eigenschaft nicht von auﬂen
 * aufgerufen werden darf
 */
Configuration::Configuration() {}

/*
 * statische Funktion um eine Instanz der Singleton-Klasse zu bekommen
 */
Configuration* Configuration::getInstance() {
    if (pinstance == 0) {
		pinstance = new Configuration;
	}
	return pinstance;
}

wxString Configuration::getLocalIP() {
    wxIPV4address addr;
    addr.Hostname(wxGetFullHostName());
    wxString ipAddr = addr.IPAddress();
    return ipAddr;
    #warning "Testen, ob richtige IP gefunden wird"
}
