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


/* This is a callback function. The data arguments are ignored
 * in this example. More on callbacks below. */
static void hello( GtkWidget *widget,
                   gpointer   data )
{
    g_print ("Hello World\n");
}
static gboolean delete_event( GtkWidget *widget,
                              GdkEvent  *event,
                              gpointer   data )
{
    /* If you return FALSE in the "delete_event" signal handler,
     * GTK will emit the "destroy" signal. Returning TRUE means
     * you don't want the window to be destroyed.
     * This is useful for popping up 'are you sure you want to quit?'
     * type dialogs. */
    g_print ("delete event occurred\n");
    /* Change TRUE to FALSE and the main window will be destroyed with
     * a "delete_event". */
    return TRUE;
}
/* Another callback */
static void destroy( GtkWidget *widget,
                     gpointer   data )
{
    gtk_main_quit ();
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



//ImsgvermethodPut* fakemsgveryficator=new ImsgvermethodPut();
//srv::ILogger* fakeloger=new Loger();
//Candriverserver* myeth=new Candriverserver(*fakeloger,*fakemsgveryficator);

//Iethernet* myethserver1=myeth;
//drv::ICandriverserver* myethserver2=myeth;
//myethserver2->init();
//pthread_t thread_id;
//pthread_create(&thread_id,NULL,&Ethernetdriverserver::initializess,myethserver);
/*
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

*/
 /* GtkWidget is the storage type for widgets */
    GtkWidget *window;
    GtkWidget *button;

    /* This is called in all GTK applications. Arguments are parsed
     * from the command line and are returned to the application. */
    gtk_init (&argc, &argv);

    /* create a new window */
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);

    /* When the window is given the "delete_event" signal (this is given
     * by the window manager, usually by the "close" option, or on the
     * titlebar), we ask it to call the delete_event () function
     * as defined above. The data passed to the callback
     * function is NULL and is ignored in the callback function. */
    g_signal_connect (G_OBJECT (window), "delete_event",
              G_CALLBACK (delete_event), NULL);

    /* Here we connect the "destroy" event to a signal handler.
     * This event occurs when we call gtk_widget_destroy() on the window,
     * or if we return FALSE in the "delete_event" callback. */
    g_signal_connect (G_OBJECT (window), "destroy",
              G_CALLBACK (destroy), NULL);

    /* Sets the border width of the window. */
    gtk_container_set_border_width (GTK_CONTAINER (window), 10);

    /* Creates a new button with the label "Hello World". */
    button = gtk_button_new_with_label ("Hello World");

    /* When the button receives the "clicked" signal, it will call the
     * function hello() passing it NULL as its argument.  The hello()
     * function is defined above. */
    g_signal_connect (G_OBJECT (button), "clicked",
              G_CALLBACK (hello), NULL);

    /* This will cause the window to be destroyed by calling
     * gtk_widget_destroy(window) when "clicked".  Again, the destroy
     * signal could come from here, or the window manager. */
    g_signal_connect_swapped (G_OBJECT (button), "clicked",
                  G_CALLBACK (gtk_widget_destroy),
                              G_OBJECT (window));

    /* This packs the button into the window (a gtk container). */
    gtk_container_add (GTK_CONTAINER (window), button);

    /* The final step is to display this newly created widget. */
    gtk_widget_show (button);

    /* and the window */
    gtk_widget_show (window);

    /* All GTK applications must have a gtk_main(). Control ends here
     * and waits for an event to occur (like a key press or
     * mouse event). */
    gtk_main ();

    return 0;
}



