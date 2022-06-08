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





// main function
int main()
{

    int max, k=0;
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

    }
   
    for(int i=1; i<num; i++)
    {
        for(int j=i+1; j<num; j++)
        {
            //remove distinct
            if(arr[i] == arr[j])
            {
                arr[k] >> arr[i];
                num--;
                j--;
            }
        }
        
        

    }
    

//Exiting after completion
return 0;
}
