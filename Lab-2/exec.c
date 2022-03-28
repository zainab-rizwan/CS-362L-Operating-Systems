
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


int childtask()
{
	printf("Child function exec.c with id %d\n", getpid());
	char *args[]={"./test"};
	execvp(args[0]);
	printf("back in exec.c\n");
	return 0;

}

int main(int argc,char *argv[])
{
	int pid;
	pid= fork();
	if (pid==0)
	{
		childtask();

	}
	else if (pid>0)
	{
		printf("Parent Task: ");
		return 0;
	}
	else if (pid==-1)
	{
		printf("Process creation unsuccessful\n");
		return 0;

	}
	return 0;

}
