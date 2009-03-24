#include "OutputData.h"

void OutputData::setComProtocol(unsigned char com) {
    m_comProtocol = com;
}

void OutputData::setNumBytes(unsigned char num) {
    m_numBytes = num;
}

void OutputData::setMessage(wxString message) {
    m_message = message;
}

unsigned char* OutputData::getComProtocol() {
    return &m_comProtocol;
}

unsigned char* OutputData::getNumBytes() {
    return &m_numBytes;
}

wxString OutputData::getMessage() {
    return m_message;
}
