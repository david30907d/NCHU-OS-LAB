#include <stdlib.h>
#include <stdio.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#define FILE_LENGTH 0x50

int main(int argc,char *argv[]){
        int fd,count;
        char ch[80] = {0};
        char *ca;
        void *file_memory;

        fd = open(argv[1],O_RDWR,S_IRUSR | S_IWUSR);
        lseek(fd,0,SEEK_SET);
        write(fd,ch,FILE_LENGTH);
        file_memory = mmap(0,FILE_LENGTH,PROT_WRITE,MAP_SHARED,fd,0);
        close(fd);
        printf("enter any message:\n");
        /*filter enter character.*/
        while(1){
                gets(ch);
                ca = file_memory;
                count = strlen(ca);
                sprintf((char*)(file_memory+count),"%s",ch);
        }

        /*just wait user input any character to close mmap.*/
        getchar();

        /*release the memory.*/
        munmap((char*)file_memory,FILE_LENGTH);
return 0;
}
