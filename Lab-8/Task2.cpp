#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
#include <semaphore.h>
#include <pthread.h>

int c, b, total= 0;

//declare semaphores
sem_t sem1;
sem_t sem2;
int Buffer[100];


void *Producer(void *)
{
    while (true)
    {
        sem_wait(&sem1);
        if (c < 100)
        {
		Buffer[c] = (rand() % 6) + 1;
		cout << "Producer: "<<Buffer[c] << endl;
		c++;
		}
        sem_post(&sem2);
    }
}

void *Consumer(void *)
{
    while (true)
    {
        sem_wait(&sem2);
        if (b < 100)
        {
        
		total = total+Buffer[b];
		cout <<"Consumer: "<< total << endl;
		b++;
        }
        sem_post(&sem1);
    }
}

int main()
{

    //declare thread
    pthread_t id1, id2;
    
    //initiate semaphore
    sem_init(&sem1, 0, 1);
    sem_init(&sem2, 0, 0);

    //create thread
    pthread_create(&id1, NULL, &Producer, NULL);
    pthread_create(&id2, NULL, &Consumer, NULL);

    //join threads
    pthread_join(id1, NULL);
    pthread_join(id2, NULL);
}
