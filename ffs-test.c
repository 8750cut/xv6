#include "types.h"
#include "stat.h"
#include "user.h"

#define SIZE 7461

int
main()
{
	printf(1, "ffs test\n");

	if(mkdir("ffstest") < 0) {
		printf(1, "mkdir ffs test failed\n");
		exit();
	}
	if(chdir("ffstest") < 0) {
		printf(1, "chdir ffs test failed\n");
		exit();
	}

	printf(1, "ffs test OK\n");

	exit();
}
