#include "Grafico.hpp"

class Reta : public Grafico {
    public:
        Reta(int i) : Grafico(i) {
            id = i;
            pontos = new ListaEnc<Ponto>();
        }
};
