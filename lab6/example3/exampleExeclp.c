/*Reference: http://stackoverflow.com/questions/15183427/getpid-and-getppid-returns-two-different-values*/

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

	switch(new_pid)
	{
		case -1:
			printf(RED_BOLD"fork error!\n"RESET);	
			break;
		
		case 0: //child process enters this block, fork successfully
			execlp("/bin/ls", "ls", "-l", NULL);
			break;
		default: //parent process enters this block
        	wait();
			printf(CYAN_BOLD_ITALIC"\n----------------This is parent process-----------------\n");
			printf("Pid:%d\nChild Pid:%d\n",getpid(),new_pid);
			printf("---------------------------------------------------------\n"RESET);
			break;

	}
	return 0;
}
