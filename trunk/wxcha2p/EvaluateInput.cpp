/*
 * Diese Klasse analysiert ankommende Pakete auf Protokollebene und leitet nachfolgende
 * Schritte ein, wie das Senden einer Antwort oder das Aktuallisieren der GUI
 */

#include "EvaluateInput.h"
#include "enum.h"
#include "GUIEvent.h"

/*
 * Diese Methode analysiert das Paket und wendet je nach gesendetem Protokoll-Schlüssel die
 * richtigen Methoden zur Verarbeitung des Pakets an
 */
void EvaluateInput::evaluate(MessageEvent& message) {
    switch(*message.getSocketData()->getComProtocol()) {
        case CHANNELMESSAGE:
            channelMessage(message.getSocketData());
            break;
    }
}

/*
 * Hier wird ein neues Event erzeugt um der GUI mitzuteilen, dass die neue Nachricht
 * angezeigy     werden soll.
 */
void EvaluateInput::channelMessage(SocketData* data) {
    // Send Event to display Text
    GUIEvent myevent(wxEVT_COMMAND_GUIEvent);
    myevent.setEventType(DISPLAYMESSAGE);
    myevent.setText(data->getMessage());
    myevent.SetEventObject(this);
    ProcessEvent(myevent);
}
