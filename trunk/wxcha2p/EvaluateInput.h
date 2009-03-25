#ifndef EVALUATEINPUT_H_INCLUDED
#define EVALUATEINPUT_H_INCLUDED

#include <wx/event.h>
#include "SocketData.h"

class EvaluateInput: private wxEvtHandler {
public:
    void evaluate(SocketData* data);

private:
    void channelMessage(SocketData* data);

};


#endif // EVALUATEINPUT_H_INCLUDED
