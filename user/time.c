#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/param.h"
#include "kernel/pstat.h"
int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: time \n");
        exit(1);
    }
    int pid=fork();
    int sottime=uptime();
    if(pid==0){
       exec(argv[1], argv+1);
       printf("Error\n", argv[1]);
       exit(1);
    }
    else if(pid>0){
       int status;
       struct rusage ru;
       wait2(&status,&ru);
       int elatime=uptime();
       int elaticks=elatime-sottime;
       printf("Elapsed time %d ticks, CPU time: %d, CPU % %d \n", elaticks, ru.cputime,(ru.cputime*100)/elaticks);
       exit(0);
    }
    else{
       printf("Fork Error");
    }
    exit(0);
}
