#include <stdio.h>
#include <unistd.h>
#define RED_BOLD "\x1b[;31;1m"
#define BLU_BOLD "\x1b[;34;1m"
#define YEL_BOLD "\x1b[;33;1m"
#define GRN_BOLD "\x1b[;32;1m"
#define CYAN_BOLD_ITALIC "\x1b[;36;1;3m"
#define RESET "\x1b[0;m"

int glo = 10;

int main(int argc, char *argv[])
{
    int loc = 10;

    printf(CYAN_BOLD_ITALIC"\n--------------------------------------------\n");
    printf("Global:%d\nLocal:%d\nPid:%d\n",glo,loc,getpid());
    printf("--------------------------------------------\n"RESET);

    pid_t new_pid;
    new_pid = fork();
    switch(new_pid)
    {
        case -1:
            printf(RED_BOLD"fork error!\n"RESET);   
            break;
        case 0: // create a child process
            printf(YEL_BOLD"\n----------------This is child process------------------\n");
            printf("Global:%d\nLocal:%d\nPid:%d\nParent Pid:%d\n",glo,loc,getpid(),getppid());
            glo++;
            loc++;
            printf("---------------------------------------------------------\n"RESET);
            printf("--------------------------------------------------------------------------------------------------\n");
            break;
        default:
            wait();
            break;
    }

    switch(new_pid)
    {
        case -1:
            printf(RED_BOLD"fork error!\n"RESET);   
            break;
        case 0: // create a child process
            printf(YEL_BOLD"\n----------------This is child process------------------\n");
            printf("Global:%d\nLocal:%d\nPid:%d\nParent Pid:%d\n",glo,loc,getpid(),getppid());
            printf("---------------------------------------------------------\n"RESET);
            break;
        default:
            printf(CYAN_BOLD_ITALIC"\n--------------------------------------------\n");
            printf("Global:%d\nLocal:%d\nPid:%d\nChild Pid:%d\n",glo,loc,getpid(),new_pid);
            printf("--------------------------------------------\n"RESET);
            wait();

            break;
    }


    return 0;
}
