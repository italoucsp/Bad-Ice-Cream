#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Hielo.h"
#include "Miscelanea.h"

using namespace std;

class Game
{
    public:
        sf::Sprite TtoS(char *,sf::Texture&);
        void Run(sf::RenderWindow&);
    private:
        int FPS = 60;
        vector<Hielo> Hielos;

};

#endif // GAME_H
