#include "kernel/types.h"
#include "user/user.h"
 
int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: memory-user <start> <limit> <increment>, where <start> is initial and goes up to limit \n");

        exit(-1);

    }

    uint start = atoi(argv[1]);

    uint limit = atoi(argv[2]);

    uint increment = atoi(argv[3]);

    uint i;

    // uint j;

    int *array;

    for (i=start; i<=limit; i+=increment) {

	printf("allocating %p ", i); 

	array = (int *) malloc(i*1024*1024);

	printf("Returned %p\n", array);

        if (!array) {

            printf("Failed\n");

	    exit(-1);

        }

	sleep(50);

	printf("freeing %p ", i); 

	free(array);

	sleep(50);

    }
 
    exit(0);

}
