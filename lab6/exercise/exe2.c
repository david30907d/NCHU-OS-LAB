#include <stdio.h>
#include <unistd.h>
#define RED_BOLD "\x1b[;31;1m"
#define BLU_BOLD "\x1b[;34;1m"
#define YEL_BOLD "\x1b[;33;1m"
#define GRN_BOLD "\x1b[;32;1m"
#define CYAN_BOLD_ITALIC "\x1b[;36;1;3m"
#define RESET "\x1b[0;m"

int main(int argc, char *argv[])
{
    printf("I'm parent process A.\n");
    printf("PID: %d\tParent PID: %d\n",getpid(),getppid());

    // create process B
    if(fork() == 0)
    {
        // create process C
        if(fork() == 0)
        {
            printf(RED_BOLD"I'm child process C.\n");
            printf("PID: %d\tParent PID: %d\n"RESET,getpid(),getppid());
            return 0;
        }
        wait();

        printf(YEL_BOLD"I'm child process B.\n");
        printf("PID: %d\tParent PID: %d\n"RESET,getpid(),getppid());
        return 0;
    }
    wait();
    // create process D
    if(fork() == 0)
    {
        printf(YEL_BOLD"I'm child process D.\n");
        printf("PID: %d\tParent PID: %d\n"RESET,getpid(),getppid());
        return 0;
    }
    wait();
    // create process E
    if(fork() == 0)
    {
        printf(YEL_BOLD"I'm child process E.\n");
        printf("PID: %d\tParent PID: %d\n"RESET,getpid(),getppid());
        return 0;
    }
    wait();

    // printf(GRN_BOLD"I'm parent process A.\n");
    // printf("PID: %d\tParent PID: %d\n"RESET,getpid(),getppid());

    return 0;
}
