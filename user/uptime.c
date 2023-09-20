#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
//Franz Reyes hw1
int main(int argc, char *argv[]) {
	int ti;
	ti = uptime();
	printf("up %d clock ticks\n", ti);
	exit(0);
}
