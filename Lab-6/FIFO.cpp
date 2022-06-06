#include<stdio.h>

int main()
{
	int i, j, pages, a[50], frame[10], frames, k, avail, count=0;
	
	//Getting inputs
	
	printf("Enter number of frames: ");
        scanf("%d",&frames);
	
	printf("Enter number of pages: ");
	scanf("%d",&pages);
	
        printf("Enter reference string: ");
        for(i=1; i<=pages; i++)
        {
        	scanf("%d",&a[i]);  
        } 
        
        //Setting frame values to -1
	for(i=0; i<frames; i++)
	{	
		frame[i]= -1;
		j=0;
	}
	
	
	printf("\nPage Frames\n");		
	for(i=1; i<=pages; i++)
	{

            avail=0;
            printf("Reference np%d->\t\t", a[i]);
            for(k=0; k<frames; k++)
            	//Reference page is present within frames
	   	if(frame[k]==a[i])
	        {     
	        	avail=1;
	        }
	        
	        //Reference page is not present within frames
	    	if (avail==0)
		{
			//Add page into frame
		        frame[j]=a[i];
		        //Update j
			j=(j+1) %frames;
			//Increment page count
			count++;
			for(k=0; k<frames; k++)
			{
				printf("%d\t",frame[k]);
			}
		}
		printf("\n");
	}
	
        printf("\nNumber of page faults: %d",count);
        printf("\n");
        return 0;
}
