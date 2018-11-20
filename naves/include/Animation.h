#ifndef ANIMATION_H
#define ANIMATION_H
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

class Animation
{
    public:
        Animation(int,int,int,int,int,string);
        void Update(sf::Sprite&);
    protected:
        int frames=0,cont=0;
        int cantidad;
        vector<sf::IntRect> FramesVector;
};

#endif // ANIMATION_H
