#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include <time.h>

void sfile(char const filename[]);

int main()
{
  ssize_t read;
  char* buffer = 0;
  size_t buf_size = 0;

  //--1-Get file
  printf("Enter the name of a file to check: \n");
  read = getline(&buffer, &buf_size, stdin);

  if (read <=0 )
  {
    printf("getline failed\n");
    exit(1);
  }

  if (buffer[read-1] == '\n'){
  
    buffer[read-1] = 0;
  }

  
  int s=open(buffer,O_RDONLY);
  if(s==-1)
  {
    printf("File doesn't exist\n");
    exit(1);
  }
  else
  {
    sfile(buffer);
  }
  free(buffer);
  return 0;
}

void sfile(char const filename[])
{
  struct stat sfile;
  struct tm dt;
  //--2-call stat
  //stat unsuccessfull
  if(stat(filename,&sfile)==-1)
  {
    printf("Error Occurred\n");
  }

  //--3-Displaying members
  printf("\nFile st_uid %d \n",sfile.st_uid);
  printf("\nFile st_blksize %ld \n",sfile.st_blksize);
  printf("\nFile st_blocks %ld \n",sfile.st_blocks);
  printf("\nFile st_size %ld \n",sfile.st_size);
  printf("\nFile st_nlink %u \n",(unsigned int)sfile.st_nlink);
  
  //--4-Convert time
  dt = *(gmtime(&sfile.st_atime));
  printf("\nCreated on: %d-%d-%d %d:%d:%d", dt.tm_mday, dt.tm_mon, dt.tm_year + 1900, dt.tm_hour, dt.tm_min, dt.tm_sec);
           
  dt = *(gmtime(&sfile.st_mtime));
  printf("\nModified on: %d-%d-%d %d:%d:%d", dt.tm_mday, dt.tm_mon, dt.tm_year + 1900, dt.tm_hour, dt.tm_min, dt.tm_sec);
  
  //--5-Compare st_mode with mode constants


}
