#include "Player.h"
#include "Hielo.h"
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

Player::Player(sf::Sprite &s,int m[15][15]){
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

void Player::Controls(sf::RenderWindow &app,int m[15][15],vector<Hielo> &hielos){
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){app.close();}
        if(cont%9==0){
            if(left==false || right==false){if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){isMove=true;up=true;down=left=right=false;Move(m,getPosx(),getPosy());}}
            if(left==false || right==false){if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){isMove=true;down=true;up=left=right=false;Move(m,getPosx(),getPosy());}}
            if(up==false || down==false){if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){isMove=true;left=true;down=up=right=false;Move(m,getPosx(),getPosy());}}
            if(up==false || down==false){if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){isMove=true;right=true;down=left=up=false;Move(m,getPosx(),getPosy());}}
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::N)){SpawnIce(m,getPosx(),getPosy(),hielos);}
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::M)){DestroyIce(m,getPosx(),getPosy(),hielos);}
        cont ++;
}

void Player::Move(int m[15][15],int x,int y){
    if(isMove==true && m[y][x]==2){
        if(Detector(m,x,y,up,down,left,right)==false){
            m[y][x] = 0;
            if(up==true && left==false && right==false){y -= 1;}
            if(down==true && left==false && right==false){y += 1;}
            if(left==true && up==false && down==false){x -= 1;}
            if(right==true && up==false && down==false){x += 1;}
            m[y][x] = 2;
        }
    }
}

void Player::SpawnIce(int m[15][15],int x,int y,vector<Hielo> &hielos){
    if(Detector(m,x,y,up,down,left,right)==false){
        if(up==true){
            for(int i=y;i > 0;i--){
                if(m[i-1][x]==0){m[i-1][x]=1;}
                else {break;}
            }
        }
        if(down==true){
            for(int i=y;i < 15;i++){
                if(m[i+1][x]==0){m[i+1][x]=1;}
                else {break;}
            }
        }
        if(left==true){
            for(int i=x;i > 0;i--){
                if(m[y][i-1]==0){m[y][i-1]=1;}
                else {break;}
            }
        }
        if(right==true){
            for(int i=x;i < 15;i++){
                if(m[y][i+1]==0){m[y][i+1]=1;}
                else {break;}
            }
        }
    }
}

void Player::DestroyIce(int m[15][15],int x,int y,vector<Hielo> &hielos){
    if(Detector(m,x,y,up,down,left,right)==true){
        if(up==true){
            for(int i=y;i > 0;i--){
                if(m[i-1][x]==1){m[i-1][x]=0;}
                else {break;}
            }
        }
        if(down==true){
            for(int i=y;i < 15;i++){
                if(m[i+1][x]==1){m[i+1][x]=0;}
                else {break;}
            }
        }
        if(left==true){
            for(int i=x;i > 0;i--){
                if(m[y][i-1]==1){m[y][i-1]=0;}
                else {break;}
            }
        }
        if(right==true){
            for(int i=x;i < 15;i++){
                if(m[y][i+1]==1){m[y][i+1]=0;}
                else {break;}
            }
        }
    }
}

void Player::MoveSprite(int &spx,int &spy,bool &isMove){
    if(isMove == true){
        if(up == true){
            if(spy > posy-18)
                spy -= 5;
        }
        if(down == true){
            if(spy < posy-18)
                spy += 5;
        }
        if(left == true){
            if(spx > posx)
                spx -= 5;
        }
        if(right == true){
            if(spx < posx)
                spx += 5;
        }
    }
    if(spx == posx && spy+18 == posy){isMove = false;}
}

void Player::Draw(int m[15][15],int x,int y,sf::RenderWindow &app){
    posx = x*50;
    posy = y*50;

    if(down==true && isMove==false)Animation(0,76,50,76,"largo",s,4);
    if(up==true && isMove==false)Animation(0,0,50,76,"largo",s,4);
    if(left==true && isMove==false)Animation(0,152,50,76,"largo",s,4);
    if(right==true && isMove==false)Animation(0,228,50,76,"largo",s,4);

    MoveSprite(spx,spy,isMove);
    s.setPosition(spx,spy);
    app.draw(s);
}

