#include "Utility.h"
#include <stdio.h>
#include <unistd.h>

#define BACKLOG 1

int main(int argc, char *argv[]) {

  struct sockaddr_un server_addr;
  int server_fd, client_fd;

  server_fd = socket(AF_UNIX, SOCK_STREAM, 0);
  if (server_fd == -1)
    errExit("Socket");

  setAddr(&server_addr, "/tmp/myfirstsocket");

  if (bind(server_fd, (struct sockaddr *)&server_addr,
           sizeof(struct sockaddr_un)) == -1)
    errExit("Bind");

  if (listen(server_fd, BACKLOG) == -1)
    errExit("Listen");

  printf("Server in UNIX domain listen...\n");

  while (1) {
    client_fd = accept(server_fd, NULL, NULL);

    if (client_fd == -1)
      errExit("Socket Client");

    printf("FD of client in server: %d\n", client_fd);

    if (close(client_fd) == -1)
      errExit("close");
  }

  return 0;
}
