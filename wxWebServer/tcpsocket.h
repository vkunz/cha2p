//
// tcpsocket.h
//

#ifndef bbbb
#define bbbb

#define _WIN32_WINNT 0x0501

#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>



#define SOCKETSTATUS_UNDEFINED -1
#define SOCKETSTATUS_OPENED 0
#define SOCKETSTATUS_LISTENSERVER 1
#define SOCKETSTATUS_CONNECTEDCLIENT 2
#define SOCKETSTATUS_CLIENTHANDLE 3
#define SOCKETSTATUS_CLOSED 11


class tcpSocket {
public:

  virtual ~tcpSocket();
  tcpSocket();
  tcpSocket& operator=(tcpSocket&);

  bool openserver(int myport, int maxconn);
  tcpSocket* acceptclient ();
  bool closetcpsocket();

  bool connecttoserver(std::string, std::string);

  std::string getdata(int);
  std::string getoneline();
  bool putdata(const std::string);

protected:
	int* _refcounter;

private:
  SOCKET _localsocket;
  int _socketstatus;
};

#endif // bbbb
