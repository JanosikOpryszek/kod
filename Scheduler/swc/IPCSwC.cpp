#include "IPCSwC.hpp"
#include<unistd.h>

swc::IPCSwC::IPCSwC()
{

}

swc::IPCSwC::~IPCSwC()
{
}

void* swc::IPCSwC::work()
{

    std::cout<<"IPCSwS working"<<std::endl;


    return 0;
}

