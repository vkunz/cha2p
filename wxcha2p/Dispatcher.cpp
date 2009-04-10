#include "Dispatcher.h"

#include "ContactList.h"

Dispatcher::Dispatcher() {
    m_sender = new Sender();
}

/*
 * Sendet den gelieferten Output an alle, die in der Kontaktliste sind
 */
void Dispatcher::sendToAll(SocketData* output) {
    ContactList* contact = ContactList::getInstance();

    std::list<Buddy*>::iterator it;

    for(it = contact->getBuddyList()->begin(); it != contact->getBuddyList()->end(); it++) {
        SocketData* myout = new SocketData(*output);
        m_sender->SendMessage((*it)->m_ip, 3000, myout, false);
    }

    delete output;
}

/*
 * Sendet den gelieferten Output an eine übergebene Adresse
 */
void Dispatcher::sendToOne(wxString hostname, int port, SocketData* output){
    m_sender->SendMessage(hostname, port, output);
}
