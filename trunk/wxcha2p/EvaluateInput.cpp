/*
 * Diese Klasse analysiert ankommende Pakete auf Protokollebene und leitet nachfolgende
 * Schritte ein, wie das Senden einer Antwort oder das Aktuallisieren der GUI
 */

#include "ContactList.h"
#include "EvaluateInput.h"
#include "enum.h"
#include "GenerateOutput.h"
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
        case REQUESTCONTACTS:
            requestContacts(message);
            break;
        case SENDCONTACTS:
            sendContacts(message.getSocketData());
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

/*
 * Verarbeitung einer Anfrage nach der eigenen Kontaktliste. Veranlassung der Antwort
 * mit dieser Liste
 */
void EvaluateInput::requestContacts(MessageEvent& message) {
    GenerateOutput* genOut = GenerateOutput::getInstance();
    genOut->sendContacts(message);
}

/*
 * Verarbeitung des Eintreffens einer fremden Kontaktliste und Aufnahme in die eigene
 */
void EvaluateInput::sendContacts(SocketData* data) {
    ContactList* list = ContactList::getInstance();
    list->unserialize(data->getMessage());
}
