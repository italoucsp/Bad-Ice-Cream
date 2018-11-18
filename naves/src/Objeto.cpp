#include "Objeto.h"
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

bool Objeto::Detector(int m[15][15],int x,int y,bool up,bool down,bool left,bool right){
    if(up==true){
        if(m[y-1][x] == 1 || m[y-1][x] == 9){
            return true;
        }
    }
    if(down==true){
        if(m[y+1][x] == 1 || m[y+1][x] == 9){
            return true;
        }
    }
    if(left==true){
        if(m[y][x-1] == 1 || m[y][x-1] == 9){
            return true;
        }
    }
    if(right==true){
        if(m[y][x+1] == 1 || m[y][x+1] == 9){
            return true;
        }
    }
    return false;
}
