#include "kernel/types.h"
#include "user/user.h"

int
main()
{
  int pid;
  int fd[2];
  int res = pipe(fd);
  if(res == -1){
    printf("open pipe on filaure!");
    exit(-1);
  }
  int *read_fd = &fd[0];
  int *write_fd = &fd[1];
  char str[] = "received ping";
  char read_buffer[100];
  write(*write_fd, str, strlen(str));  
  pid = fork();
  if(pid == 0){
    read(*read_fd, read_buffer, sizeof(read_buffer));
    printf("pid: %d, %s\n", getpid(),read_buffer);
    char send[] = "received pong";
    write(*write_fd, send, strlen(send));
    exit(0);
  }else {
    wait(&pid);
    read(*read_fd, read_buffer, sizeof(read_buffer));
    printf("pid: %d, %s\n", getpid(), read_buffer);
  }
  exit(0);
}
