#ifndef CLIENT_HPP
#define CLIENT_HPP


#include <string>

#include "../com/connection.hpp"

class client
{
public:
  client(const char* serverName);
  ~client();
connection m_co;
private:

  int m_fdSocket;
};




#endif //CLIENT_HPP
