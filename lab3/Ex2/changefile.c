#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>


int main(void)
{
	FILE *cptr;
	printf("My real user id = %d\n",getuid());
	printf("My effective user id = %d\n",geteuid());
	// seteuid(0);
	cptr = fopen("datafile.txt", "a");
	if(cptr == NULL){
		printf("Can't open file.\n");
		return 0;
	}
	fprintf(cptr,"My real user id = %d\n", getuid());
	fprintf(cptr,"My effective user id = %d\n", geteuid());
	fclose(cptr);

	return 0;
}
