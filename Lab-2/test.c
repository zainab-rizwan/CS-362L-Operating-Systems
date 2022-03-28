#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	printf("Child task in test.c with id %d\n", getpid());
	FILE *fptr;
	char c;
	
	if ((fptr = fopen("data.txt","r")) == NULL)
	{
      		 printf("Error! opening file");
     		 exit(1);
  	}
  	else
  	{
		c=fgetc(fptr);
		while(c!=EOF)
		{
			printf("%c",c);
			c=fgetc(fptr);
		}
	}
	fclose(fptr);
	exit(1);
}



