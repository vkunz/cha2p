/*
 * Hier wird die Nachricht generiert. Diese Klasse weiß über das grundliegende Protokoll
 * bescheid und prepariert die Nachrichten entsprechend der gewünschten Art.
 */

#include "GenerateOutput.h"
#include "enum.h"

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
