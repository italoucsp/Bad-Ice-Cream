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
    if(is_creating==true)notLoopAnimation(0,0,50,75,"largo",s,5);
    else s.setTextureRect(sf::IntRect(0,0,50,75));
    s.setPosition(posx,posy-25);
    app.draw(s);
}
