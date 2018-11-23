#ifndef HIELO_H
#define HIELO_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Objeto.h"

using namespace std;

class Hielo:public Objeto
{
    public:
        int posx,posy;
        Hielo(sf::Sprite&);
        bool is_creating;
        void Draw(int [15][15],int,int,sf::RenderWindow&);

    private:
};

#endif // HIELO_H
