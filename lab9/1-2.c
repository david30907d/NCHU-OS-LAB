#include <stdio.h>
#include <sys/wait.h>

int main()
{ 
        char k[50]; 
        pid_t pid;
        pid = fork(); 
        if(pid == 0)
        {
                printf("Child process");
                printf("PID:%d\n",getpid());
        }
        gets(k);
        kill(pid,SIGKILL);
        printf("Parent process.\n"); 
        printf("PID:%d",getpid());
        printf("Papa has killed its child.\n");
    
    
return 0; 
}
