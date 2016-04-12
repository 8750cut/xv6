#include "param.h"
#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"
#include "fcntl.h"
#include "syscall.h"
#include "traps.h"
#include "memlayout.h"

// checks to see if child and parent get and can write to the same file descriptor
void
childwrite(void){
	int fd, pid;

	printf(1, "childwrite test\n");

    fd = open("childtest", O_CREATE|O_RDWR);

    pid = fork();
    
    if(pid == 0){
    	if(write(fd, "child ", 6) != 6)
    		printf(1, "childwrite failed\n");
    	exit();
    }

    wait();
    if(write(fd, "test\n", 5) != 5){
    	printf(1, "childwrite failed\n");
    	exit();
    }

    close(fd);
  
  	printf(1, "childwrite test OK\n");
}

int
main(void)
{
  childwrite();
  exit();
}
