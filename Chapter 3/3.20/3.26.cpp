#include <iostream>
#include <string>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>

#define BUFFER_SIZE 25
#define READ_END 0
#define WRITE_END 1

using namespace std;

int main(void){
    
    int fd[2];
    pid_t pid;
    
    pipe(fd);
    
    pid = fork();
    
    if(pid > 0){
        
        char msn_write[BUFFER_SIZE];
        char msn_read[BUFFER_SIZE];
        
        fgets(msn_write, BUFFER_SIZE, stdin);
        
        write(fd[WRITE_END], msn_write, strlen(msn_write));
        close(fd[WRITE_END]);
        
        wait(NULL);
        
        read(fd[READ_END], msn_read, BUFFER_SIZE);
        close(fd[READ_END]);
        
        printf("%s", msn_read);
        
    }else{
        
        char msn_write[BUFFER_SIZE];
        char msn_read[BUFFER_SIZE];
        
        read(fd[READ_END], msn_read, BUFFER_SIZE);
        close(fd[READ_END]);
        
        int n = strlen(msn_read);
        
        for(int i=0;i<n;i++){
            
            char ch = msn_read[i];
            
            if(ch >= 'a' && ch <= 'z')
                msn_write[i] = ch - 32;
            else if(ch >= 'A' && ch <= 'Z')
                msn_write[i] = ch + 32;
        }
        
        write(fd[WRITE_END], msn_write, strlen(msn_write)+1);
        close(fd[WRITE_END]);
        
        exit(1);
    }
    
    return 0;
}

