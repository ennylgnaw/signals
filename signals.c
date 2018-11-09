#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>

static void sighandler(int signo) {
  if (signo == SIGINT) {
    int fd = open("sigerr.txt", O_WRONLY | O_APPEND | O_CREAT, 0777);
    write(fd, "Program exited due to SIGINT\n", 30);
    close(fd);
    exit(0);
  }

  else if (signo == SIGUSR1)
    printf("The parent process PID is: %d\n", getppid());
}

int main() {
  signal(SIGINT, sighandler);
  signal(SIGUSR1, sighandler);
  
  while(1) {
    printf("The process PID is: %d\n", getpid());
    sleep(1);
  }

  return 0;
}
