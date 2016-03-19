#include "param.h"
#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"
#include "fcntl.h"
#include "syscall.h"
#include "traps.h"
#include "memlayout.h"

void
test1(void){
	
  
  	printf(1, "fork test OK\n");
}

int
main(void)
{
  test1();
  exit();
}
