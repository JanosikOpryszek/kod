#include "SensorMasterImpl.h"
#include<unistd.h>


swc::SensorMasterImpl::SensorMasterImpl()
{

}

void* swc::SensorMasterImpl::work()
{
    std::cout<<"Sensorworking"<<std::endl;
    return 0;
}
