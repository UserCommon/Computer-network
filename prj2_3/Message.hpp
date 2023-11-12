#include <iostream>

class Message {
  public:
    Message();
    Message(char msg[1024]);

    std::string msgAsString();

  private:
    char m_message[1024];
};
