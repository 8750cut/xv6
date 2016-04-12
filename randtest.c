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
  for(i = 0, j = 4000; i < 2000; i+=100, j-=100)
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

  int indexes[100];

  printf(1, "TESTING DISTRIBUTION FROM 0 TO 50\n");
  for(i = 0; i < 100; i++)
  {
    indexes[i] = 0;
  }

  int min = 0, max = 100;
  for(i = 0; i < 10000; i++)
  {
    x = random() % 50;
    if(x < min || x > max)
    {
      printf(1, "INVALID OUTPUT: %d\n", x);
      break;
    }
    indexes[x]++;
  }


  int index = 0;
  while(index < 50)
  {
    printf(1, "indexes[%d] = %d\n", index, indexes[index]);
    index++;
  }
}

int
main()
{
  test();

  exit();
}
