#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Objeto.h"

using namespace std;

class Player:public Objeto
{
    public:
        Player(sf::Sprite&,int [15][15]);
        void Controls(sf::RenderWindow&,int [15][15]);
        int getPosx();
        int getPosy();
        void Move(int [15][15],int,int);
        void SpawnIce(int [15][15],int,int);
        void DestroyIce(int [15][15],int,int);
        void MoveSprite(int &,int &,bool &);
        void Draw(int [15][15],int,int,sf::RenderWindow&);

    private:
        int posx,posy;
        bool up=false,left=false,right=false;
        bool down = true,isMove = false,isPressed = false;
        sf::Sprite s;
        int cont = 0;
};

#endif // PLAYER_H
