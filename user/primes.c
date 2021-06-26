#include "kernel/types.h"
#include "user/user.h"

int is_prime(int num);

int
main()
{
  int pid;
  int fd[2];
  int r = pipe(fd);
  if(r == -1)
  {
    printf("create pipe on filaure!\n");
    exit(-1);
  }
  int nums[32];
  int len = 32;
  for(int i = 0; i < 32; i++)
  {
    nums[i] = i;
  }
  // write(fd[1], nums, len);
  // close(fd[1]);
  for(int i = 0; i < len; i++)
  {
    pid = fork();
    if(pid == 0)
    {
      if(is_prime(nums[i]) == 0)
        printf("%d\n", nums[i]);
    }else
    {
      wait(&pid);
      break;
    }
  }
  exit(0);
}

int is_prime(int num)
{
  for(int i = 2; i * i <= num; i++)
  { 
    if(num % i == 0)
      return -1; 
  }
  return 0;
}
