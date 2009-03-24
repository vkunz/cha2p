/*
 * Diese Klasse ist als sp�tere Thread Klasse zum Versenden der Nachrichten gedacht.
 * Nachrichten sollten also nicht direkt �ber die Sockets versendet werden, sondern �ber
 * diese Klasse.
 * Sie verwendet intern die socketClient-Klasse, um die Nachrichten zu senden.
 */

#include "Sender.h"

/*
 * Versenden der Nachricht mit Hilfe der zust�ndigen Socket-Methode
 */
void Sender::SendMessage(wxString hostname, int port, SocketData* output) {
    socket.OpenConnection(hostname, port);
    socket.SendMessage(output);
    socket.CloseConnection();
}
