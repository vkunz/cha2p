/*
 * Klasse um alle Daten für den Austausch zu speichern und an entsprechende Stellen weiterzugeben
 */

#include "SocketData.h"

void SocketData::setComProtocol(unsigned char com) {
    m_comProtocol = com;
}

void SocketData::setNumBytes(unsigned char num) {
    m_numBytes = num;
}

void SocketData::setMessage(wxString message) {
    m_message = message;
}

unsigned char* SocketData::getComProtocol() {
    return &m_comProtocol;
}

unsigned char* SocketData::getNumBytes() {
    return &m_numBytes;
}

wxString SocketData::getMessage() {
    return m_message;
}
