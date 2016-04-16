#include "types.h"
#include "stat.h"
#include "user.h"

void
forktest(){
	printf(1, "starting fork test\n");
	// int i, j, k, n, pid, sum;

	int a[5][5], b[5][5], c[5][5];
	int i, j, k, n, z, pid, sum;

	for(i=1; i<=5; i++){
		for(j=i-1; j<=5; j++){
			a[i][j] = j;
			b[i][j] = j;
		}
	}

	for(n=0; n<5; n++){
	    pid = fork();
	    if(pid < 0)
	      	break;
	    if(pid == 0){
	    	if(n == 1)
	    		z = -19;
	    	else if(n == 2)
	    		z = 12;
	    	else
	    		z = n;

	    	nice(z);
	    	printf(1, "forked child %d with priorty %d\n", n, z);
	    	for (i = 0; i < 5; i++) {
			    for (j = 0; j < 5; j++) {
			        sum = 0;
			        for (k = 0; k < 5; k++) {
			            sum = sum + a[i][k] * b[k][j];
			        }
			        c[i][j] = sum;
			    }
			    printf(1, "child %d row %d completed with values: %d %d %d\n", n, i, c[i][0], c[i][1], c[i][2]);
		    }
	    	exit();
	    }
	}
	  
	for(; n > 0; n--){
	    wait();
	}

	printf(1, "fork test OK\n");
}

int 
main()
{
	forktest();
	
	exit();
}