#ifndef GUIEVENT_H_INCLUDED
#define GUIEVENT_H_INCLUDED

#include <wx/event.h>
#include <wx/string.h>
#include "enum.h"

class GUIEvent : public wxNotifyEvent
{
private:
	wxString m_text;
	guiEventType m_type;

public:
	GUIEvent(wxEventType commandType = wxEVT_NULL, int id = 0);
	GUIEvent(const GUIEvent& event);
	virtual wxEvent* Clone() const;

	void setText(wxString text);
	void setEventType(guiEventType type);

	wxString getText();
	guiEventType getEventType();

	DECLARE_DYNAMIC_CLASS(GUIEvent);
};

typedef void (wxEvtHandler::*GUIEventFunction)(GUIEvent&);

BEGIN_DECLARE_EVENT_TYPES()
DECLARE_EVENT_TYPE(wxEVT_COMMAND_GUIEvent, 801)
END_DECLARE_EVENT_TYPES()

#define EVT_GUI(id, fn) DECLARE_EVENT_TABLE_ENTRY( \
wxEVT_COMMAND_GUIEvent, id, -1, (wxObjectEventFunction) \
(wxEventFunction) (GUIEventFunction) & fn, \
(wxObject *) NULL ),


#endif // GUIEVENT_H_INCLUDED
