/* 
 * File:   Grafico.hpp
 * Author: mariana
 *
 * Created on August 18, 2015, 8:13 PM
 */

#ifndef GRAFICO_HPP
#define	GRAFICO_HPP

#include "ListaEnc.cpp"
#include "Ponto.hpp"
class Grafico {
    public:
        Grafico(int i) { 
            id = i; 
            pontos = new ListaEnc<Ponto>();
        }
        void adicionaPonto(int x, int y) {
            Ponto p(x, y);
            pontos->adiciona(p);
        }
        ListaEnc<Ponto>* getPontos() {
            return pontos;
        }
    protected:
        int id;
        ListaEnc<Ponto>* pontos;
        Grafico() { }
};
#endif	/* GRAFICO_HPP */