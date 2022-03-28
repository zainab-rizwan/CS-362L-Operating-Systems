#include <iostream>
#include <unistd.h>
using namespace std;
int main()
{


	for (int i = 0; i < 2; i++)
	{
		fork();
		//cout << "Hello from the process " << getpid() <<" parent id"<< getppid() << endl;
		//Process will run 4 times
	}
	cout << "Hello from the process " << getpid() <<" parent id: "<< getppid() << endl;

}
