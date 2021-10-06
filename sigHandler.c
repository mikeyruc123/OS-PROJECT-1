// Student name: Michael Rucando
// Ilab machine used: top.cs.rutgers.edu

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


void floating_point_exception_handler(int signum) {

	printf("I am slain!\n");

	/* Do your tricks here */

	unsigned int *sp;
	sp = &signum;
	
	//printf("address of signum is %p\n", sp);
	
	sp += (12*4)+3;
	
	*sp += 5;
	
	//printf("address of signum is %p\n", sp);
	

	
	

}

int main() {

	int x = 5, y = 0, z = 0;

	signal(SIGFPE, floating_point_exception_handler);

	z = x / y;

	printf("I live again!\n");

	return 0;
}

