#ifndef OBJETO_H
#define OBJETO_H
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

class Objeto
{
    public:
        virtual void Draw(int [15][15],int,int,sf::RenderWindow&)=0;
        bool Detector(int [15][15],int,int,bool,bool,bool,bool);
        void Animation(int,int,int,int,string,sf::Sprite&,int);
        void notLoopAnimation(int,int,int,int,string,sf::Sprite&,int);
        int cont=0;
        int cantt;
    protected:
        int spx,spy;
        sf::Sprite s;
        sf::Sprite c;
        int speed=0;
};

#endif // OBJETO_H
