#include<unistd.h>
#include<signal.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#define SIGHUP 1
#define SIGINT 2
#define SIGQUIT 3

pthread_mutex_t m1=PTHREAD_MUTEX_INITIALIZER;

sem_t s1;
sem_t s2;
sem_t s3;
sem_t s4;


void sighup(); 
void sigint(); 
void sigquit(); 

void Alert_Doctor() 
{ 
  int pid;
  
     //
			if ((pid = fork()) < 0)
				{ 
				perror("fork"); 
				exit(1); 
				} 
  
			if (pid == 0)
				{	                            //child
				signal(SIGHUP, sighup); 
				signal(SIGINT, sigint); 
				signal(SIGQUIT, sigquit); 
				for (;;); 
				} 
				  
  
			else 
				{ 
				printf("\nPARENT: sending SIGHUP\n\n");  
				kill(pid, SIGHUP); 
  
				sleep(3); 
				printf("\nPARENT: sending SIGINT\n\n"); 
				kill(pid, SIGINT); 
  
				sleep(3);
				printf("\nPARENT: sending SIGQUIT\n\n"); 
				kill(pid, SIGQUIT); 
				sleep(3); 
				} 
		}
		

   

  
void sigint() 
  
{ 
    signal(SIGINT, sigint); //reset signal
    printf("Doctor treating the patient \n"); 
} 
  
void sigquit() 
{ 
    printf("Treatment complete\n"); 

} 

void sighup() 
  
{ 
    signal(SIGHUP, sighup); //reset signal
    printf("Doctor has been alerted\n"); 
} 
	

 
int CheckVitals( int Breathing_rate, int Heart_beat)
{
	printf("Patient Vital Details : Heart_beat - %d and Breathing_rate - %d", Heart_beat, Breathing_rate);
	if(Breathing_rate > 12 && Breathing_rate<20 )
		{
			if (Heart_beat>60 && Heart_beat<100)
				{
					printf("Patient is normal");
				}
			else 
				{
					printf("Heart_beat Problem - Alert the doctor");
					 Alert_Doctor();
				}
		}
		else
			{
				printf("Patient is in a critical situation - Alert the doctor as fast as possible");
				Alert_Doctor();	
			}
			
}
		
		
	



void* patient1(void* pv)
{
	sem_wait(&s1);
	pthread_mutex_lock(&m1);
	char str[]= "Suraj";
	int IDn= 785;
	printf("Patient name : %s \n Patient ID : %d", str,IDn);
	CheckVitals(15,65);

	
	pthread_mutex_lock(&m1);
	sem_post(&s1);
	sem_post(&s2);
	

	//pthread_exit(NULL);
}

void* patient2(void* pv)
{
	sem_wait(&s2);
	pthread_mutex_lock(&m1);
	char str[]= "Vinay";
	int IDn= 788;
	printf("Patient name : %s \n Patient ID : %d", str,IDn);
	CheckVitals(10,110);

	
	pthread_mutex_lock(&m1);
	sem_post(&s2);
	sem_post(&s3);

	//pthread_exit(NULL);
}

void* patient3(void* pv)
{
	sem_wait(&s3);
	pthread_mutex_lock(&m1);
	char str[]= "Reeshav";
	int IDn= 790;
	printf("Patient name : %s \n Patient ID : %d", str,IDn);
	CheckVitals(25,50);

	
	pthread_mutex_lock(&m1);
	sem_post(&s3);
	sem_post(&s4);
	

	//pthread_exit(NULL);
}

void* patient4(void* pv)
{
	sem_wait(&s4);
	pthread_mutex_lock(&m1);
	char str[]= "Rajath";
	int IDn= 795;
	printf("Patient name : %s \n Patient ID : %d", str,IDn);
	CheckVitals(14,80);

	
	pthread_mutex_lock(&m1);
	sem_post(&s4);
	

	//pthread_exit(NULL);
}




int main()
{
	pthread_t pt1,pt2,pt3,pt4;	//thread handle
	sem_init(&s1,0,1);
	sem_init(&s2,0,0);
	sem_init(&s3,0,0);
	sem_init(&s4,0,0);
	pthread_create(&pt1,NULL,patient1,NULL);
	
	pthread_create(&pt2,NULL,patient2,NULL);
	
	pthread_create(&pt3,NULL,patient3,NULL);
	
	pthread_create(&pt4,NULL,patient4,NULL);
	
	pthread_join(pt1,NULL);
	pthread_join(pt2,NULL);
	pthread_join(pt3,NULL);
	pthread_join(pt4,NULL);
	sem_destroy(&s1);
	sem_destroy(&s2);
	sem_destroy(&s3);
	sem_destroy(&s4);
	pthread_mutex_destroy(&m1);
	printf("Thank you for the visit\n");
	return 0;	//exit(0);
}

