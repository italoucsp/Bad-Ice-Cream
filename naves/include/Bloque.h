#ifndef BLOQUE_H
#define BLOQUE_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Objetos.h"


class Bloque:public Objetos
{
    public:
        Bloque();
        Bloque(sf::Sprite&);
        void Draw(sf::RenderWindow&);
};

#endif // BLOQUE_H
