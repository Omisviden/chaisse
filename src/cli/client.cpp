#include "client.hpp"
#include <iostream>

int main(int argc, char *argv[]){

    if (argc != 3) {
        printf("Usage: %s serveur message\n", argv[0]);
        perror("nombre de paramètres incorrect");
        return -1;
    }
    client cli(argv[1]);

    /*
    connection new_connection(argv[1]);
    std::string msg = argv[2];
    new_connection.send_message(TEST, msg);
    new_connection.read_message();
  std::cout<<"hi"<<std::endl;*/
  return 0;
}

client::client(const char* serverName)
{
  struct sockaddr_in addr_serveur;
  struct hostent *serveur;

  m_fdSocket = socket(AF_INET, SOCK_STREAM, 0);       /* création prise */
  if (m_fdSocket < 0)
    {perror("socket"); exit(-1);}

  serveur = gethostbyname(serverName); /* recherche adresse serveur */
  if (serveur == NULL)
    {perror("gethostbyname"); exit(-1);}

  addr_serveur.sin_family = AF_INET;
  addr_serveur.sin_port = htons(PORT);
  addr_serveur.sin_addr = *(struct in_addr *) serveur->h_addr;
  if (connect(m_fdSocket, /* connexion au serveur */
              (struct sockaddr *) &addr_serveur, sizeof addr_serveur) < 0)
    {perror("connect"); exit(-1);}
}

client::~client()
{
  close(m_fdSocket);
  m_fdSocket = -1;
}
