#include "Sender.h"

#include <wx/socket.h>

void Sender::SendMessage(wxString hostname, int port, wxString message) {
    socket.OpenConnection(hostname, port);
    socket.SendMessage(message);
}
