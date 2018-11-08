#include<iostream>
#include<stdlib.h>
#include <thread>

using namespace std;


void wyswietl()
{
  while(1)
  {
    cout<<"c++11 Thread wyswietlam swoj pid="<<pthread_self()<<endl;
//std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }
}

int main()
{


thread  myThreads[1000];                          
int i=0;

while(i<1000)
{    
    //std::thread{wyswietl}.detach();
    myThreads[i]=std::thread(wyswietl);
    i++;
}

int b;
cin>>b;  //nie koncz main

return 0;
}

