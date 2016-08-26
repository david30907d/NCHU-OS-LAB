#include <stdio.h>
#include <unistd.h>

#define RED_BOLD "\x1b[;31;1m"
#define BLU_BOLD "\x1b[;34;1m"
#define YEL_BOLD "\x1b[;33;1m"
#define GRN_BOLD "\x1b[;32;1m"
#define CYAN_BOLD_ITALIC "\x1b[;36;1;3m"
#define RESET "\x1b[0;m"


int main(int argc, char *argv[]){
    pid_t new_pid;
    new_pid = fork();

    if(new_pid < 0)
    {
        printf(RED_BOLD"fork error!\n"RESET);   
        return 0;

    }
    else if(new_pid == 0)
    {
        printf("\nC:%d\n",new_pid);
        printf(YEL_BOLD"\n----------------This is child process------------------\n");
        printf("Pid:%d\nParent Pid:%d\n",getpid(),getppid());
        printf("---------------------------------------------------------\n"RESET);
        return 0;
    } 
    else
    {
        printf("\nP:%d\n",new_pid);
        printf(CYAN_BOLD_ITALIC"\n----------------This is parent process-----------------\n");
        printf("Pid:%d\nChild Pid:%d\nParent Pid:%d\n",getpid(),new_pid,getppid());
        printf("---------------------------------------------------------\n"RESET);
        wait();
        return 0;

    }

    
    return 0;
}
