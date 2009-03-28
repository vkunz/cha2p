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
GenerateOutput::GenerateOutput() {}

/*
 * Erstellt eine Instanz der Singleton-Klasse
 */
GenerateOutput* GenerateOutput::getInstance() {
    if (pinstance == 0) {
		pinstance = new GenerateOutput;
	}
	return pinstance;
}

/*
 * Präpariert den Output um eine Nachricht an einen Channel zu versenden
 */
SocketData* GenerateOutput::SendChannelMessage(wxString message) {
    SocketData* output = new SocketData;

    // Communication Protocoll
    output->setComProtocol(CHANNELMESSAGE);
    //Message-Length
    output->setNumBytes((unsigned char)((wxStrlen(message) + 1) * sizeof(char)));
    //Message
    output->setMessage(message);

    return output;
}

/*
 * Erstellt die Anfrage um von einem fremden Client die Kontaktliste abzufragen
 */
SocketData* GenerateOutput::requestContacts() {
    SocketData* output = new SocketData;
    output->setComProtocol(REQUESTCONTACTS);
    output->setNumBytes(0);

    return output;
}

/*
 * Sendet an einen fremden Client die Kontaktliste in serialisierter Form
 */
SocketData* GenerateOutput::sendContacts() {
    // serialize ContactList
    ContactList* contact = ContactList::getInstance();
    wxString list = contact->serialize();

    // generate socket-data
    SocketData* output = new SocketData;
    output->setComProtocol(SENDCONTACTS);
    output->setNumBytes((unsigned char)((wxStrlen(list) +1) * sizeof(char)));
    output->setMessage(list);

    SocketServer* server = SocketServer::getInstance(3000);
    //server->AnswerRequest(

    return output;
}
