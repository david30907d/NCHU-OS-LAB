#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>


int main(void)
{
	FILE *cptr;
	int temp;
	printf("My real user id = %d\n",getuid());
	printf("My effective user id = %d\n",geteuid());
	cptr = fopen("datafile.txt", "a");
	if(cptr == NULL){
		printf("Can't open file.\n");
		return 0;
	} else {
		fprintf("My real user id = %d\n", getuid());
		fprintf("My effective user id = %d\n", geteuid());
		fclose(cptr);
	}

	return 0;
}
