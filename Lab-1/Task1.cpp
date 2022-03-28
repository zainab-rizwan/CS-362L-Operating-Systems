
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream var;
    string line;
    int num;
    char filename[100];
    
    cout<< "How many files do you want to open? \n";
    scanf("%d", &num); 
    cout << "Enter file name: \n";
    
    while(num)
    {
	    scanf("%s", filename); 
	    var.open(filename);
	
	    if(var.is_open())
	    {
	        //read file contents
	        while(getline(var, line))
	        {
	            //print line
	            cout << line << endl;
	        }     
	    //close file
	    var.close();
	    num--;
	    }
	    
	    else
	    {
	        cout << "Unable to open the file";
	    }    
	    
	}	

    return 0;
}
