#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void fine();
void original();

void how()
{
        printf("How are you!\n");
}

void change()
{
        signal(SIGINT,fine);
        signal(SIGALRM,original);
        alarm(3);
}

void fine()
{   
        printf("I'm fine.\n");
} 

void original()
{
        signal(SIGINT,SIG_DFL);
}

int main()
{
        signal(SIGINT,how);
        signal(SIGALRM,change);
        alarm(3);

        for(;;);

}
