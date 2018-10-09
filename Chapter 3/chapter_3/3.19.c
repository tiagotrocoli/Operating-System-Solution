#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <time.h>

#define SIZE  sizeof(double)

int main(int argc, char *argv[]){

  const char *name = "OS";

  int pid = fork();

  if(pid == 0){

    int fd  = shm_open(name, O_CREAT | O_RDWR, 0666);
		ftruncate(fd, SIZE);
		double *time_taken  = (double *) mmap(0, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0 );

    clock_t t;

    t = clock();
    system(argv[1]);
    t = clock() - t;

    *time_taken = ((double)t)/CLOCKS_PER_SEC;

  }else{

    wait(NULL);

    int fd = shm_open(name, O_CREAT | O_RDWR, 0666);

		double *time_taken = (double *) mmap(0, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0 );

    printf("Elapsed time: %lf seconds\n",*time_taken);

  }

  return 0;
}
