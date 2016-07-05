#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	//current user id
	int ruid = getuid();
	//effective user id
	int euid = geteuid();
	int s = setuid(euid);	
	if(s == 1){
		printf("Error\n");
	} else if(s == 0 ){
		printf("set successfully!\n");
		printf("E = %d\n",geteuid());
	}

	return 0;
}
