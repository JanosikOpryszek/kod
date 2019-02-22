#include<string>
#include<iostream>
#include<unistd.h>  // sleep
#include"imsgvermethod.hpp"


namespace drv
{

eErrorCodes ImsgmethodPut::retEr;          //variable to return errorcode
unsigned long ImsgmethodPut::temp=0;
unsigned long  ImsgmethodPut::fpreasure=0;
unsigned long  ImsgmethodPut::rmp=0;
std::string ImsgmethodPut::spacee=" ";
bool ImsgmethodPut::direction=1;



eErrorCodes ImsgmethodPut::putMessage(std::string comingMessage)
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
    case 'a':  //fuel presure
    {
        fpreasure=std::stoul(comingMessage.substr(4,6),nullptr,10);   //stoul conver string to int
        show();
        break;
    }
    case 'c':   //engine rmp
    {
        rmp=std::stoul(comingMessage.substr(4,6),nullptr,10);   //stoul conver string to int
        show();
        break;
    }
    default:
        break;

}

return retEr;
}

eErrorCodes ImsgmethodPut::show()
{

    std::system("clear");
    std::cout<<"---------------------------------------------------------------------------"<<std::endl;
    std::cout<<"coolant temp=";
    std::cout<<temp<<std::endl;
    std::cout<<"fuel preasure=";
    std::cout<<fpreasure<<std::endl;
    std::cout<<"engine RPM=";
    std::cout<<rmp<<std::endl;
    std::cout<<"direction= "<<direction<<".  Pres x Enter to exit. "<<std::endl;
    std::cout<<"---------------------------------------------------------------------------"<<std::endl;

    //move picture
    if (direction )
    {
        if( spacee.length()<50 )
        {
            spacee.append(" ");
        }
        else
            direction=0;
    }
    else
    {
        if(spacee.length()>2)
        {
            spacee.erase(0,1);
        }
        else
            direction=1;
    }


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

bool ImsgmethodPut::checkdirection()
{

    return direction;

}

}

