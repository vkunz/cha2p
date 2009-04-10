#ifndef EVALUATEINPUT_H_INCLUDED
#define EVALUATEINPUT_H_INCLUDED

#include <wx/event.h>
#include "MessageEvent.h"
#include "SocketData.h"

class EvaluateInput: private wxEvtHandler {
public:
    void evaluate(MessageEvent& event);

private:
    void channelMessage(MessageEvent& event);
    void requestContacts(MessageEvent& event);
    void sayHello(MessageEvent& event);
    void sayGoodbye(MessageEvent& event);
    void sendContacts(MessageEvent& event);

    void sendDisplayEvent(wxString message);

};


#endif // EVALUATEINPUT_H_INCLUDED
