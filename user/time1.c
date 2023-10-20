#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, char *argv[]){
        if (argc < 2) {
                printf("Usage: time1\n");
                exit(1);
        }
        int stime = uptime();
        int pid = fork();
        if(pid == 0){
                exec(argv[1], argv + 1);
                printf("Exec failed %s.\n", argv[1]);
                exit(1);
        } else if(pid >0) {

                int st;
                wait(&st);
                int etime = uptime();
                int eticks = etime - stime;
                printf("Elapsed time: %d ticks\n",eticks);
        }
        else{
                printf("Error");
        }
        exit(1);
}
