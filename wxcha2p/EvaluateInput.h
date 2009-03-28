#ifndef EVALUATEINPUT_H_INCLUDED
#define EVALUATEINPUT_H_INCLUDED

#include <wx/event.h>
#include "MessageEvent.h"
#include "SocketData.h"

class EvaluateInput: private wxEvtHandler {
public:
    void evaluate(MessageEvent& message);

private:
    void channelMessage(SocketData* data);
    void requestContacts(MessageEvent& event);
    void sendContacts(SocketData* data);

};


#endif // EVALUATEINPUT_H_INCLUDED
