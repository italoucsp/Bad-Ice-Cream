#include "Hielo.h"
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

Hielo::Hielo(sf::Sprite &s){

    this->s = s;
}

void Hielo::Draw(int m[15][15],int x,int y,sf::RenderWindow &app){
    posx = x*50;
    posy = y*50;
    s.setPosition(posx,posy-25);
    app.draw(s);
}
