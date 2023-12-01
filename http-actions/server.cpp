#include <cstring>
#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

int main() {
  int server_fd, new_socket, valread;
  sockaddr_in address;
  int opt = 1;
  int addrlen = sizeof(address);
  char buffer[1024] = {0};
  const char *response = "HTTP/1.1 200 OK\nContent-Length: 12\n\nHello, World";

  // Создание сокета
  if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
    perror("socket failed");
    exit(EXIT_FAILURE);
  }

  // Установка параметров сокета
  if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt,
                 sizeof(opt))) {
    perror("setsockopt");
    exit(EXIT_FAILURE);
  }

  // Установка адреса сервера и порта
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons(8080);

  // Привязка сокета к адресу и порту
  if (bind(server_fd, (sockaddr *)&address, sizeof(address)) < 0) {
    perror("bind failed");
    exit(EXIT_FAILURE);
  }

  while (true) {
    // Ожидание подключения клиента
    if (listen(server_fd, 3) < 0) {
      perror("listen");
      exit(EXIT_FAILURE);
    }

    // Принятие нового соединения
    if ((new_socket = accept(server_fd, (sockaddr *)&address,
                             (socklen_t *)&addrlen)) < 0) {
      perror("accept");
      exit(EXIT_FAILURE);
    }

    // Чтение HTTP-запроса от клиента
    valread = read(new_socket, buffer, 1024);
    printf("%s\n", buffer);

    // Отправка HTTP-ответа
    send(new_socket, response, strlen(response), 0);
    printf("Response sent\n");
  }
  return 0;
}
