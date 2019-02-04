#include<iostream>
#include <gtk/gtk.h>
#include<string>
#include<pthread.h>
#include<unistd.h>  // sleep

#include <stdlib.h> // exit()             ??
#include <string.h> // memset strlen
#include <arpa/inet.h> // inet_pton inet_addr
#include <sys/socket.h> // AF_UNIX
#include <netinet/in.h> // sockaddr_in    ??
#include"Candriverserver.hpp"
#include"Iethernet.hpp"
#include"ICandriverserver.hpp"
#include"imsgvermethod.hpp"
#include"eErrorCodes.h"
#include"ILogger.h"
//#include"Loger.hpp"

using namespace drv;


static void print_hello (GtkWidget *widget, gpointer   data)
{
  g_print ("Hello World\n");
}

static void activate (GtkApplication *app, gpointer  user_data)
{
  GtkWidget *window;
  GtkWidget *button;
  GtkWidget *button_box;

  window = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW (window), "Window");
  gtk_window_set_default_size (GTK_WINDOW (window), 200, 200);

  button_box = gtk_button_box_new (GTK_ORIENTATION_HORIZONTAL);
  gtk_container_add (GTK_CONTAINER (window), button_box);

  button = gtk_button_new_with_label ("Hello World");
  g_signal_connect (button, "clicked", G_CALLBACK (print_hello), NULL);
  g_signal_connect_swapped (button, "clicked", G_CALLBACK (gtk_widget_destroy), window);
  gtk_container_add (GTK_CONTAINER (button_box), button);

  gtk_widget_show_all (window);
}




class Loger:public srv::ILogger
{

    eErrorCodes errRet;

    public:
    Loger()
    {
    std::cout<<"Logger created"<<std::endl;
    }

    ~Loger()
    {

    }

    eErrorCodes init()
    {
        errRet=OK;
        return errRet;
    }

    eErrorCodes deinit()
    {
        errRet=OK;
        return errRet;
    }



    eErrorCodes mLog_ERR(std::string a_strInput)
    {
        std::cout<<a_strInput<<std::endl;
        errRet=OK;
        return errRet;
    }


    eErrorCodes mLog_DBG(std::string a_strInput)
    {
        std::cout<<a_strInput<<std::endl;
        errRet=OK;
        return errRet;
    }

    eErrorCodes mLog_INF(std::string a_strInput)
    {
        std::cout<<a_strInput<<std::endl;
        errRet=OK;
        return errRet;
    }



    eErrorCodes mLog_WRN(std::string a_strInput)
    {
        std::cout<<a_strInput<<std::endl;
        errRet=OK;
        return errRet;
    }


};









int main (int    argc,
          char **argv)
{



ImsgvermethodPut* fakemsgveryficator=new ImsgvermethodPut();
srv::ILogger* fakeloger=new Loger();
Candriverserver* myeth=new Candriverserver(*fakeloger,*fakemsgveryficator);

//Iethernet* myethserver1=myeth;
drv::ICandriverserver* myethserver2=myeth;
myethserver2->init();
//pthread_t thread_id;
//pthread_create(&thread_id,NULL,&Ethernetdriverserver::initializess,myethserver);

bool version;
std::cout<<"Sending (car emulation) press 0, receiving (tester emulation) press 1: ";
std::cin >> version;

std::string tekst;
sleep(1);

if(version)
{
myethserver2->mRun();
std::cout<<"reading messages (tester emulation)"<<std::endl;
}
else
{
    while(1)
    {
        std::cout <<" 05(05)-cooland tem=A-40, 12(0c)RMP (2568A+B)/4, 12(0d) speed\n";
        std::cout << " podaj message id#data 00c#12345678: ";
        std::cin >> tekst;
        std::cout << "\npodales: " << tekst <<std::endl;
        myethserver2->send(tekst);
        tekst.clear();
        sleep(1);
    }
}


//reading and showing messages part



GtkApplication *app;
  int status;

  app = gtk_application_new ("org.gtk.example", G_APPLICATION_FLAGS_NONE);
  g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
  g_application_run (G_APPLICATION (app), argc, argv);

  g_object_unref (app);

  //return status;


return 0;
}



