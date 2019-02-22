/// @file        <MSGveryficator.cpp>
/// @ingroup     <drv>
/// @brief       <MSGveryficator class>


#include<string>
#include<iostream>
#include<unistd.h>  // sleep
#include"imsgvermethod.hpp"


namespace drv
{

    eErrorCodes ImsgvermethodPut::retEr;          //variable to return errorcode
    int ImsgvermethodPut::temp=0;
    int ImsgvermethodPut::fpreasure=0;
    int ImsgvermethodPut::rmp=0;
    std::string ImsgvermethodPut::spacee=" ";
    bool ImsgvermethodPut::direction=1;



    eErrorCodes ImsgvermethodPut::putMessage(std::string comingMessage)
    {
    retEr=OK;

    switch (comingMessage[2] )
    {
    case '5': //coolant temp= A-40
    {
        temp=std::stoul(comingMessage.substr(4,6),nullptr,10); //stoul conver string to int
        show();
        break;
    }
    case 'a':
    {
        fpreasure=std::stoul(comingMessage.substr(4,6),nullptr,10);   //stoul conver string to int
        show();
        break;
    }
    case 'c':
    {
        rmp=std::stoul(comingMessage.substr(4,6),nullptr,10);   //stoul conver string to int
        show();
        break;
    }
    default:
        break;

    }


    //std::cout<<comingMessage<<std::endl;
    return retEr;
    }

    eErrorCodes ImsgvermethodPut::show()
    {

        std::system("clear");
        std::cout<<"**************************************************************************"<<std::endl;
        std::cout<<"coolant temp=";
        std::cout<<temp<<std::endl;
        std::cout<<"fuel preasure=";
        std::cout<<fpreasure<<std::endl;
        std::cout<<"engine RPM=";
        std::cout<<rmp<<std::endl;
        std::cout<<"pres x Enter to exit"<<std::endl;
        std::cout<<"---------------------------------------------------------------------------"<<std::endl;

spacee.append(" ");
std::cout<<spacee<<"        _nnnn_"<<std::endl;
std::cout<<spacee<<"       dGGGGMMb"<<std::endl;
std::cout<<spacee<<"      @p~qp~~qMb"<<std::endl;
std::cout<<spacee<<"      M|@||@) M|"<<std::endl;
std::cout<<spacee<<"      @,----.JM|"<<std::endl;
std::cout<<spacee<<"     JS^ __/  qKL"<<std::endl;
std::cout<<spacee<<"    dZP        qKRb"<<std::endl;
std::cout<<spacee<<"   dZP          qKKb"<<std::endl;
std::cout<<spacee<<"  fZP            SMMb"<<std::endl;
std::cout<<spacee<<"  HZM            MMMM"<<std::endl;
std::cout<<spacee<<"  FqM            MMMM"<<std::endl;
std::cout<<spacee<<"__| .         | dSqML"<<std::endl;
std::cout<<spacee<<"|    `.       | `'  Zq"<<std::endl;
std::cout<<spacee<<"_)       .___.,|     .'"<<std::endl;
std::cout<<spacee<<" ____   )MMMMMP|   .'"<<std::endl;
std::cout<<spacee<<"    `-'       `--' hjm"<<std::endl;
return retEr;

    }
/*
    eErrorCodes ImsgvermethodPut::deinit()
    {
        return retEr;
    }


    eErrorCodes ImsgvermethodPut::mRun()
    {
    retEr=OK;
    return retEr;
    }
    eErrorCodes ImsgvermethodPut::mStop()
    {
        retEr=OK;
        return retEr;
    }
    eErrorCodes ImsgvermethodPut::mPause()
    {
        retEr=OK;
        return retEr;
    }
    eErrorCodes ImsgvermethodPut::mResume()
    {
        retEr=OK;
        return retEr;
    }

*/


}

