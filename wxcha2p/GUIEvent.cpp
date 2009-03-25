#include "GUIEvent.h"

DEFINE_EVENT_TYPE(wxEVT_COMMAND_GUIEvent)
IMPLEMENT_DYNAMIC_CLASS(GUIEvent, wxNotifyEvent)

/*
 * Constructor der Event-Klasse
 */
GUIEvent::GUIEvent(wxEventType commandType, int id)
		: wxNotifyEvent(commandType, id) {}

/*
 * Copy Constructor
 */
GUIEvent::GUIEvent(const GUIEvent& event): wxNotifyEvent(event) {}

/*
 * Clone Funktion. Wird für die internen Abläufe in WX benötigt
 */
wxEvent* GUIEvent::Clone() const
{
	return new GUIEvent(*this);
}

/*
 * Speichert den Text im Event-Objekt
 */
void GUIEvent::setText(wxString text)
{
	m_text = text;
}

/*
 * Setzt den Event-Typ
 */
void GUIEvent::setEventType(guiEventType type) {
    m_type = type;
}

/*
 * Liest die Nachricht des Event-Objekts
 */
wxString GUIEvent::getText()
{
	return m_text;
}

/*
 * Liest den Event-Typ
 */
guiEventType GUIEvent::getEventType() {
    return m_type;
}
