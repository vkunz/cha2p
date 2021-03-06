/*
 * Event-Klasse
 * Dieses Event wird ausgel�st, wenn eine Nachricht vom Server-Socket empfangen wurde,
 * bzw. wenn �ber die Eingabe eine neue Nachricht eingegeben wurde.
 * Versendet wird �ber das Event die Nachricht und ob es sich um den Empfang oder Versand
 * einer Nachricht handelt.
 */

#include "MessageEvent.h"

DEFINE_EVENT_TYPE(wxEVT_COMMAND_MESSAGE)
IMPLEMENT_DYNAMIC_CLASS(MessageEvent, wxNotifyEvent)

/*
 * Constructor der Event-Klasse
 */
MessageEvent::MessageEvent(wxEventType commandType, int id)
		: wxNotifyEvent(commandType, id) {}

/*
 * Copy Constructor
 */
MessageEvent::MessageEvent(const MessageEvent& event): wxNotifyEvent(event) {}

/*
 * Clone Funktion. Wird f�r die internen Abl�ufe in WX ben�tigt
 */
wxEvent* MessageEvent::Clone() const
{
	return new MessageEvent(*this);
}

/*
 * Speichert die Nachricht im Event-Objekt
 */
void MessageEvent::setMessage(wxString message)
{
	m_message = message;
}

/*
 * Setzt den Pointer auf ein SocketData-Objekt
 */
void MessageEvent::setSocketData(SocketData* data) {
    m_socketData = data;
}

/*
 * Setzt den Event-Typ
 */
void MessageEvent::setMessageType(messageType type) {
    m_type = type;
}

/*
 * Setzt die IP des verbundenen Clients
 */
void MessageEvent::setClientIP(wxString ip) {
    m_clientIP = ip;
}

/*
 * Setzt die IP des Host-Clients
 */
void MessageEvent::setHostIP(wxString ip) {
    m_HostIP = ip;
}

/*
 * Liest die Nachricht des Event-Objekts
 */
wxString MessageEvent::getMessage()
{
	return m_message;
}

/*
 * Liest den Pointer auf ein SocketData-Objekt
 */
SocketData* MessageEvent::getSocketData() {
    return m_socketData;
}

/*
 * Liest den Event-Typ
 */
messageType MessageEvent::getMessageType() {
    return m_type;
}

/*
 * Liest die Client-IP
 */
wxString MessageEvent::getClientIP() {
    return m_clientIP;
}

/*
 * Liest die Host-IP
 */
wxString MessageEvent::getHostIP() {
    return m_HostIP;
}
