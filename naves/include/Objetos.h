#ifndef OBJETOS_H
#define OBJETOS_H
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

class Objetos
{
    public:
        virtual void Draw(sf::RenderWindow&);
        int posx,posy,spx,spy;
        sf::Sprite s;
        int objt;
};

#endif // OBJETOS_H
