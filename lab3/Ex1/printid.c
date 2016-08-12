/*
	Step1.
		Change to "root"
	Step2.
		compile this file
	Step3.
		Change back to your user and run it.

*/


#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
	int ruid = getuid();
	int euid = seteuid(geteuid());

	printf("RUID: %d\n",ruid);
	printf("EUID: %d\n",euid);


	return 0;
}
