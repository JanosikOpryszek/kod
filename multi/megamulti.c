#include<stdio.h>
#include<pthread.h>
#include<unistd.h>  // sleep


void *wyswietl(void *arg)
{
  while(1)
  {
    printf("POSIX C wyswietlam swoj pid= %li\n",pthread_self());
//    sleep(1);
  }
    //   pthread_exit(NULL);
}

int main()
{


pthread_t  myThreads[1000];                          
int i=0;
while(i<1000)
{    


pthread_create(&myThreads[i],NULL,&wyswietl,NULL);              

//sleep(1);
i++;
}

int b;                    
scanf("%d",&b);       //nie konczy maina           

return 0;
}

