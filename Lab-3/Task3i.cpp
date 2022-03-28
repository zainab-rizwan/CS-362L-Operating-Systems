#include <stdio.h>
#include <sys/types.h> 
#include <unistd.h> 

int main()
{      
        int rank=0;
	for(int i=1;i<=2; i++)
	{	
	       if (fork() == 0)
	        {
		      rank = rank + i;
		      break;
	        }	        
	}
	
       if(rank==0)
       {
		for(int r=1; r<=25; r++)
		{
		    printf("%d\n",r);
		}		
	}
       if(rank==1)
       {	  
		for(int r=26; r<=50;r++)
		{
		    printf("%d\n",r);
		}		
	}
	if(rank==2)
	{
		for(int r=51;r<=100;r++)
		{
		    printf("%d\n",r);
		}	
	}
	if(rank==3)
	{
		for(int r=76;r<=100;r++)
		{
		    printf("%d\n",r);
		}	
	}
	
		
	return 0;	
}
