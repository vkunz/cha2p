#include "Thread.h"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

ServerThread::ServerThread(tcpSocket* mysock,string* entry)
{
    m_sock  = *mysock;
    m_entry = entry;
}

void* ServerThread::Entry()
{
    string line_in, ip;

    line_in = m_sock.getoneline();

    m_sock.putdata("0.0.0.0");

    m_sock.closetcpsocket();
}

void ServerThread::OnExit()
{

}
