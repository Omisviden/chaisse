#ifndef SERVER_HPP
#define SERVER_HPP
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

// A définir dans connection
#define PORT 8000


class server
{
public:
  server();
  ~server();

  void wait_for_connection();
  void send_message(char messageType, std::string message);
//private:
  int m_fdServer;
  int m_fdSocket;
};

#endif //SERVER_HPP
