#include<stdlib.h>
#include<stdio.h>
#include<pthread.h>
#include<unistd.h>  // sleep

//Scheduling policy
//https://www.oreilly.com/library/view/pthreads-programming/9781449364724/ch04.html
//
//http://man7.org/linux/man-pages/man7/sched.7.html



pthread_mutex_t mutex;   //zmienna mutexu
pthread_attr_t  custom_sched_attr;                       //Setting varible custom Schedul in an Attribute Object
int fifo_max_prio, fifo_min_prio, fifo_mid_prio;
struct sched_param fifo_param;



void funkcja1(void)     //funkcja ktora na watku bedzie blok. mutex
{

while(1)                        //petla
{

pthread_mutex_lock( &mutex );   //blokuje mutex
    printf("petla\n");

pthread_mutex_unlock( &mutex );  //odblokowywuje mutex

}

}


void funkcja2(void)     //funkcja ktora na watku bedzie blok. mutex
{

while(1)                        //petla
{

pthread_mutex_lock( &mutex );   //blokuje mutex
    printf("----------------------------------------------------------petla\n");

pthread_mutex_unlock( &mutex );  //odblokowywuje mutex

}

}
int main ()
{

pthread_mutex_init(&mutex, NULL);    //inicjalizacja mutexu

pthread_attr_init(&custom_sched_attr);                             //inicjacja  custom sheduling
//pthread_attr_setinheritsched(&custom_sched_attr, PTHREAD_EXPLICIT_SCHED);
pthread_attr_setschedpolicy(&custom_sched_attr, SCHED_RR);

fifo_max_prio = sched_get_priority_max(SCHED_FIFO);
fifo_min_prio = sched_get_priority_min(SCHED_FIFO);
fifo_mid_prio = (fifo_min_prio + fifo_max_prio)/2;
fifo_param.sched_priority = 1;              //fifo_mid_prio;

pthread_attr_setschedparam(&custom_sched_attr, &fifo_param);



pthread_t ping;                     //tworzenie watku 1
pthread_create( &ping, &custom_sched_attr , (void*)&funkcja1, NULL );   //uruchamianie funkcji1 w watku 

pthread_t pong;                     //tworzenie watku 2
pthread_create( &pong, &custom_sched_attr,  (void*)&funkcja2, NULL );   //uruchamianie funkcji2 w watku 





pthread_join( ping, NULL );    //czeka az watek pink zakonczy
pthread_join( pong, NULL );    //czeka az watek pink zakonczy

pthread_mutex_destroy(&mutex);  //niszczy mutex

return 0;
}
