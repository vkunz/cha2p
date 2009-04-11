#include "Thread.h"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

ServerThread::ServerThread(tcpSocket* mysock) {
    m_sock = *mysock;
}

void* ServerThread::Entry() {
    string line_in, line_out, file_name;
    stringstream ss;

    //clientconnect = *mycc;
    cout << "   ...connection accepted from client\n\n";

    line_in = m_sock.getoneline();

    cout << "Requestet: \n"  << line_in << "\nRequest end!\n\n\n";

    if (line_in.find("GET") != string::npos)
    {
        fstream ff;
        string filecontent = "";

        file_name = line_in.substr(5,line_in.find("HTTP/1.")-5);

        cout << "filename: " << file_name << endl;

        ff.open(file_name.c_str(), fstream::in);

        if(!ff.good())
        {
            filecontent = "404";
        }
        else
        {
            string tmp;

            while(!ff.eof())
            {
                getline(ff, tmp);
                filecontent += tmp;
            }
        }

        ff.close();

        ss << filecontent.length();
        line_out = "HTTP/1.1 200 OK\nServer: VSYS/0.000000001 (Windoof) HTML/6.0\nContent-Length: " + ss.str() + "\nContent-Language: de\nContent-Type: text/html\nConnection: close\n\n" + filecontent;
    }

    if (m_sock.putdata(line_out))
    {
        cout << "   ...sent: " << line_out;
    }
    else
    {
        cout << "   ...sorry, disconnected.\n";
    }

    m_sock.closetcpsocket();
    cerr << "   ...connection closed\n\n";
}

void ServerThread::OnExit() {

}
