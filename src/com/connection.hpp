#ifndef CONNECTION_HPP
#define CONNECTION_HPP

#define PORT 8000
#define TAILLE_TAMPON 255
// Works using the TCP protocole

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

#include <iostream>


enum connection_type{
  MSG = 0, // Nouveau message
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
