#include "Utility.h"
#include <stdio.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

#define BUF_SIZE 100

int main(int argc, char *argv[]) {
  char buff[BUF_SIZE];
  struct sockaddr_un addr;
  int sock_fd;

  sock_fd = socket(AF_UNIX, SOCK_STREAM, 0);

  if (sock_fd == -1)
    errExit("socket");

  setAddr(&addr, "/tmp/myfirstsocket");

  if (connect(sock_fd, (struct sockaddr *)&addr, sizeof(struct sockaddr_un)) ==
      -1)
    errExit("connect");

  printf("FD of client in client: %d\n", sock_fd);

  while (1) {
    printf("client: ");
    fgets(buff, BUF_SIZE, stdin);
    write(sock_fd, buff, BUF_SIZE);
  }

  return 0;
}
