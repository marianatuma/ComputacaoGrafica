/* 
 * File:   Ponto.hpp
 * Author: mariana
 *
 * Created on August 21, 2015, 11:37 PM
 */

#ifndef PONTO_HPP
#define	PONTO_HPP

class Ponto {
    public:
        Ponto(int x, int y);
        int getX();
        int getY();
    private:
        int x, y;
};

#endif	/* PONTO_HPP */

