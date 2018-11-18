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
    protected:
        int spx,spy;
};

#endif // OBJETO_H
