#include "kernel/types.h"
#include "user/user.h"
 
int main(void) {
    printf("Testing Memory Allocation");
    char *mem = malloc(4096);
    for (int i = 0; i < 4096; i++) {
        mem[i] = 'a';
    }
    free(mem);
    exit(-1);
}
