#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
bool isPrime(int num)
{
	if (num == 1)
	{
		return true;
	}
	else
	{
		double result;
		int divisor = num - 1;
		while (num != -1)
		{
			result = num % divisor;
			if (result == 0)
			{
				num = -1;
			}
			else
			{
				divisor = divisor - 1;
			}
		}

		if (divisor == 1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

int main()
{
    int rank = 0;
    int pid1, pid2, pid3, pid4, count_0;

    //rank
    for (int i=1; i<=2; ++i)
    {
        pid1=fork();
        if (pid1==0)
        {
            count_0=0;
            for ( int i=2; i<=25001; ++i)
	    {
		if (isPrime(i))
		{
			count_0++;
		}	
	    }	
	    printf("Prime numbers between 2 and 25001: %d\n",(count_0));	
            rank=rank+i;
            break;
        }
        else
        {
            pid3=fork();
		 if (pid3==0)
		 {
		 	count_0=0;
		    	for ( int i=50002; i<=75001; ++i)
			{
				if (isPrime(i))
				{
					count_0++;
				}	
			}	
			printf("Prime numbers between 50002 and 75001: %d\n",(count_0));
			rank=rank+i;
			break;
		 }
            else
            {
                   pid2=fork();
		    if (pid2==0)
		    {
		        count_0=0;
		    	for ( int i=25002; i<=50001; ++i)
			{
				if (isPrime(i))
				{
					count_0++;
				}	
			}	
			printf("Prime numbers between 25002 and 50001: %d\n",(count_0));
		        rank=rank+i;
		        break;
		    }

                else
                {
                     	 pid4=fork();
			 if (pid4==0)
			 {
			 	count_0=0;
			    	for ( int i=75002; i<=100001; ++i)
				{
					if (isPrime(i))
					{
						count_0++;
					}	
				}	
				printf("Prime numbers between 75002 and 100001: %d\n",(count_0));
				rank=rank+i;
				break;
			 }
                }
            }

            return 0;
        }
    }
}
