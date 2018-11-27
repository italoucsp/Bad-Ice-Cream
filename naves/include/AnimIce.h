#ifndef ANIMICE_H
#define ANIMICE_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Objeto.h"

using namespace std;

class AnimIce:public Objeto
{
    public:
        int posx,posy;
        AnimIce(sf::Sprite&);
        bool is_creating=false;
        void Draw(int [15][15],int,int,sf::RenderWindow&);

};

#endif // ANIMICE_H
