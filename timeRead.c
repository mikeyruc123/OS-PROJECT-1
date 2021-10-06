#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>
#include <fcntl.h>

// Place any necessary global variables here

int fd;

int main(int argc, char *argv[]){

	struct timeval t1;
	struct timeval t2;
	struct timeval result;
	double average = 0;

	fd = open("file", O_WRONLY);

	if (fd == -1){
		printf("Error: No file present");
		exit(-1);
	}

	for (int i = 0; i < 128000; i++){
		gettimeofday(&t1, NULL);
		read(fd, NULL, 4096);
		gettimeofday(&t2, NULL);
		timersub(&t2, &t1, &result);
		average += ((result.tv_usec) - average)/(i+1);
	}

	printf("The resulting average over 128,000 iterations is: %f Microseconds", average);

	return 0;

}
