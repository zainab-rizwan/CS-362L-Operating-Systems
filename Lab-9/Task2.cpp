#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>

sem_t sem1;
sem_t sem2;

void *Producer(void *)
{
    while (true)
    {
        sem_wait(&sem1);
        cout<< "Producer"<<endl;
        sleep(2);
	
        sem_post(&sem2);
    }
}

void *Consumer(void *)
{
    while (true)
    {
        sem_wait(&sem2);
        
        cout<< "Consumer"<<endl;
         sleep(2);
        sem_post(&sem1);
    }
}

int main()
{

    pthread_t id1, id2;
    sem_init(&sem1, 0, 1);
    sem_init(&sem2, 0, 0);

    pthread_create(&id1, NULL, &Producer, NULL);
    pthread_create(&id2, NULL, &Consumer, NULL);

    pthread_join(id1, NULL);
    pthread_join(id2, NULL);
}

