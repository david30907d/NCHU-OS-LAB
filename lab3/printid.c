#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

	printf("Real	UID = %d\n",getuid());
	seteuid(0);
	printf("Effective UID = %d\n",geteuid());

	return 0;
}
