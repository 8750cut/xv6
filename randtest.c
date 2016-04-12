#include "types.h"
#include "stat.h"
#include "user.h"

void
test()
{
  printf(1, "TESTING RANDOM\n");
  int i, j, k, x;
  int pass = 1;

  printf(1, "TESTING RANDOM WITH RANGE\n");
  for(i = 0, j = 400000; i < 200000; i+=100, j-=100)
  {
    printf(1, "FROM %d TO %d: ", i, j);

    for(k = 0; k < 200; k++)
    {
      x = random() % (j - i + 1) + i;
      if(x < i || x > j)
      {
        printf(1, "Failed.\nINVALID OUTPUT: %d\n", x);
        pass = 0;
      }
    }
    if(pass == 1)
      printf(1, "OK\n");
    k = 0;
    pass = 1;
  }
}

int
main()
{
  test();

  exit();
}
