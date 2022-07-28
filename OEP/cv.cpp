
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>

pthread_mutex_t m =			PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t smoker =		PTHREAD_MUTEX_INITIALIZER;

//actors
pthread_cond_t agent_c =		PTHREAD_COND_INITIALIZER;
pthread_cond_t smoker_tobacco_c =	PTHREAD_COND_INITIALIZER;
pthread_cond_t smoker_match_c =	PTHREAD_COND_INITIALIZER;
pthread_cond_t smoker_paper_c =	PTHREAD_COND_INITIALIZER;

//resource
pthread_cond_t tobacco =	PTHREAD_COND_INITIALIZER;
pthread_cond_t paper =		PTHREAD_COND_INITIALIZER;
pthread_cond_t match =		PTHREAD_COND_INITIALIZER;

int have_tobacco = 0;
int have_paper = 0;
int have_match = 0;

int agent_job = 1;			
int smoker_tobacco_job = 0;
int smoker_match_job = 0;
int smoker_paper_job = 0;

int getRand(int range){    
    int randNum = rand() % range;    
    return randNum;   
}

void * agent(void * arg){   
    while(1) {   
        sleep(1); 
        
        //Lock     
        pthread_mutex_lock(&m);       
        //The agent stays waiting if agent_job is equal 0
        while(agent_job == 0)
            pthread_cond_wait(&agent_c, &m);      
        printf("\n");
        
        int randNum = getRand(3);
        
        //Paper and Match
        if ( randNum == 0 ) 
        {         
            agent_job = 0;
            have_match = 1;
            have_paper = 1;
            puts("Agent puts paper and match on the table");
            pthread_cond_signal(&paper);
            pthread_cond_signal(&match);
        }
        
        //Tobacco and Match
        else if ( randNum == 1 ) 
        {
            agent_job = 0;
            have_match = 1;
            have_tobacco = 1;
            puts("Agent puts tobacco and match on the table");
            pthread_cond_signal(&tobacco);
            pthread_cond_signal(&match);
        }
        
        //Tobacco and Paper
        else if ( randNum == 2 ) 
        {
            agent_job = 0;
            have_tobacco = 1;
            have_paper = 1;
            puts("Agent puts paper and tobacco on the table");
            pthread_cond_signal(&paper);
            pthread_cond_signal(&tobacco);
        }
        //Unlock
        pthread_mutex_unlock(&m);
    }
    return 0;
}

void * pusher_paper(void * arg){   
    while(1)
    {
        pthread_mutex_lock(&m);
        //wait for smoker to be ready for paper
        while(have_paper == 0)
            pthread_cond_wait(&paper, &m);
    	
    	//check if smoker has matches or tobacco
        if(have_match == 1) {
            have_match = 0;
            agent_job = 0;
            smoker_tobacco_job = 1;
            puts("Call the tobacco smoker");
            //call smoker waiting on tobacco instead
            pthread_cond_signal(&smoker_tobacco_c);
        }
        if(have_tobacco == 1) {
            have_tobacco = 0;
            agent_job = 0;
            smoker_match_job = 1;
            puts("Call the match smoker");
            //call smoker waiting on match instead
            pthread_cond_signal(&smoker_match_c);
        }
        pthread_mutex_unlock(&m);
    }
    
    return 0 ;
}

void * pusher_match(void * arg){
    
    while(1) {
        pthread_mutex_lock(&m);
        //wait for smoker to be ready for matches
        while(have_match == 0)
            pthread_cond_wait(&match, &m);
    	
    	//check if smoker has paper or tobacco
        if(have_paper == 1) {
            have_paper = 0;
            agent_job = 0;
            smoker_tobacco_job = 1;
            puts("Call the tobacco smoker");
            //call smoker waiting on tobacco instead
            pthread_cond_signal(&smoker_tobacco_c);
        }
        if(have_tobacco == 1) {
            have_tobacco = 0;
            agent_job = 0;
            smoker_paper_job = 1;
            puts("Call the paper smoker");
            //call smoker waiting on paper instead
            pthread_cond_signal(&smoker_paper_c);
        }
        pthread_mutex_unlock(&m);
    }
    
    return 0 ;
}

