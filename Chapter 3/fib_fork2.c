#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/wait.h>

#define MAX_SEQUENCE 1000000

int main(){
	
	int n;
	int fd;
	long *ptr;
	const char *name = "OS";
	
	scanf("%d", &n);

	fd = shm_open(name, O_CREAT | O_RDWR, 0666);
	ftruncate(fd, MAX_SEQUENCE);	

	int pid = fork();

	if(pid == 0){
	
		int fib1 = 0;
		int fib2 = 1;		
		
		ptr = (long *) mmap(0, MAX_SEQUENCE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0 );
		
		ptr[0] = 0;
		ptr[1] = 1;

		for(int i=2;i<n;i++){
			
			long temp = fib2;
			fib2 	 = fib2 + fib1;
			fib1 	 = temp;			
			
			ptr[i]   = fib2;
		}
		

	}else{
		
		wait(NULL);
		
		ptr = (long *)mmap(0, MAX_SEQUENCE, PROT_READ, MAP_SHARED, fd, 0);
		
		for(int i=0;i<n;i++)
			printf("%ld\n", ptr[i]);

		shm_unlink(name);
	}

	return 0;
}
