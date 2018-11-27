#include "Objeto.h"
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

bool Objeto::Detector(int m[15][15],int x,int y,bool up,bool down,bool left,bool right){
    if(up==true){
        if(m[y-1][x] == 1 || m[y-1][x] == 9 || m[y-1][x] == 8){
            return true;
        }
    }
    if(down==true){
        if(m[y+1][x] == 1 || m[y+1][x] == 9 || m[y+1][x] == 8){
            return true;
        }
    }
    if(left==true){
        if(m[y][x-1] == 1 || m[y][x-1] == 9 || m[y][x-1] == 8){
            return true;
        }
    }
    if(right==true){
        if(m[y][x+1] == 1 || m[y][x+1] == 9 || m[y][x+1] == 8){
            return true;
        }
    }
    return false;
}

void Objeto::Animation(int x,int y,int w,int h,string direct,sf::Sprite &s,int cant){
    if(direct == "largo"){
        if(speed%9==0){
            s.setTextureRect(sf::IntRect(x+cont*w,y,w,h));
        }
    }
    if(direct == "alto"){
        if(speed%9==0){
            s.setTextureRect(sf::IntRect(x,y+cont*h,w,h));
        }
    }
    cont++;
    speed++;
    if(cont == cant){cont = 0;}
    if(speed == cant*speed){speed=0;}
}

void Objeto::notLoopAnimation(int x,int y,int w,int h,string direct,sf::Sprite &s,int cant){
    cantt = cant;
    if(direct == "largo"){
        if(speed%9==0){
            s.setTextureRect(sf::IntRect(x+cont*w,y,w,h));
        }
    }
    if(direct == "alto"){
        if(speed%9==0){
            s.setTextureRect(sf::IntRect(x,y+cont*h,w,h));
        }
    }
    if(cont == cant){cont=cant;}
    else cont++;
    speed++;
    if(speed == cant*speed){speed=0;}
}



























