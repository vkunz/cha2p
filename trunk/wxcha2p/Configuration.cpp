#include "Configuration.h"

#include <wx/socket.h>

Configuration* Configuration::pinstance = 0;

/*
 * protected Constructor, der wegen der Singleton-Eigenschaft nicht von auﬂen
 * aufgerufen werden darf
 */
Configuration::Configuration() {
    m_nickname = wxT("Nick");
}

/*
 * statische Funktion um eine Instanz der Singleton-Klasse zu bekommen
 */
Configuration* Configuration::getInstance() {
    if (pinstance == 0) {
		pinstance = new Configuration;
	}
	return pinstance;
}

void Configuration::setNickname(wxString nick) {
    m_nickname = nick;
}

wxString Configuration::getNickname() {
    return m_nickname;
}
