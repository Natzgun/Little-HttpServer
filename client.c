#include "Utility.h"
#include <sys/socket.h>
#include <sys/un.h>

int main(int argc, char *argv[]) {
  struct sockaddr_un addr;
  int server_fd;

  server_fd = socket(AF_UNIX, SOCK_STREAM, 0);

  if (server_fd == -1)
    errExit("socket");

  setAddr(&addr, "/tmp/myfirstsocket");

  if (connect(server_fd, (struct sockaddr *)&addr,
              sizeof(struct sockaddr_un)) == -1)
    errExit("connect");

  printf("FD of client: %d\n", server_fd);

  return 0;
}
