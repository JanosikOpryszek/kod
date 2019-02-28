#include<string>
#include<iostream>
#include <locale>
#include<unistd.h>  // sleep
#include"imsgvermethod.hpp"


namespace drv
{

eErrorCodes ImsgmethodPut::retEr;          //variable to return errorcode
unsigned long ImsgmethodPut::temp=0;
unsigned long ImsgmethodPut::fpreasure=0;
unsigned long ImsgmethodPut::rmp=0;
unsigned long ImsgmethodPut::speed=0;
unsigned long ImsgmethodPut::airtemp=0;
std::string ImsgmethodPut::spacee=" ";
bool ImsgmethodPut::direction=1;



eErrorCodes ImsgmethodPut::putMessage(std::string comingMessage)
{
    retEr=OK;

    //std::locale loc;
    std::string strin=comingMessage.substr(4,6);
    const char * chararray=strin.c_str();
    char nr1=chararray[0];
    char nr2=chararray[1];
    char nr3=chararray[2];


    if(isdigit(nr1)&&isdigit(nr2)&&isdigit(nr3))
    {

        switch (comingMessage[2] )
        {
        case '5': //coolant temp= A-40
        {
            temp=(std::stoul(comingMessage.substr(4,6),nullptr,10))-40; //stoul conver string to int
            show();
            break;
        }
        case 'a':  //fuel presure = 3*A
        {
            fpreasure=(std::stoul(comingMessage.substr(4,6),nullptr,10))*3;   //stoul conver string to int
            show();
            break;
        }
        case 'c':   //engine rmp = (256*A)/4
        {
            rmp=((std::stoul(comingMessage.substr(4,6),nullptr,10))*256)/4;   //stoul conver string to int
            show();
            break;
        }

        case 'd':   //speed = A
        {
            speed=std::stoul(comingMessage.substr(4,6),nullptr,10);   //stoul conver string to int
            show();
            break;
        }

        case 'f':   //airtemp = A-40
        {
            airtemp=(std::stoul(comingMessage.substr(4,6),nullptr,10))-40;   //stoul conver string to int
            show();
            break;
        }
        default:
            break;
        }
    }
    else if(isdigit(nr1)&&isdigit(nr2))
    {

        switch (comingMessage[2] )
        {
        case '5': //coolant temp= A-40
        {
            temp=(std::stoul(comingMessage.substr(4,5),nullptr,10))-40; //stoul conver string to int
            show();
            break;
        }
        case 'a':  //fuel presure = 3*A
        {
            fpreasure=(std::stoul(comingMessage.substr(4,5),nullptr,10))*3;   //stoul conver string to int            show();
            break;
        }
        case 'c':   //engine rmp = (256*A)/4
        {
            rmp=((std::stoul(comingMessage.substr(4,5),nullptr,10))*256)/4;   //stoul conver string to int
            show();
            break;
        }

        case 'd':   //speed = A
        {
            speed=std::stoul(comingMessage.substr(4,5),nullptr,10);   //stoul conver string to int
            show();
            break;
        }

        case 'f':   //airtemp = A-40
        {
            airtemp=(std::stoul(comingMessage.substr(4,5),nullptr,10))-40;   //stoul conver string to int
            show();
            break;
        }
        default:
            break;
        }
    }
    else if(isdigit(nr1))
    {

        switch (comingMessage[2] )
        {
        case '5': //coolant temp= A-40
        {
            temp=(std::stoul(comingMessage.substr(4,4),nullptr,10))-40; //stoul conver string to int
            show();
            break;
        }
        case 'a':  //fuel presure = 3*A
        {
            fpreasure=(std::stoul(comingMessage.substr(4,4),nullptr,10))*3;   //stoul conver string to int            show();
            break;
        }
        case 'c':   //engine rmp = (256*A)/4
        {
            rmp=((std::stoul(comingMessage.substr(4,4),nullptr,10))*256)/4;   //stoul conver string to int
            show();
            break;
        }

        case 'd':   //speed = A
        {
            speed=std::stoul(comingMessage.substr(4,4),nullptr,10);   //stoul conver string to int
            show();
            break;
        }

        case 'f':   //airtemp = A-40
        {
            airtemp=(std::stoul(comingMessage.substr(4,4),nullptr,10))-40;   //stoul conver string to int
            show();
            break;
        }
        default:
            break;
        }
    }










return retEr;
}

eErrorCodes ImsgmethodPut::show()
{

    std::system("clear");
    std::cout<<"---------------------------------------------------------------------------"<<std::endl;
    std::cout<<"                          Coolant temp=";
    std::cout<<temp<<std::endl;
    std::cout<<"                          Fuel preasure=";
    std::cout<<fpreasure<<std::endl;
    std::cout<<"                          Engine RPM=";
    std::cout<<rmp<<std::endl;
    std::cout<<"                          Air temp=";
    std::cout<<airtemp<<std::endl;
    std::cout<<std::endl;


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
    std::cout<<spacee<<"  fZP   SPEED:   SMMb"<<std::endl;
    std::cout<<spacee<<"  HZM     "<<speed<<"    MMMM"<<std::endl;
    std::cout<<spacee<<"  FqM            MMMM"<<std::endl;
    std::cout<<spacee<<"__| .         | dSqML"<<std::endl;
    std::cout<<spacee<<"|    `.       | `'  Zq"<<std::endl;
    std::cout<<spacee<<"_)       .___.,|     .'"<<std::endl;
    std::cout<<spacee<<" ____   )MMMMMP|   .'"<<std::endl;
    std::cout<<spacee<<"    `-'       `--' hjm"<<std::endl;
    std::cout<<"Press x Enter to exit.-----------------------------------------------------"<<std::endl;
    return retEr;

}


}

