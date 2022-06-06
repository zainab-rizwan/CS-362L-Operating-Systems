#include<stdio.h>
 
//Function to find LRU
int findLRU(int time[], int n)
{
    int i, minimum= time[0], pos= 0;
    for(i= 1; i< n; i++)
    {
    	//Check for LRU value
        if(time[i]< minimum)
        {
            minimum = time[i];
            //Determine frame position
            pos = i;
        }
    }  
    return pos;
}
 
int main()
{
    int no_of_frames, no_of_pages, frames[10], pages[30], counter = 0, time[10], flag1, flag2, i, j, pos, count = 0;
    
    //Getting inputs
    printf("Enter number of pages: ");
    scanf("%d", &no_of_pages);
    
    printf("Enter reference string: "); 
    for(i = 0; i< no_of_pages; i++)
    {
        scanf("%d", &pages[i]);
    }
    
     printf("Enter number of frames: ");
     scanf("%d", &no_of_frames);
    
    //Setting frame values to -1
    for(i = 0; i< no_of_frames; i++)
    {
        frames[i] = -1;
    }
    
    //Traversing
    printf("\nPage Frames\n");	
    for(i= 0; i<no_of_pages; i++)
    {
    	 printf("\nReference np%d->\t\t", pages[i]);
        flag1= flag2= 0;
        for(j= 0; j< no_of_frames; j++)
        {
            //Reference page is present within frames
            if(frames[j] == pages[i])
            {
                counter++;
                //Increment counter and set value in time array to keep track
                time[j]= counter;
          	 flag1= flag2= 1;
          	 break;
            }
        }
        
        //Reference page is not present within frames
        if(flag1== 0)
        {
            for(j= 0; j< no_of_frames; ++j)
            {
                //Insert page if empty frame is present
                if(frames[j]== -1)
                {
                    counter++;
                    //Increment page fault
                    count++;
                    //Add page into frame
                    frames[j]= pages[i];
                    //Increment counter and set value in time array to keep track
                    time[j]= counter;
                    flag2= 1;
                    break;
                }
            }    
        }
        
        //Reference page is not present within frames 
        //Page replacement is required because no empty frame is present
        if(flag2== 0)
        {
            //Find Least Recently Used page frame
            pos= findLRU(time, no_of_frames);
            counter++;
            //Increment page fault
            count++;
            //Insert new page at acquired frame position
            frames[pos] = pages[i];
            time[pos] = counter;
        }

        
        for(j= 0; j< no_of_frames; j++)
        {
            printf("%d\t",frames[j]);
        }
    }
    
    printf("\nNumber of page faults: %d",count);
    printf("\n");
    
    return 0;
}
