#include "kernel/types.h"
#include "user/user.h"

int 
main(int argc, char *argv[])
{
  if(argc <= 1)
    fprintf(2, "at lease 1 augment\n");
  int time = atoi(argv[1]);
  sleep(time);
  exit(0);
}
