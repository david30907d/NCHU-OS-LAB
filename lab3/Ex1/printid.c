/*
	Step1.
		Change user to "root"
	Step2.
		compile print.c
	Step3.
		chmod 4755 ./a.out     4的意思是rw"s"
	Step4.
		在root下執行./a.out
		會產生  ruid:0
				euid:0
	Step5.
		回到一般使用者然後執行./a.out
		會看到	ruid:1000
				euid:0

		若有seteuid(500) 這行，代表會看到
				ruid:1000
				euid:500
*/


#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
	int ruid = getuid();
	// 強制將effective uid設成500
	//seteuid(500);

	int euid = geteuid();
	
	printf("RUID: %d\n",ruid);
	printf("EUID: %d\n",euid);


	return 0;
}
