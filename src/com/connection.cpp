#include "connection.hpp"

connection::connection(int fdSocket) : m_fdSocket(fdSocket){}



//=========================
//***** COMMUNICATION *****
//=========================

//requete format : En TETE [Taille message, type du message]
                  //Corps Message

void connection::send_message(connection_type type, std::string message)
{
  char requete[TAILLE_TAMPON];

  int longueur = snprintf(requete, (int)message.length()+2,
                      "%c%c%s", (int)message.length()+'\0', type+'\0',
                      message.c_str());
  send(m_fdSocket, requete, longueur, 0);
}

void connection::read_message(){
    char tampon[TAILLE_TAMPON];
    read(m_fdSocket, tampon, TAILLE_TAMPON);     /* lecture par bloc */

    // Décriptage de la requete
    std::cout<<"Taille du message : "<< tampon[0]-'\0' <<std::endl;
    std::cout<<"Type de message : " << tampon[1]-'\0' << std::endl;
    tampon[tampon[0]-'\0'+2] = '\0';
    std::cout << &tampon[2] << std::endl;
}
