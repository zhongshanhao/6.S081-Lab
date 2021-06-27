#include "types.h"
#include "sysinfo.h"

// 废弃 
struct sysinfo sysinfo = {0, 0};


struct sysinfo*
getsysinfo(void)
{
  return &sysinfo;
}

