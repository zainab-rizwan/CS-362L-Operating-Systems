#include <iostream>
#include <unistd.h>
using namespace std;
int main()
{
	int pid;
	pid= fork();
	if (pid==0)
	{
		cout << "\n Parent Process id: "
			<< getppid() <<endl;
		cout << "\n Child process with parent id: "
			<< getpid() << endl;

	}
	return 0;
}
