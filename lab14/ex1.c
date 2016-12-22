#include <stdlib.h>
#include <stdio.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#define FILE_LENGTH 0x50

int main(int argc, char *argv[]){

  int fd, count;
  char ch[80] = {0};
//  char *ca;
  void *file_memory;

  fd = open(argv[1], O_RDWR, S_IRUSR | S_IWUSR);

  lseek(fd, 1, SEEK_SET);       //偏移檔案的起始位置1 byte，ref: http://blog.xuite.net/lidj37/twblog/179517548-lseek+function
  write(fd, "", FILE_LENGTH);   //寫入空的內容到szie=80byte的file
        
  file_memory = mmap(0, FILE_LENGTH, PROT_WRITE, MAP_SHARED, fd, 0);

  close(fd);

  count = strlen(file_memory);
  printf("count1: %d\n",count); //因為先偏移一個byte，所以會先印出1
        
  printf("Enter any character:\n");
  while(1 && count <= 80){
    gets(ch);
    //ca = file_memory;
    //count = strlen(ca);
    count = strlen(file_memory);
    sprintf((char*)(file_memory+count),"%s",ch);
    
    count = strlen(file_memory);
    printf("count2: %d\n",count);

  }


  munmap((char*)file_memory, FILE_LENGTH);

  return 0;
}
