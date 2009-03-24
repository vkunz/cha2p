/*
 * Hier wird die Nachricht generiert. Diese Klasse wei� �ber das grundliegende Protokoll
 * bescheid und prepariert die Nachrichten entsprechend der gew�nschten Art.
 */

#include "GenerateOutput.h"
#include "enum.h"

/*
 * Pr�pariert den Output um eine Nachricht an einen Channel zu versenden
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
