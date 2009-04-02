/*
 * Hier wird die Nachricht generiert. Diese Klasse weiß über das grundliegende Protokoll
 * bescheid und prepariert die Nachrichten entsprechend der gewünschten Art.
 * Diese Klasse ist als Singleton implementiert
 */

#include "GenerateOutput.h"

#include "ContactList.h"
#include "enum.h"
#include "socketServer.h"

GenerateOutput* GenerateOutput::pinstance = 0;

/*
 * Protected Constructor fuer Singleton-Klasse
 */
GenerateOutput::GenerateOutput() {
    m_sender = new Sender;
}

/*
 * Erstellt eine Instanz der Singleton-Klasse
 */
GenerateOutput* GenerateOutput::getInstance() {
    if (pinstance == 0) {
		pinstance = new GenerateOutput;
	}
	return pinstance;
}
#include <iostream>
/*
 * Erstellt die Anfrage um von einem fremden Client die Kontaktliste abzufragen
 */
void GenerateOutput::requestContacts(wxString hostname, int port) {
    SocketData* output = new SocketData;
    output->setComProtocol(REQUESTCONTACTS);
    output->setMessage(hostname);

    m_sender->SendMessage(hostname, port, output);
}

/*
 * Sendet an einen fremden Client die Kontaktliste in serialisierter Form
 */
void GenerateOutput::sendContacts(wxString hostname, int port) {
    // serialize ContactList
    ContactList* contact = ContactList::getInstance();
    wxString list = contact->serialize();

    // generate socket-data
    SocketData* output = new SocketData;
    output->setComProtocol(SENDCONTACTS);
    output->setMessage(list);

    // answer client-request
    m_sender->SendMessage(hostname, port, output);
}

/*
 * Präpariert den Output um eine Nachricht an einen Channel zu versenden
 */
void GenerateOutput::SendChannelMessage(wxString message) {
    SocketData* output = new SocketData;

    // generate Message
    output->setComProtocol(CHANNELMESSAGE);
    output->setMessage(message);

    m_sender->SendMessage(wxT("localhost"), 3000, output, false);
}

/*
 * Sagt an alle bekannten Clients HALLO, um in deren Liste aufgenommen zu werden
 */
void GenerateOutput::sayHello() {
    SocketData* output = new SocketData;

    output->setComProtocol(HELLO);
    #warning "Nickname fehlt"

    m_sender->SendMessage(wxT("localhost"), 3000, output, false);
}