void * pusher_tobacco(void * arg){
    while(1){
        pthread_mutex_lock(&m);
        //wait for smoker to be ready for tobacco
        
        while(have_tobacco == 0)
            pthread_cond_wait(&tobacco, &m);
    	//check if smoker has paper or match
        if(have_match == 1) {
            have_match = 0;
            agent_job = 0;
            smoker_paper_job = 1;
            puts("Call the paper smoker");
            //call smoker waiting on paper instead
            pthread_cond_signal(&smoker_paper_c);
        }
        if(have_paper == 1) {
            have_tobacco = 0;
            agent_job = 0;
            smoker_match_job = 1;
            puts("Call the match smoker");
            //call smoker waiting on match instead
            pthread_cond_signal(&smoker_match_c);
        }
        pthread_mutex_unlock(&m);
    }
    return 0 ;
}

void * smoker_tobacco(void * arg){
    
    while(1){
        
        pthread_mutex_lock(&smoker);
        //wait for smoker to be ready for assets
        while(smoker_tobacco_job == 0)
            pthread_cond_wait(&smoker_tobacco_c, &smoker);
        //doesn't have paper or matches
        have_paper = 0;
        have_match = 0;
        smoker_tobacco_job = 0;
        agent_job = 1;
        puts("Tobacco Smoker is now smoking");
        pthread_mutex_unlock(&smoker);
        

    }
    
    return 0;
}

void * smoker_paper(void * arg){
    
    while(1){
        
        pthread_mutex_lock(&smoker);
        //wait for smoker to be ready for assets
        while(smoker_paper_job == 0)
            pthread_cond_wait(&smoker_paper_c, &smoker);
        //doesn't have match or tobacco
        have_tobacco = 0;
        have_match = 0;
        smoker_paper_job = 0;
        agent_job = 1;
        puts("Paper Smoker is now smoking");
        pthread_mutex_unlock(&smoker);
        
    }
    
    return 0;
}

void * smoker_match(void * arg){
    
    while(1){
        
        pthread_mutex_lock(&smoker);
        //wait for smoker to be ready for assets
        while(smoker_match_job == 0)
            pthread_cond_wait(&smoker_match_c, &smoker);
        //doesn't have paper or tobacco
        have_paper = 0;
        have_tobacco = 0;
        smoker_match_job = 0;
        agent_job = 1;
        puts("Match Smoker is now smoking");
        pthread_mutex_unlock(&smoker);
        
    }
    
    return 0;
}


int main(int argc, char *argv[])
{
    pthread_t agent_t,		//agent having infinite resources
    smoker_tobacco_t, 		//smoker with infinite tobacco
    smoker_paper_t, 		//smoker with infinite paper
    smoker_match_t,    	//smoker with infinite macth
    pusher_tobacco_t, 		//agent giving tobacco
    pusher_paper_t, 		//agent giving paper
    pusher_match_t;		//agent giving match

    //thread creation
    pthread_create(&agent_t,NULL,agent,NULL);   
    pthread_create(&pusher_tobacco_t,NULL,pusher_tobacco,NULL);
    pthread_create(&pusher_paper_t,NULL,pusher_paper,NULL);
    pthread_create(&pusher_match_t,NULL,pusher_match,NULL);
    pthread_create(&smoker_tobacco_t,NULL,smoker_tobacco,NULL);
    pthread_create(&smoker_paper_t,NULL,smoker_paper,NULL);
    pthread_create(&smoker_match_t,NULL,smoker_match,NULL);
   
    //joining threads 
    pthread_join(agent_t, NULL);
    pthread_join(pusher_tobacco_t, NULL);
    pthread_join(pusher_paper_t, NULL);
    pthread_join(pusher_match_t, NULL);
    pthread_join(smoker_tobacco_t, NULL);
    pthread_join(smoker_paper_t, NULL);
    pthread_join(smoker_match_t, NULL);

}
