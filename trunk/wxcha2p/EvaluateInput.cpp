/*
 * Diese Klasse analysiert ankommende Pakete auf Protokollebene und leitet nachfolgende
 * Schritte ein, wie das Senden einer Antwort oder das Aktuallisieren der GUI
 */

#include "EvaluateInput.h"
#include "enum.h"

#include <wx/msgdlg.h>

void EvaluateInput::evaluate(SocketData* data) {
    switch(*data->getComProtocol()) {
        case CHANNELMESSAGE:
            // es fehlt ein neues Event um die Nachricht an die GUI zu senden
            wxMessageBox(data->getMessage());
            break;
    }
}
