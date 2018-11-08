#include<stdlib.h>
#include<sched.h>
#include<stdio.h>
#include<pthread.h>
#include<unistd.h>  // sleep

                                    //Scheduling policy
pthread_attr_t my_attr;                                          //atrybuty threadow
pthread_attr_t my_attr2;                                          //atrybuty threadoww
struct sched_param param1, param2;

long unsigned int ff1 =0;
long unsigned int ff2=0;

void funkcja1(void)     
{
while(1)                      
{
    if (!(ff1 % 10000000)) {
    printf("funkcja1 = %lu\n",ff1);
    }
    ff1++;
}
}

void funkcja2(void)     
{
while(1)                
{
    if (!(ff2 % 10000000)) {
    printf("funkcja2 = %lu\n",ff2);
    }
    ff2++;
}
}

int main ()
{
pthread_attr_init(&my_attr);
pthread_attr_init(&my_attr2);
pthread_attr_setinheritsched (&my_attr, PTHREAD_EXPLICIT_SCHED);     //nie dziedzicz ustawien watku z wywalujacego
pthread_attr_setinheritsched (&my_attr2, PTHREAD_EXPLICIT_SCHED);  
pthread_attr_setschedpolicy(&my_attr, SCHED_RR);  //RR lub FIFO
pthread_attr_setschedpolicy(&my_attr2, SCHED_RR); 
param1.sched_priority = 1;
param2.sched_priority = 5;

pthread_attr_setschedparam(&my_attr, &param1);               //param1 do atrybutow  watku
pthread_t ping;                     //tworzenie watku 1
pthread_create( &ping, &my_attr , (void*)&funkcja1, NULL );   //uruchamianie funkcji1  

pthread_attr_setschedparam(&my_attr2, &param2);              //param2 do atrybutow watku
pthread_t pong;                     //tworzenie watku 2
pthread_create( &pong, &my_attr,  (void*)&funkcja2, NULL );   //uruchamianie funkcji2

pthread_join( ping, NULL );    //czeka az watek pink zakonczy
pthread_join( pong, NULL );    //czeka az watek pink zakonczy
pthread_attr_destroy(&my_attr);   //niszczy zmienna atrybutow
pthread_attr_destroy(&my_attr2);   //niszczy zmienna atrybutow
return 0;
}
