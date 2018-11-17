#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/wait.h>

#define MAXSIZE 100

int main(){

	int n;
	int i = 0;
	const char *name = "OS";

	scanf("%d", &n);

	int pid = fork();

	if(pid == 0){

		int fd = shm_open(name, O_CREAT | O_RDWR, 0666);
		ftruncate(fd, MAXSIZE);
		int *ptr = (int *) mmap(0, MAXSIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0 );

		ptr[i++] = n;

		do{

			if(n%2 == 0)
				n = n/2;
			else
				n = 3*n + 1;

			ptr[i++] = n;

		}while(n > 1 && i < MAXSIZE-1);

		ptr[i] = -1;

	}else{

		wait(NULL);

		int fd 		= shm_open(name, O_CREAT | O_RDWR, 0666);
		int *ptr 	= (int *) mmap(0, MAXSIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0 );

		printf("%d: %d\n",0, ptr[0]);

		while(ptr[i] != -1){
			printf("%d: %d\n",i, ptr[i]);
			++i;
		}

		shm_unlink(name);
	}

	return 0;
}
