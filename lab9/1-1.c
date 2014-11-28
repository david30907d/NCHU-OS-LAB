#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
        char k[50];
        pid_t pid;
        pid = fork();
        if(pid == 0)
        {
                printf("Child process.\n");
                printf("PID%d\n",getpid());
                for(;;);
        }
        wait(NULL);
        printf("Parent process.\n");
        printf("PID%d\n",getpid());



return 0;
}
