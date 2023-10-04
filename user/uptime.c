//Franz Reyes uptime	
//References include for system info 
#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
//main takes two parameters
int main(int argc, char *argv[]) {
	//declares int ti and assigns result of uptime to ti
	int ti;
	ti = uptime();
	//print of num of ticks
	printf("up %d clock ticks\n", ti);
	exit(0);
}
