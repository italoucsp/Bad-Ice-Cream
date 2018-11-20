#ifndef MISCELANEA_H
#define MISCELANEA_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Objeto.h"

using namespace std;

class Miscelanea:public Objeto
{
    public:
        Miscelanea(sf::Sprite&);
        void Draw(int [15][15],int,int,sf::RenderWindow&);

    private:
        int posx,posy;
};
#endif // MISCELANEA_H
