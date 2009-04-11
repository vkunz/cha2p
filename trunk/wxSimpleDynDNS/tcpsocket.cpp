//
// tcpsocket.cpp
//
// (c) Markus Schäffter, Hochschule Ulm 2008
//

#include "tcpsocket.h"

#include <iostream>
#include <winsock2.h>
#include <windows.h>
#include "string.h"
#include <ws2tcpip.h>

using namespace std;

static int _nboftcpsockets = 0;

tcpSocket::~tcpSocket() {
  if (_socketstatus != SOCKETSTATUS_UNDEFINED && _socketstatus != SOCKETSTATUS_CLOSED) {
    closesocket (_localsocket);
  }

  _nboftcpsockets--;
  if (_nboftcpsockets == 0)
    WSACleanup();
}


tcpSocket::tcpSocket() {
  if (_nboftcpsockets == 0) {
    WSADATA retval;
    if (WSAStartup(MAKEWORD(2,0), &retval)) {
      cerr << "TCPsocket: WSAstartup failed.\n";
	}
  }

  _nboftcpsockets++;

  // TCP: SOCK_STREAM
  // UDP: SOCK_DGRAM
  _localsocket = socket(AF_INET, SOCK_STREAM, 0);
  if (_localsocket == INVALID_SOCKET) {
    cerr << "TCPsocket: Opening socket failed.\n";
  }
  _socketstatus = SOCKETSTATUS_OPENED;
}


tcpSocket& tcpSocket::operator=(tcpSocket& mys) {
  _localsocket = mys._localsocket;
  _socketstatus = mys._socketstatus;
  return *this;
}


bool tcpSocket::openserver(int myport, int maxconn) {

  sockaddr_in sa;
  memset(&sa, 0, sizeof(sa));

  sa.sin_family = AF_INET;
  sa.sin_port = htons(myport);

  if (bind (_localsocket, (sockaddr *)&sa, sizeof(sockaddr_in))) {
	cerr << "TCPsocket: Could not bind to socket.\n";
  }

  if (listen(_localsocket, maxconn))
    cerr << "TCPsocket: Could not listen on socket.\n";

  cout << "TCPsocket: Server started, listening on port " << myport << endl;
  return TRUE;
}


bool tcpSocket::connecttoserver(std::string servername, std::string port) {
  struct addrinfo *ailist = NULL;

  if (getaddrinfo(servername.c_str(), port.c_str(), NULL, &ailist)) {
	  cerr << "TCPsocket: Failed to resolve host.\n";
	return FALSE;
  }

  if(connect(_localsocket, ailist->ai_addr, (int) ailist->ai_addrlen)) {
    cerr << "TCPsocket: Could not connect to server.\n";
	return FALSE;
  }

  _socketstatus = SOCKETSTATUS_CONNECTEDCLIENT;
  return TRUE;
}


tcpSocket* tcpSocket::acceptclient () {
  SOCKET newclient;

  newclient = accept (_localsocket, 0, 0);
  if (newclient == INVALID_SOCKET) {
    cerr <<  "TCPsocket: Invalid socket when accepting client connect.\n";
	return NULL;
  }

  tcpSocket* newclientptr = new tcpSocket();
  newclientptr->_localsocket = newclient;
  newclientptr->_socketstatus = SOCKETSTATUS_CLIENTHANDLE;

  return newclientptr;
}


bool tcpSocket::closetcpsocket() {
  closesocket(_localsocket);
  _socketstatus = SOCKETSTATUS_CLOSED;
  return TRUE;
}


std::string tcpSocket::getoneline() {
  char ch = 'x';
  string linein = "";

  while (ch != '\n') {
    if (recv(_localsocket, &ch, 1, 0) <= 0) {
      _socketstatus = SOCKETSTATUS_OPENED;
	  return "";
	}

	linein += ch;
  }
  return linein;
}


std::string tcpSocket::getdata(int nbofchars) {
  char ch;
  string datain = "";

  while (nbofchars > 0) {
    if (recv(_localsocket, &ch, 1, 0) <= 0) {
      _socketstatus = SOCKETSTATUS_OPENED;
	  return "";
	}

	datain += ch;
    nbofchars--;
  }

  return datain;
}


bool tcpSocket::putdata(const std::string dataout) {
  if (send(_localsocket, dataout.c_str(), (int)dataout.length(), 0))
    return TRUE;
  else
    return FALSE;
}
