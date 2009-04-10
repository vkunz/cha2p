#ifndef MESSAGEEVENT_H_INCLUDED
#define MESSAGEEVENT_H_INCLUDED

#include <wx/event.h>
#include <wx/string.h>
#include "enum.h"
#include "SocketData.h"

class MessageEvent : public wxNotifyEvent
{
private:
	wxString m_message;
	wxString m_clientIP;
	wxString m_HostIP;
	messageType m_type;
	SocketData* m_socketData;

public:
	MessageEvent(wxEventType commandType = wxEVT_NULL, int id = 0);
	MessageEvent(const MessageEvent& event);
	virtual wxEvent* Clone() const;

	void setMessage(wxString message);
	void setSocketData(SocketData* data);
	void setMessageType(messageType type);
	void setClientIP(wxString ip);
	void setHostIP(wxString ip);

	wxString getMessage();
	SocketData* getSocketData();
	messageType getMessageType();
	wxString getClientIP();
	wxString getHostIP();

	DECLARE_DYNAMIC_CLASS(MessageEvent);
};

typedef void (wxEvtHandler::*MessageEventFunction)(MessageEvent&);

BEGIN_DECLARE_EVENT_TYPES()
DECLARE_EVENT_TYPE(wxEVT_COMMAND_MESSAGE, 800)
END_DECLARE_EVENT_TYPES()

#define EVT_MESSAGE(id, fn) DECLARE_EVENT_TABLE_ENTRY( \
wxEVT_COMMAND_MESSAGE, id, -1, (wxObjectEventFunction) \
(wxEventFunction) (MessageEventFunction) & fn, \
(wxObject *) NULL ),


#endif // MESSAGEEVENT_H_INCLUDED
