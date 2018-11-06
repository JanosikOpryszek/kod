#include<iostream>
#include<stdlib.h>
#include <thread>

using namespace std;

int licznik=0;

void uruchom();


void wyswietl()
{
licznik++;
uruchom();

while(1)
  {
    cout<<"uruchomiles watkow w licznie = "<<licznik<<endl;
    cout<<"c++11 Thread wyswietlam swoj pid="<<pthread_self()<<endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }
}

void uruchom()
{
std::thread{wyswietl}.detach();
}


int main()
{

uruchom();


int b;
cin>>b;  //nie koncz main

return 0;
}

