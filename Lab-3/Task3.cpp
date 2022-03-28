#include <iostream>
#include <unistd.h>
using namespace std;
int main()
{
	int f;
	int number= rand();
	int rank = 0;
	for(int i = 1; i <= 3; ++i) 
	{
		if (fork() == 0)
		{
			rank = rank + i;
			break;
		}
	}
	

	if (rank==0)
	{
		printf("Process 1\n");
		int result = (rand() % (50 +1 -26) + 26);
   		printf("%d \n", result);	
   	}

   	else if (rank==1)
	{
		printf("Process 0\n");
		int result = (rand() % (25 +1 -1) + 1);
   		printf("%d \n", result);		
	}
	else if (rank==2)
	{
		printf("Process 3\n");
		int result = (rand() % (100 +1 -76) + 76);
   		printf("%d \n", result);	
	}
	else if (rank==3)
	{
   		printf("Process 2\n");
		int result = (rand() % (75 +1 -51) + 51);
   		printf("%d \n", result);		
	}

	exit(0);

}
