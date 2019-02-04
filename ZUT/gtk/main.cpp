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

enum {
    KOLUMNA_OSOBA = 0,
    ILOSC_KOLUMN
};

GtkTreeView * treeview;
GtkWidget * przycisk_usun, * przycisk_zmien;

void wcisnieto_Dodaj( GtkWidget * entry, gpointer data )
{
    const gchar * tekst;

    tekst = gtk_entry_get_text( GTK_ENTRY( entry ) );

    // Jeśli wypełniono kontrolke entry
    if( strlen( tekst ) )
    {
        GtkTreeModel * model;
        GtkTreeIter iter;

        // Pobranie modelu z kontrolki
        model = gtk_tree_view_get_model( GTK_TREE_VIEW( treeview ) );

        // Dodatnie wiersza na koniec listy
        gtk_list_store_append( GTK_LIST_STORE( model ), & iter );
        gtk_list_store_set( GTK_LIST_STORE( model ), & iter, KOLUMNA_OSOBA, tekst, - 1 );

        gtk_entry_set_text( GTK_ENTRY( entry ), "" );
    }
}

void wcisnieto_Usun( GtkWidget * button, gpointer data )
{

    GtkTreeSelection * sel;
    GtkTreeModel * model;
    GtkTreeIter wybrany_wiersz;

    // Pobranie zaznaczenia
    sel = gtk_tree_view_get_selection( GTK_TREE_VIEW( treeview ) );

    if( gtk_tree_selection_get_selected( sel, & model, & wybrany_wiersz ) )
         gtk_list_store_remove( GTK_LIST_STORE( model ), & wybrany_wiersz );

}

void wcisnieto_Zmien( GtkWidget * entry, gpointer data )
{

    GtkTreeSelection * sel;
    GtkTreeModel * model;
    GtkTreeIter wybrany_wiersz;

    sel = gtk_tree_view_get_selection( GTK_TREE_VIEW( treeview ) );

    if( gtk_tree_selection_get_selected( sel, & model, & wybrany_wiersz ) )
    {
        const gchar * tekst;

        tekst = gtk_entry_get_text( GTK_ENTRY( entry ) );

        if( strlen( tekst ) )
        {
            gtk_list_store_set( GTK_LIST_STORE( model ), & wybrany_wiersz, KOLUMNA_OSOBA, tekst, - 1 );
            gtk_entry_set_text( GTK_ENTRY( entry ), "" );
        }
    }

    // Odznacz wybrany wiersz
    gtk_tree_selection_unselect_iter( sel, & wybrany_wiersz );
}



