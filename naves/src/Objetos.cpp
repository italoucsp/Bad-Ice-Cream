#include "Objetos.h"
#include <iostream>
#include <SFML/Graphics.hpp>

void Objetos::Draw(sf::RenderWindow &road){
    s.setPosition(posx,posy);
    road.draw(s);
}
