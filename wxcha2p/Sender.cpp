/*
 * Diese Klasse ist als spätere Thread Klasse zum Versenden der Nachrichten gedacht.
 * Nachrichten sollten also nicht direkt über die Sockets versendet werden, sondern über
 * diese Klasse.
 * Sie verwendet intern die socketClient-Klasse, um die Nachrichten zu senden.
 */

#include "Sender.h"

/*
 * Versenden der Nachricht mit Hilfe der zuständigen Socket-Methode
 */
void Sender::SendMessage(wxString hostname, int port, SocketData* output, bool keepAlive) {
    m_socket.OpenConnection(hostname, port);
    m_socket.SendMessage(output);
    if(!keepAlive) {
        m_socket.CloseConnection();
    }
}
