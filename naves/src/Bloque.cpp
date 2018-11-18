#include "Bloque.h"
#include <iostream>
#include <SFML/Graphics.hpp>

Bloque::Bloque(){
    posx = 0;
    posy = 0;
}
Bloque::Bloque(sf::Sprite &sprite){
    s = sprite;
}

void Bloque::Draw(sf::RenderWindow &road){
    s.setPosition(posx,1000);
    road.draw(s);
}
