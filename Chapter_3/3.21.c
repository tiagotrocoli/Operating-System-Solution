
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>


int main(){

	int n;

	scanf("%d", &n);

	int pid = fork();

	if(pid == 0){

		printf("%d\n", n);

		do{

			if(n%2 == 0)
				n = n/2;
			else
				n = 3*n + 1;

			printf("%d\n", n);

		}while(n > 1);

		return 0;

	}else{
		wait(NULL);
	}

	return 0;
}
