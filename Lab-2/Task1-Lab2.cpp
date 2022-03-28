#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
  
  
int main()
{
	
        if(fork() == 0)
        {

            printf("[grandparent] %d, [parent] %d\n",getppid(),getpid());
            if(fork() == 0)
	     {

		    printf("[parent] %d, [child] %d\n",getppid(),getpid());
		    if(fork() == 0)
		     {
			    printf("[grandparent] %d, [parent] %d\n",getppid(),getpid());
			    if(fork() == 0)
		     {
	   
	      }
   
        }
        else
        {
        	return 0;
        }
      
}


