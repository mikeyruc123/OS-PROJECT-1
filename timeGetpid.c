#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

// Place any necessary global variables here


int main(int argc, char *argv[]){

	// run getPid() 100,000 times; average out

	struct timeval t1;
	struct timeval t2;
	struct timeval result;
	double average = 0;

	for (int i = 0; i < 100000; i++){

		gettimeofday(&t1, NULL);

		getpid();

		gettimeofday(&t2, NULL);

		timersub(&t2, &t1, &result);

		average += ((result.tv_usec) - average)/(i+1);

	}

	printf("The resulting average over 100,000 iterations is: %f Microseconds", average);

	return 0;

}
