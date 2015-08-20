#include "ListaEnc.hpp"
#include "Grafico.hpp"
#include <cstdlib>
#include <iostream>

template<typename T>
ListaEnc<T>::ListaEnc() {
    size = 0;
}


template <class T>
void ListaEnc<T>::adicionaNoInicio(const T& dado) {
    if(head == NULL) {
        head = new Elemento<T>(dado, NULL);
    } else {
    Elemento<T> *newHead;
    newHead = new Elemento<T>(dado, head);
    head = newHead;
    }
    size++;
}

template <class T>
T ListaEnc<T>::retiraDoInicio(){
    Elemento<T>* oldHead = head;
    Elemento<T>* newHead = oldHead->getProximo();
    head = newHead;
    return oldHead->getInfo();
    size--;
}

template <class T>
void ListaEnc<T>::eliminaDoInicio() {
    Elemento<T>* oldHead = head;
    Elemento<T>* newHead = oldHead->getProximo();
    head = newHead;
    delete oldHead;
    size--;
}

template <class T>
void ListaEnc<T>::adicionaNaPosicao(const T& dado, int pos) {
    if(pos < size){
        if(pos == 0){
            adicionaNoInicio(dado);
        } else {
            Elemento<T>* anterior = head;
            for (int i = 1; i < pos; i++) {
                anterior = anterior->getProximo();
            }

            Elemento<T>* proximo = anterior->getProximo();
            Elemento<T>* novo = new Elemento<T>(dado, proximo);
            anterior->setProximo(novo);
            size++;
        }
    }
    
}

template <class T>
int ListaEnc<T>::posicao(const T& dado) const {
    //if(contem(dado)) { //erro, contem não é const
        Elemento<T>* atual = head;
        Grafico d = static_cast<Grafico>(dado);
        for(int i = 0; i < size; i++) {
            Grafico e = static_cast<Grafico>(atual->getInfo());
            if(d.id == e.id){
                return i;
            } else {
                atual = atual->getProximo();
            }
        }    
    //}
    return -1;
}

template <class T>
T* ListaEnc<T>::posicaoMem(const T& dado) const {
//    Elemento<T>* atual = head;
//    int pos = 0;
//    Grafico d = static_cast<Grafico>(dado);
//    Grafico e(0);
//    while(pos < size) {
//        e = static_cast<Grafico>(atual->getInfo());
//        if(d.id = e.id) {
//            return *atual->getInfo();
//        } else {
//            atual = atual->getProximo();
//        }
//        pos++;
//    }
}

template <class T>
bool ListaEnc<T>::contem(const T& dado) {
    int pos = 0;
    Elemento<T>* atual = head;
    Grafico d = static_cast<Grafico>(dado);
    while(pos < size) {
        Grafico e = static_cast<Grafico>(atual->getInfo());
        if(d.id == e.id)
            return true;
        else
            atual = atual->getProximo();
        pos++;
    }    
    return false;
}

template <class T>
T ListaEnc<T>::retiraDaPosicao(int pos) {
    if(pos < size){
        if(pos = 0) {
            T e = retiraDoInicio();
        }
        Elemento<T>* anterior = head;
        for(int i = 1; i < pos; i++){
            anterior = anterior->getProximo();
        }
        Elemento<T>* e = anterior->getProximo();
        Elemento<T>* proximo = e->getProximo();
        anterior->setProximo(proximo);
        size--;
        return e->getInfo();
    }
}

template <class T>
void ListaEnc<T>::adiciona(const T& dado) {
    if(size == 0) {
        adicionaNoInicio(dado);
    }
    Elemento<T>* atual = head;
    Elemento<T>* novo = new Elemento<T>(dado, NULL);
    for(int i = 0; i < size-1; i++){
        atual = atual->getProximo();
    }
    atual->setProximo(novo);
    size++;
}

template <class T>
T ListaEnc<T>::retira(){
    Elemento<T>* atual = head;
    for(int i = 0; i < size-2; i++){
        atual = atual->getProximo();
    }
    Elemento<T>* r = atual->getProximo();
    atual->setProximo(NULL);
    size--;
    return r->getInfo();
} 

template <class T>
T ListaEnc<T>::retiraEspecifico(const T& dado) {
    int pos = posicao(dado);
    T retirado = retiraDaPosicao(pos); //size-- implicito
    return retirado;
}

template <class T>
void ListaEnc<T>::adicionaEmOrdem(const T& data) {
    //??
}

template <class T>
bool ListaEnc<T>::listaVazia() const {
    return size == 0;
}

template <class T>
bool ListaEnc<T>::igual(T dado1, T dado2) {
    return dado1 == dado2;
}

template <class T>
bool ListaEnc<T>::maior(T dado1, T dado2) {
    return dado1 > dado2;
}

template <class T>
bool ListaEnc<T>::menor(T dado1, T dado2) {
    return dado1 < dado2;
}