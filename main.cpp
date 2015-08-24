/* 
 * File:   main.c
 * Author: mariana
 *
 * Created on August 18, 2015, 7:19 PM
 */

#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "Reta.cpp"
#include "Ponto.hpp"

int main (int argc, char **argv) {
//    gtk_init(&argc, &argv);
//    GtkBuilder* builder;
//    GtkWidget* window;
//    GError* error = NULL;
//    
//    builder = gtk_builder_new();
//    if(!gtk_builder_add_from_file(builder, "glade_Trab1.glade", &error)) {
//        g_warning("%s", error->message);
//        g_free(error);
//        return (1);
//    }
//    
//    window = GTK_WIDGET(gtk_builder_get_object(builder, "window1"));
//    GtkWidget* button1 = GTK_WIDGET(gtk_builder_get_object(builder, "button1"));
//    
//    gtk_builder_connect_signals(builder, NULL);
//    gtk_widget_show_all(window);
//    gtk_main();
//    return 0;
    
    Reta r(0);
    r.adicionaPonto(1, 2);
    //r.adicionaPonto(2, 3);
    ListaEnc<Ponto>* l = r.getPontos();
    Ponto p = l->retira();
    std::cout << p.getX();
}
