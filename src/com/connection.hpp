#ifndef CONNECTION_HPP
#define CONNECTION_HPP

#define PORT 8000
#define TAILLE_TAMPON 255
//Works using the TCP protocol

#ifdef _WIN32
    //sous windows, compiler avec l'option -lws2_32
    #include <winsock2.h>
    typedef int socklen_t;
#else
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <arpa/inet.h>
    #include <netdb.h> //gethostbyname
#endif

#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>




enum connection_type{
  MESSAGE = 0, // Nouveau message
  NEW_CONNECTION = 1, // demande de connection
  PERSON_LEFT = 2, // Information : personne ayant quittée la room
  PERSON_CONNECTED = 3,
  TEST = 63,}; // Information : nouvelle personne connectée à la room

class connection
{
public:
  connection(int fdSocket);

  //~connection();

  void send_message(connection_type type, std::string message);
  void read_message();


private:
  int m_fdSocket;

  //tcp::socket m_socket;
  std::string m_message;
  char Buffer[1024];
};


#endif // CONNECTION_HPP
