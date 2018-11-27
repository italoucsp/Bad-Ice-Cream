#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Objeto.h"
#include "Hielo.h"

using namespace std;

class Player:public Objeto
{
    public:
        Player(sf::Sprite&,int [15][15]);
        void Controls(sf::RenderWindow&,int [15][15],sf::Sprite&);
        int getPosx();
        int getPosy();
        void Move(int [15][15],int,int);
        void SpawnIce(int [15][15],int,int,sf::Sprite&);
        void DestroyIce(int [15][15],int,int);
        void MoveSprite(int &,int &,bool &);
        void Draw(int [15][15],int,int,sf::RenderWindow&);

    private:
        int posx,posy;
        bool up=false,left=false,right=false;
        bool mov;
        bool down = true,isMove = false,isPressed = false,movement=false;
        int cont2 = 0;
};

#endif // PLAYER_H
