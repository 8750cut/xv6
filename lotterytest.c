#include "types.h"
#include "stat.h"
#include "user.h"

void
forktest(){
	printf(1, "starting fork test\n");
	// int i, j, k, n, pid, sum;

	int a[3][3], b[3][3], c[3][3];
	int i, j, k, n, pid, sum;

	for(i=1; i<=3; i++){
		for(j=i-1; j<=3; j++){
			a[i][j] = j;
			b[i][j] = j;
		}
	}

	// for(n=0; n<3; n++){
	//     pid = fork();
	//     if(pid < 0)
	//       break;
	//     if(pid == 0){
	//     	nice(n);
	//     	printf(1, "forked child %d with priorty %d\n", n, n);
	//     	for (i = 0; i < 3; i++) {
	// 		    for (j = 0; j < 3; j++) {
	// 		        sum = 0;
	// 		        for (k = 0; k < 3; k++) {
	// 		            sum = sum + a[i][k] * b[k][j];
	// 		        }
	// 		        c[i][j] = sum;
	// 		    }
	// 		    printf(1, "child %d row %d completed with values: %d %d %d\n", n, i, c[i][0], c[i][1], c[i][2]);
	// 	    }
	// 	    exit();
	//     }
	//   }
	for(n=0; n<3; n++){
	    pid = fork();
	    if(pid < 0)
	      	break;
	    if(pid == 0){
	    	nice(n);
	    	printf(1, "forked child %d with priorty %d\n", n, n);
	    	for (i = 0; i < 3; i++) {
			    for (j = 0; j < 3; j++) {
			        sum = 0;
			        for (k = 0; k < 3; k++) {
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