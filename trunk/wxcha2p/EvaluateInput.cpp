/*
 * Diese Klasse analysiert ankommende Pakete auf Protokollebene und leitet nachfolgende
 * Schritte ein, wie das Senden einer Antwort oder das Aktuallisieren der GUI
 */

#include "Configuration.h"
#include "ContactList.h"
#include "EvaluateInput.h"
#include "enum.h"
#include "GenerateOutput.h"
#include "GUIEvent.h"

/*
 * Diese Methode analysiert das Paket und wendet je nach gesendetem Protokoll-Schlüssel die
 * richtigen Methoden zur Verarbeitung des Pakets an
 */
void EvaluateInput::evaluate(MessageEvent& event) {
    switch(*event.getSocketData()->getComProtocol()) {
        case CHANNELMESSAGE:
            channelMessage(event.getSocketData());
            break;
        case REQUESTCONTACTS:
            requestContacts(event);
            break;
        case SENDCONTACTS:
            sendContacts(event.getSocketData());
            break;
        case HELLO:
            sayHello(event);
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
#include <iostream>
/*
 * Verarbeitung einer Anfrage nach der eigenen Kontaktliste. Veranlassung der Antwort
 * mit dieser Liste
 */
void EvaluateInput::requestContacts(MessageEvent& message) {
    //read local ip
    Configuration* config = Configuration::getInstance();
    ContactList* contList = ContactList::getInstance();
    contList->add(message.getSocketData()->getMessage(), config->getNickname());

    // initiate output-generation
    GenerateOutput* genOut = GenerateOutput::getInstance();
    genOut->sendContacts(message.getClientIP(), 3000);
}

/*
 * Verarbeitung des Eintreffens einer fremden Kontaktliste und Aufnahme in die eigene
 */
void EvaluateInput::sendContacts(SocketData* data) {
    // store received contact-list
    ContactList* list = ContactList::getInstance();
    list->unserialize(data->getMessage());

    //initiate say hello
    GenerateOutput* genOut = GenerateOutput::getInstance();
    genOut->sayHello();
}

/*
 * Liest die IP-Adresse des sendenden Clients und fügt diese der Kontaktliste zu
 */
void EvaluateInput::sayHello(MessageEvent& event) {
    // add ip to contact-list
    ContactList* list = ContactList::getInstance();
    list->add(event.getClientIP(), event.getSocketData()->getMessage());
}
