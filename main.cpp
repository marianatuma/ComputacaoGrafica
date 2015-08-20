/* 
 * File:   main.c
 * Author: mariana
 *
 * Created on August 18, 2015, 7:19 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <gtk-3.0/gtk/gtk.h>
#include <iostream>
#include "ListaEnc.cpp"
#include "Grafico.hpp"

int main (int argc, char **argv) {
    ListaEnc<Grafico>* lista = new ListaEnc<Grafico>();
    Grafico* g = new Grafico(1);
    Grafico* h = new Grafico(2);
    Grafico* i = new Grafico(3);
    lista->adiciona(*g);
    lista->adiciona(*g);
    lista->adiciona(*g);
    lista->adiciona(*h);
    
    Grafico retiraDaPosicao = lista->retiraDaPosicao(2);
    lista->retira();
    Grafico retiraDoInicio = lista->retiraDoInicio();
    lista->retiraEspecifico(*g);
    
    bool b = lista->listaVazia();
    std::cout << b;
    
    
}
