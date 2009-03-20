#include "MessageEvent.h"

DEFINE_EVENT_TYPE(wxEVT_COMMAND_MESSAGE)
IMPLEMENT_DYNAMIC_CLASS(MessageEvent, wxNotifyEvent)

MessageEvent::MessageEvent(wxEventType commandType, int id)
		: wxNotifyEvent(commandType, id) {}

MessageEvent::MessageEvent(const MessageEvent& event): wxNotifyEvent(event) {}

wxEvent* MessageEvent::Clone() const
{
	return new MessageEvent(*this);
}

void MessageEvent::setMessage(wxString message)
{
	m_message = message;
}

void MessageEvent::setMessageType(messageType type) {
    m_type = type;
}

wxString MessageEvent::getMessage()
{
	return m_message;
}

messageType MessageEvent::getMessageType() {
    return m_type;
}
