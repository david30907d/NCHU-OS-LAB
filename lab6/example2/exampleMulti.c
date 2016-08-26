#include <stdio.h>
#include <unistd.h>

#define RED_BOLD "\x1b[;31;1m"
#define BLU_BOLD "\x1b[;34;1m"
#define YEL_BOLD "\x1b[;33;1m"
#define GRN_BOLD "\x1b[;32;1m"
#define CYAN_BOLD_ITALIC "\x1b[;36;1;3m"
#define RESET "\x1b[0;m"


int main(int argc, char *argv[]){

    if(fork() == 0)
    {
        printf(YEL_BOLD"I'm child process 1\n");   
        printf("Pid:%d Parent Pid:%d\n"RESET,getpid(),getppid());
        return 0;
    }
    wait(NULL);
    
    if(fork() == 0)
    {
        printf(BLU_BOLD"I'm child process 2\n");   
        printf("Pid:%d Parent Pid:%d\n"RESET,getpid(),getppid());
        return 0;
    }

    wait(NULL);
    printf(CYAN_BOLD_ITALIC"I'm parent process\n");
    printf("Pid:%d Parent Pid:%d\n"RESET,getpid(),getppid());

    return 0;
}
