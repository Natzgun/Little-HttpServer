#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>

int errExit(const char *c) {
  perror(c);
  exit(EXIT_FAILURE);
}

void setAddr(struct sockaddr_un *addr) {

  memset(addr, 0, sizeof(struct sockaddr_un));

  addr->sun_family = AF_UNIX;
  strncpy(addr->sun_path, "/tmp/myserversocket", sizeof(addr->sun_path) - 1);
}

int main(int argc, char *argv[]) {

  struct sockaddr_un server_addr;
  int server_fd;

  server_fd = socket(AF_UNIX, SOCK_STREAM, 0);
  if (!server_fd)
    errExit("Error: Socket");

  setAddr(&server_addr);

  if (!bind(server_fd, (struct sockaddr *)&server_addr,
            sizeof(struct sockaddr_un)))
    errExit("Error: bind");

  return 0;
}
