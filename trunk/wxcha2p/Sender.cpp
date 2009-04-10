/*
 * Diese Klasse ist als spätere Thread Klasse zum Versenden der Nachrichten gedacht.
 * Nachrichten sollten also nicht direkt über die Sockets versendet werden, sondern über
 * diese Klasse.
 * Sie verwendet intern die socketClient-Klasse, um die Nachrichten zu senden.
 */

#include "Sender.h"
#include <iostream>
/*
 * Versenden der Nachricht mit Hilfe der zuständigen Socket-Methode
 */
void Sender::SendMessage(wxString hostname, int port, SocketData* output, bool keepAlive) {
    std::cout << "-------------OUTGOING--------------" << std::endl;
    std::cout << "Hostname: " << hostname.mb_str() << " Port: " << port << std::endl;
    std::cout << "Protokoll: " << (int) *output->getComProtocol() << std::endl;
    std::cout << "Laenge: " << output->getNumBytes() << std::endl;
    std::cout << "Message: " << output->getMessage().mb_str() << std::endl;
    std::cout << "-----------------------------------" << std::endl;

    m_socket.OpenConnection(hostname, port);
    m_socket.SendMessage(output);
    if(!keepAlive) {
        m_socket.CloseConnection();
    }
}