void zmiana_Zaznaczenia( GtkTreeSelection * sel, GtkListStore * lista )
{
    GtkTreeIter zaznaczony_wiersz;

    // Sprawdzenie czy wiersz jest zaznaczony i odpowiednio aktywacja/dezaktywacja przycisków
    if( gtk_tree_selection_get_selected( sel, NULL, & zaznaczony_wiersz ) )
    {
        gtk_widget_set_sensitive( przycisk_usun, TRUE );
        gtk_widget_set_sensitive( przycisk_zmien, TRUE );
    }
    else
    {
        gtk_widget_set_sensitive( przycisk_usun, FALSE );
        gtk_widget_set_sensitive( przycisk_zmien, FALSE );
    }
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


    GtkWidget * okno, * vbox, * hbox;
    GtkWidget * label, * entry, * przycisk;
    GtkTreeViewColumn * kolumna;
    GtkCellRenderer * komorka;
    GtkListStore * lista;
    GtkTreeSelection * sel;


    gtk_init( & argc, & argv );

    // Utworzenie okna z połączeniem sygnału destroy
    okno = gtk_window_new( GTK_WINDOW_TOPLEVEL );
    gtk_window_set_title( GTK_WINDOW( okno ), "TreeView2" );
    gtk_window_set_default_size( GTK_WINDOW( okno ), 300, 200 );
    g_signal_connect( okno, "destroy", G_CALLBACK( gtk_main_quit ), NULL );

    vbox = gtk_vbox_new( FALSE, 2 );
    gtk_container_add( GTK_CONTAINER( okno ), vbox );


    // Utworzenie kontrolki GtkTreeView z dodaniem jej do okna
    treeview = gtk_tree_view_new();
    gtk_box_pack_start( GTK_BOX( vbox ), treeview, TRUE, TRUE, 0 );
    //gtk_container_add (GTK_CONTAINER(okno), treeview);

    // Utworzenie komórki tekstowej, utworzenie kolumny z nazwą Osoby oraz dołączenie komórki wraz z ustawieniem atrybutu text wskazującego na pozycje 0 modelu. Dodanie kolumny do kontrolki
    komorka = gtk_cell_renderer_text_new();
    kolumna = gtk_tree_view_column_new_with_attributes( "Osoby", komorka, "text", 0, NULL );
    gtk_tree_view_append_column( GTK_TREE_VIEW( treeview ), kolumna );

    // Utworzenie "listy" 1 elementowej, 1 kolumna typu tekstowego
    lista = gtk_list_store_new( ILOSC_KOLUMN, G_TYPE_STRING );


    // Dołączenie modelu do kontrolki
    gtk_tree_view_set_model( GTK_TREE_VIEW( treeview ), GTK_TREE_MODEL( lista ) );

    g_object_unref( lista );

    sel = gtk_tree_view_get_selection( GTK_TREE_VIEW( treeview ) );
    g_signal_connect( sel, "changed", G_CALLBACK( zmiana_Zaznaczenia ), lista );

    // Utworzenie 2 elementowego kontenera hbox
    hbox = gtk_hbox_new( FALSE, 14 );

    // Utworzenie kontrolki tekstowej z tekstem Osoba i dodanie jej do kontenera hbox
    label = gtk_label_new( "Osoba" );
    gtk_box_pack_start( GTK_BOX( hbox ), label, FALSE, FALSE, 0 );

    // Utworzenie kontrolki wpisu i dodanie jej do kontenera hbox
    entry = gtk_entry_new();
    gtk_box_pack_start( GTK_BOX( hbox ), entry, TRUE, TRUE, 0 );

    // Utworzenie przycisku Dodaj, dodanie go do kontenera hbox, powiązanie sygnału cliked przycisku z funkcją wcisnieto_Dodaj
    przycisk = gtk_button_new_with_label( "Dodaj" );
    gtk_box_pack_start( GTK_BOX( hbox ), przycisk, FALSE, TRUE, 5 );
    g_signal_connect_swapped( przycisk, "clicked", G_CALLBACK( wcisnieto_Dodaj ), entry );

    // Utworzenie przycisku Usuń, dodanie go do kontenera hbox, powiązanie sygnału cliked przycisku z funkcją wcisnieto_Usun oraz ustawienie przycisku jako nieaktywnego
    przycisk_usun = gtk_button_new_with_label( "Usuń" );
    gtk_box_pack_start( GTK_BOX( hbox ), przycisk_usun, FALSE, TRUE, 0 );
    g_signal_connect( przycisk_usun, "clicked", G_CALLBACK( wcisnieto_Usun ), NULL );
    gtk_widget_set_sensitive( przycisk_usun, FALSE );

    // Utworzenie przycisku Zmień, dodanie go do kontenera hbox, powiązanie sygnału cliked przycisku z funkcją wcisnieto_Zmien oraz ustawienie przycisku jako nieaktywnego
    przycisk_zmien = gtk_button_new_with_label( "Zmień" );
    gtk_box_pack_start( GTK_BOX( hbox ), przycisk_zmien, FALSE, TRUE, 5 );
    g_signal_connect_swapped( przycisk_zmien, "clicked", G_CALLBACK( wcisnieto_Zmien ), entry );
    gtk_widget_set_sensitive( GTK_WIDGET( przycisk_zmien ), FALSE );

    // Dodanie kontenera poziomego hbox do kontenera pionowego vbox
    gtk_box_pack_start( GTK_BOX( vbox ), hbox, FALSE, FALSE, 0 );


    gtk_widget_show_all( okno );

    gtk_main();

    return 0;
}



