#include <iostream>
using namespace std;
#include <semaphore.h>
#include <pthread.h>

sem_t sem1;
sem_t sem2;
sem_t sem3;

void* func1(void *)
{
   while (true)
    {
      sem_wait(&sem1);
        cout<<"c";
      sem_post(&sem2);
    }
}
void* func2(void *)
{  
   while (true)
    {
      sem_wait(&sem2);
        cout<<"b";
      sem_post(&sem3);
    }

}

void* func3(void *)
{  
   while (true)
    {
      sem_wait(&sem3);
        cout<<"a\n";
      sem_post(&sem1);
    }

}




int main()
{
    //declare threads
    pthread_t id1, id2, id3;
    
    //initialise semaphores
    sem_init(&sem1, 0, 1);
    sem_init(&sem2, 0, 0);
    sem_init(&sem3, 0, 0);

    //create threads
    pthread_create(&id1, NULL, &func1, NULL);
    pthread_create(&id2, NULL, &func2, NULL);
    pthread_create(&id3, NULL, &func3, NULL);
	
    //join
    pthread_join(id1, NULL);
    pthread_join(id2, NULL);
    pthread_join(id3, NULL);

}

