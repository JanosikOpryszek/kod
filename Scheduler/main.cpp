
#include<iostream>
#include<unistd.h>
#include<string>
#include<pthread.h>
#include<unistd.h>  // sleep

#include <stdlib.h> // exit()             ??
#include <string.h> // memset strlen
#include"sheduler.hpp"
#include"Loger.hpp"
#include"eStates.h"




int main ()
{


    srv::Loger logger;
    rte::Sheduler *objsheduler=new rte::Sheduler(logger);


objsheduler->mOnStateChange(PRE_START);

objsheduler->mOnStateChange(IDLE);

objsheduler->mOnStateChange(INIT);

objsheduler->mOnStateChange(FULL_OP);




sleep(10);

return 0;
}
