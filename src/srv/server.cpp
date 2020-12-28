#include "server.hpp"
#include <iostream>

int main()
{
  server srv;
  srv.wait_for_connection();
  connection co(srv.m_fdSocket);// srv.send_message('c', "hello world!");
  co.send_message(MSG, "hello world ! :3");
  co.read_message();
}

server::server()
{
  struct sockaddr_in adresse_serveur;
  size_t taille_adresse_serveur;

  m_fdServer = socket(AF_INET, SOCK_STREAM, 0);
  if(m_fdServer < 0)
    {perror("socket"); exit(-1);}

  /* 3.2 Remplissage de l'adresse de réception
     (protocole Internet TCP-IP, réception acceptée sur toutes
     les adresses IP du serveur, numéro de port indiqué)*/

  adresse_serveur.sin_family = AF_INET;
  adresse_serveur.sin_addr.s_addr = INADDR_ANY;
  adresse_serveur.sin_port = htons(PORT);
  /* 3.3 Association du socket au port de réception */
  taille_adresse_serveur = sizeof adresse_serveur;
  if (bind(m_fdServer, (struct sockaddr *) &adresse_serveur, taille_adresse_serveur) < 0)
    {perror("Binding socket failed");exit(-1);}

  // Ouverture du service
  listen(m_fdServer, 4);//4 for max connections in wait
}

server::~server()
{
  close(m_fdSocket);
  close(m_fdServer);
}

void server::wait_for_connection()
{
  // mode connecté
  printf("SERVEUR> Le serveur écoute le port %d\n", PORT);
  while ((m_fdSocket = accept(m_fdServer, NULL, NULL)) < 0)
  {
    if (errno != EINTR)
    {
      perror("newcoming connection failed");
      exit(3);
    }
  }
  std::cout<<"connection entrante"<<std::endl;
}
