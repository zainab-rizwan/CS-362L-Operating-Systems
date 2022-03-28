
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	ifstream var;
	string line;
	char filename[100], pattern[10];

	cout<<"Enter file name: \n";
	scanf("%s",filename);

	cout<<"Enter string to be searched: \n";
	scanf("%s",pattern);

	var.open(filename);
	
	if(var.is_open())
	{
		//read file contents
		while(getline(var, line))
		{
			//read and search all lines
			if (line.find(pattern) != std::string::npos) 
			{
      			  cout << "\nString found on this line: \n" << line << endl;
			}
		}
	}

	//close file
    	var.close();
}
