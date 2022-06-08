#include <iostream>
#include <iostream>
#include <string.h>
#include <unistd.h>  
#include <pthread.h>
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
using namespace std;


void* func1(void*)
{
    int max=0;
    sleep(1);   
    int arr[100];
    ifstream file;
    string line;
    //open file
    file.open("f1.txt");
       if(file.fail()) 
      {
        cout << "Error" << endl;
        exit(1);
      }
      
    int num=44;
    //store file contents in array
    cout << "File 1 contents" << endl;
    for(int a = 1; a < 44; a++) 
    {
        file >> arr[a];
        cout << arr[a] <<"\n";

    }
   
    for(int i=1; i<num; i++)
    {
        for(int j=i+1; j<num; j++)
        {
            if(arr[i] != arr[j])
            {
                for(int k=j; k<num; k++)
                {
                    arr[k] = arr[k-1];
                }
                

                num--;

                j--;
            }
        }

    }
 
 
    
    for(int i=1; i<num; i++)
    {
        max+=arr[i];
    }
    
    int *result=new int; 
    *result=max/21;
    pthread_exit((void*) result);
}

void* func2(void*)
{
    int max=0;
    sleep(1);   
    int arr[100];
    ifstream file;
    string line;
    //open file
    file.open("f2.txt");
       if(file.fail()) 
      {
        cout << "Error" << endl;
        exit(1);
      }
      
    int num=44;
    //store file contents in array
    cout << "File 1 contents" << endl;
    for(int a = 1; a < 44; a++) 
    {
        file >> arr[a];
        cout << arr[a] <<"\n";

    }
   
    for(int i=1; i<num; i++)
    {
        for(int j=i+1; j<num; j++)
        {
            if(arr[i] != arr[j])
            {
                for(int k=j; k<num; k++)
                {
                    arr[k] = arr[k-1];
                }
                

                num--;

                j--;
            }
        }

    }
 
   
    
    for(int i=1; i<num; i++)
    {
        max+=arr[i];
    }
    
    int *result=new int; 
    *result=max/21;
    pthread_exit((void*) result);
}


// main function
int main()
{
    //Step 1: thread for f1.txt
    pthread_t t1[2];	
    	int* status;
        //Create thread function
        pthread_create(&t1[1], NULL, &func1, NULL); 
        // Joining threads, main thread waits for child thread to complete
        
        int *res;
        pthread_join(t1[1],(void**)&res);
  		cout<<"Thread 1: average "<<*res<<endl;
  		
  	pthread_create(&t1[2], NULL, &func2, NULL); 
        // Joining threads, main thread waits for child thread to complete
        

        pthread_join(t1[2],(void**)&res);
  		cout<<"Thread 2: average "<<*res<<endl;				
				

        //Create thread function
      
	
//Exiting after completion
return 0;
}
