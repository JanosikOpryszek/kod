
#include<iostream>
#include<string>
#include<pthread.h>
#include<unistd.h>  // sleep

#include <stdlib.h> // exit()             ??
#include <string.h> // memset strlen
#include"sheduler.hpp"




int main ()
{
    rte::Sheduler *objsheduler=new rte::Sheduler;

objsheduler->mRun();

sleep(5);

return 0;
}
