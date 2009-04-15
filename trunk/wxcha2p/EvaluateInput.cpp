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
            channelMessage(event);
            break;
        case REQUESTCONTACTS:
            requestContacts(event);
            break;
        case SENDCONTACTS:
            sendContacts(event);
            break;
        case HELLO:
            sayHello(event);
            break;
        case GOODBYE:
            sayGoodbye(event);
            break;
        case SENDENTRY:
            sendEntry(event.getSocketData());
            break;
    }
}

/*
 * Hier wird ein neues Event erzeugt um der GUI mitzuteilen, dass die neue Nachricht
 * angezeigt     werden soll.
 */
void EvaluateInput::channelMessage(MessageEvent& event) {
    ContactList* contList = ContactList::getInstance();

    wxString msg = contList->getName(event.getClientIP()) + wxT(": ") + event.getSocketData()->getMessage();
    sendDisplayEvent(msg);
}

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
void EvaluateInput::sendContacts(MessageEvent& event) {
    // store received contact-list
    ContactList* list = ContactList::getInstance();
    list->unserialize(event.getSocketData()->getMessage());

    // add yourself to contactlist
    Configuration* config = Configuration::getInstance();
    list->add(event.getHostIP(), config->getNickname());

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

    //prepare GUI-Text
    wxString msg = event.getSocketData()->getMessage() + wxT(" connected...");
    sendDisplayEvent(msg);
}

/*
 * Loescht den sendenden Client von der Contaktliste
 */
void EvaluateInput::sayGoodbye(MessageEvent& event) {
    ContactList* list = ContactList::getInstance();
    list->remove(event.getClientIP());

    //prepare GUI-Text
    wxString msg = list->getName(event.getClientIP()) + wxT(" disconnected...");
    sendDisplayEvent(msg);
}

/*
 * Empfaengt die Adresse eine Clients im gewuenschten Channel und veranlasst den Verbindungsaufbau
 */
void EvaluateInput::sendEntry(SocketData* data) {
    GenerateOutput* genOut = GenerateOutput::getInstance();

    genOut->requestContacts(data->getMessage(), 3000);
}

/*
 * Sendet ein Event um eine Nachricht in der GUI anzuzeigen
 */
void EvaluateInput::sendDisplayEvent(wxString message) {
    // Send Event to display Text
    GUIEvent myevent(wxEVT_COMMAND_GUIEvent);
    myevent.setEventType(DISPLAYMESSAGE);
    myevent.setText(message);
    myevent.SetEventObject(this);
    ProcessEvent(myevent);
}
