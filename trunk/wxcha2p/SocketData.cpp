/*
 * Klasse um alle Daten für den Austausch zu speichern und an entsprechende Stellen weiterzugeben
 */

#include "SocketData.h"

SocketData::SocketData() {
    m_numBytes = 0;
}

void SocketData::setComProtocol(unsigned char com) {
    m_comProtocol = com;
}

void SocketData::setMessage(wxString message) {
    m_message = message;
    m_numBytes = (unsigned int)((wxStrlen(message) +1) * sizeof(char));
}

unsigned char* SocketData::getComProtocol() {
    return &m_comProtocol;
}

unsigned int* SocketData::getNumBytes() {
    return &m_numBytes;
}

wxString SocketData::getMessage() {
    return m_message;
}
