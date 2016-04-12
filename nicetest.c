#include "types.h"
#include "stat.h"
#include "user.h"

void niceInput(int n){
  if((nice(n) == -1) && (nice(0) != -1)){
    printf(1, "invalid argument. Current nice value is: %d\n", n, nice(0));
    return;
  }
  printf(1, "nice(%d) value: %d\n", n, nice(0));
}

void
test()
{
  niceInput(0);
  niceInput(-1);
  niceInput(20);
  niceInput(5);
  niceInput(-50);
  niceInput(-25);

  int pid = fork();
  if(pid == 0){
	  printf(1, "forked child nice value: %d\n", nice(0));
    niceInput(-5);
    exit();
  }

  wait();

  printf(1, "parent's nice value: %d\n", nice(0));

  printf(1, "nice test OK\n");
}

int
main()
{
  test();

  exit();
}
