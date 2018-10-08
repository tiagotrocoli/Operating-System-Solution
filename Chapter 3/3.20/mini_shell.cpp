#include <iostream>
#include <string>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>


#define MAX_LINE 80

using namespace std;

void execute(const char *str){
    
    int pid = fork();
            
    if(pid == 0){
                
        system(str);
        exit(1);
            
    }else
        wait(NULL);
    
}

int main(void){
	
	char saved[MAX_LINE];
	bool should_run = true;

	while(should_run){
	    
	    char args[MAX_LINE];
	    
		printf("osh> ");
		
		cin.getline(args, MAX_LINE);
        
		if(strcmp(args,"exit") == 0){
		    
		    should_run = false;
		
		}else if(strcmp(args,"!!") == 0){
		    
		    execute(saved);
		
		}else{
		    
		    strcpy(saved, args);
		    
		    execute(args);
		    
        	}
	}

	return 0;
}

