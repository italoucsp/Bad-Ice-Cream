#include "Player.h"
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

Player::Player(sf::Sprite &s,int m[15][15])

{
    int px,py;
    for(int y=1;y<14;y++){
        for(int x=1;x<14;x++){
            if(m[y][x]==2){
                px = x;
                py = y;
            }
        }
    }
    posx = px*50;
    posy = py*50;
    spx = posx;
    spy = posy-18;
    this->s = s;
}

int Player::getPosx(){return posx/50;}

int Player::getPosy(){return posy/50;}

void Player::Controls(sf::RenderWindow &app,int m[15][15]){
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){app.close();}
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){isMove=true;up=true;down=left=right=false;Move(m,getPosx(),getPosy());}
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){isMove=true;down=true;up=left=right=false;Move(m,getPosx(),getPosy());}
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){isMove=true;left=true;down=up=right=false;Move(m,getPosx(),getPosy());}
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){isMove=true;right=true;down=left=up=false;Move(m,getPosx(),getPosy());}
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){isPressed = true;}
}

void Player::Move(int m[15][15],int x,int y){
    if(isMove==true && m[y][x]==2){
        if(Detector(m,x,y,up,down,left,right)==false){
            m[y][x] = 0;
            if(up==true){y -= 1;}
            if(down==true){y += 1;}
            if(left==true){x -= 1;}
            if(right==true){x += 1;}
            m[y][x] = 2;
            isMove = false;
        }
    }
}

void Player::SpawnIce(int m[15][15],int x,int y){
    if(Detector(m,x,y,up,down,left,right)==false){
        if(up==true){y -= 1;}
        if(down==true){y += 1;}
        if(left==true){x -= 1;}
        if(right==true){x += 1;}
        if(m[y][x]==0){
            m[y][x] = 1;
        }
    }
    if(Detector(m,x,y,up,down,left,right)==true){
        if(up==true){y -= 1;}
        if(down==true){y += 1;}
        if(left==true){x -= 1;}
        if(right==true){x += 1;}
        if(m[y][x]==1){
            m[y][x] = 0;
        }
    }
}

void Player::Draw(int m[15][15],int x,int y,sf::RenderWindow &app){
    if(isPressed == true){
        SpawnIce(m,getPosx(),getPosy());
        isPressed = false;
    }
    posx = x*50;
    posy = y*50;
    s.setTextureRect(sf::IntRect(0,0,50,64));
    s.setPosition(posx,posy-18);
    app.draw(s);
}

