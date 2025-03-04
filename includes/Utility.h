#ifndef UTILITY_H
#define UTILITY_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/un.h>

int errExit(const char *c) {
  perror(c);
  exit(EXIT_FAILURE);
}

void setAddr(struct sockaddr_un *addr, char path[]) {

  memset(addr, 0, sizeof(struct sockaddr_un));

  addr->sun_family = AF_UNIX;
  strncpy(addr->sun_path, path, sizeof(addr->sun_path) - 1);
}

#endif // UTILITY_H
