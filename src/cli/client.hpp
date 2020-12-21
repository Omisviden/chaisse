#ifndef CLIENT_HPP
#define CLIENT_HPP

//includes
#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <signal.h>
#include <arpa/inet.h>
#include <netdb.h> //gethostbyname
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
//#include <string>

#include "../com/connection.hpp"

class client
{
public:
  client(const char* serverName);
  ~client();

private:
  int m_fdSocket;
};




#endif //CLIENT_HPP
