#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{
        int     fd[2], nbytes;
        pid_t   childpid;
        char    string[] = "Zainab Rizwan\n";
        char    s[] = "2019-CE-36\n";
        char    buffer[80];

        pipe(fd);
        
        if((childpid = fork()) == -1)
        {
           
                exit(1);
        }
        
	if ((childpid = fork()) > 0) {
        write(fd[1], string, (strlen(s)+1));
        
        
        }
        
        if(childpid == 0)
        {
              
                close(fd[0]);
                write(fd[1], s, (strlen(string)+1));
                exit(0);
        }
        
        else
        {
               
                close(fd[1]);
               while( nbytes = read(fd[0], buffer, sizeof(buffer))>0);
                printf("%s", buffer);
        }
        
        return(0);
      
}
