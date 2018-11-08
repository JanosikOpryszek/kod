#include<stdlib.h>
#include<stdio.h>
#include<pthread.h>
#include<unistd.h>  // sleep

pthread_mutex_t mutex;   //zmienna mutexu


void funkcja1(void)     //funkcja ktora na watku bedzie blok. mutex
{
pthread_mutex_lock( &mutex );   //blokuje mutex

while(1)                        //petla
{
    printf("petla\n");
}

pthread_mutex_unlock( &mutex );  //odblokowywuje mutex
}


int main ()
{

pthread_mutex_init(&mutex, NULL);    //inicjalizacja mutexu

pthread_t ping;                     //tworzenie watku
pthread_create( &ping, NULL, (void*)&funkcja1, NULL );   //uruchamianie funkcji w watku


pthread_join( ping, NULL );    //czeka az watek pink zakonczy
pthread_mutex_destroy(&mutex);  //niszczy mutex

return 0;
}
