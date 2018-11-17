
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
	
	int n;

	scanf("%d", &n);	
	
	int pid = fork();

	if(pid == 0){
		
		int fib1 = 0;
		int fib2 = 1;		
		
		printf("0\n");
		printf("1\n");

		for(int i=2;i<n;i++){
			
			int temp = fib2;
			fib2 	 = fib2 + fib1;
			fib1 	 = temp;			
			
			printf("%d\n", fib2);
		}
	}else{
		wait(NULL);
		printf("Child completed.\n");
	}

	return 0;
}
