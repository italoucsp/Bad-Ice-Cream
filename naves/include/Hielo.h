#ifndef HIELO_H
#define HIELO_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Objeto.h"

using namespace std;

class Hielo:public Objeto
{
    public:
        Hielo(sf::Sprite&);
        void Draw(int [15][15],int,int,sf::RenderWindow&);

    private:
        int posx,posy;
        sf::Sprite s;
};

#endif // HIELO_H
