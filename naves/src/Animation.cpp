#include "Animation.h"
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

Animation::Animation(int x,int y,int w,int h,int cantidad,string direct){

    this->cantidad = cantidad;
    if(direct=="largo"){
        for(int i=0;i<cantidad;i++){
            FramesVector.push_back(sf::IntRect(x+i*w,y,w,h));
            cout << x+i*w << endl;
            cout << y << endl;
            cout << w << endl;
            cout << h << endl;
        }
    }
    if(direct=="alto"){
        for(int i=0;i<cantidad;i++){
            FramesVector.push_back(sf::IntRect(x,y+i*w,w,h));
            cout << y+i*w << endl;
        }
    }
}

void Animation::Update(sf::Sprite &s){
    s.setTextureRect(FramesVector[cont]);
    cont++;
    if(cont==cantidad){
        cont = 0;
    }
}
