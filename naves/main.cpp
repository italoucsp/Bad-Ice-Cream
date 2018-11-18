#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.h"


using namespace std;

int const widthscreen = 750;
int const heightscreen = 800;

int main()
{
    sf::RenderWindow app(sf::VideoMode(widthscreen,heightscreen),"Bad Ice");
    Game BadIce;
    BadIce.Run(app);
    return 0;

}
