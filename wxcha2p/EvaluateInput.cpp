/*
 * Diese Klasse analysiert ankommende Pakete auf Protokollebene und leitet nachfolgende
 * Schritte ein, wie das Senden einer Antwort oder das Aktuallisieren der GUI
 */

#include "EvaluateInput.h"
#include "enum.h"
#include "GUIEvent.h"

void EvaluateInput::evaluate(SocketData* data) {
    switch(*data->getComProtocol()) {
        case CHANNELMESSAGE:
            // Send Event to display Text
            GUIEvent myevent(wxEVT_COMMAND_GUIEvent);
            myevent.setEventType(DISPLAYMESSAGE);
            myevent.setText(data->getMessage());
//            myevent.SetEventObject(this);
            ProcessEvent(myevent);
            break;
    }
}
