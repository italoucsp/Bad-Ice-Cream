#include "Miscelanea.h"
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

Miscelanea::Miscelanea(sf::Sprite &s){

    this->s = s;
}

void Miscelanea::Draw(int m[15][15],int x,int y,sf::RenderWindow &app){
    posx = x*50;
    posy = y*50;
    if(m[x][y]==9)
        s.setPosition(posx,posy-50);
    if(m[x][y]==8)
        s.setPosition(posx,posy-25);
    app.draw(s);
}
