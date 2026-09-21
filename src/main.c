#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include "treenity.h"

void handler(int sig)
{
  (void)sig;
  unlink("treenity");
  printf("exotting..\n");
  exit(0);
}

int main(void)
{
  struct sigaction sa = {0};
  sa.sa_handler = &handler;
  sigaction(SIGINT, &sa, NULL);
  sigaction(SIGTERM, &sa, NULL);

  int i = 0;
  while (1)
    printf("Hello, World!: %i\r", i++);
  return (0);
}
