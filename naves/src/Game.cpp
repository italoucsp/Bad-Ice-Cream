#include "Game.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Hielo.h"
#include "Miscelanea.h"

using namespace std;

sf::Sprite Game::TtoS(char *rute,sf::Texture &t){
    t.loadFromFile(rute);
    t.setSmooth(true);
    sf::Sprite s;
    s.setTexture(t);
    return s;
}

void Game::DrawIce(int m[15][15],sf::RenderWindow &app){
    for(int i=0;i<Hielos.size();i++){
        Hielos[i].Draw(m,Hielos[i].posx,Hielos[i].posy,app);
        if(Hielos[i].cont = 5){
            Hielos.erase(Hielos.begin()+i+1);
        }
    }
}
void Game::Run(sf::RenderWindow &app){
    sf::Texture ba;
    sf::Texture pl;
    sf::Texture ic;
    sf::Texture ich;
    sf::Texture icv;
    sf::Texture ob;
    sf::Texture ob2;

    char *ice = "Images/bloque.png";
    char *iceh = "Images/hielo.png";
    char *bg = "Images/background.png";
    char *player = "Images/icecream.png";
    char *tronco = "Images/tronco.png";
    char *tronc2 = "Images/tronco2.png";
    int nivel1[15][15] = {{9,8,9,8,9,8,9,8,9,8,9,8,9,8,9},
                          {8,1,1,0,0,0,0,0,0,0,0,0,1,1,8},
                          {9,1,0,0,0,0,0,0,0,0,0,0,0,1,9},
                          {8,0,0,0,0,0,0,0,0,0,0,0,0,0,8},
                          {9,0,0,0,0,1,1,0,1,1,0,0,0,0,9},
                          {8,0,0,0,0,0,0,0,0,0,0,0,0,0,8},
                          {9,0,0,1,0,0,0,0,0,0,0,1,0,0,9},
                          {8,0,0,1,0,0,0,2,0,0,0,1,0,0,8},
                          {9,0,0,1,0,0,0,0,0,0,0,1,0,0,9},
                          {8,0,0,0,0,0,0,0,0,0,0,0,0,0,8},
                          {9,0,0,0,0,1,1,0,1,1,0,0,0,0,9},
                          {8,0,0,0,0,0,0,0,0,0,0,0,0,0,8},
                          {9,1,0,0,0,0,0,0,0,0,0,0,0,1,9},
                          {8,1,1,0,0,0,0,0,0,0,0,0,1,1,8},
                          {9,8,9,8,9,8,9,8,9,8,9,8,9,8,9},};
    sf::Sprite Ice = TtoS(ice,ic);
    sf::Sprite Icehove = TtoS(iceh,ich);
    sf::Sprite Background = TtoS(bg,ba);
    sf::Sprite Icecream = TtoS(player,pl);
    sf::Sprite Troncos = TtoS(tronco,ob);
    sf::Sprite Troncos2 = TtoS(tronc2,ob2);

    Background.setPosition(50,50);

    Player helado(Icecream,nivel1);
    Hielo hielo(Ice);
    Miscelanea tronco1(Troncos);
    Miscelanea tronco2(Troncos2);

    while(app.isOpen()){
        app.setFramerateLimit(FPS);
        app.clear(sf::Color (200,200,200));
        app.draw(Background);
        for(int y=0;y<15;y++){
            for(int x=0;x<15;x++){
                if(nivel1[y][x]==2){
                    helado.Controls(app,nivel1,Hielos,Icehove);
                    helado.Draw(nivel1,x,y,app);
                }
                if(nivel1[y][x]==1){
                    hielo.Draw(nivel1,x,y,app);
                }
                if(nivel1[y][x]==8){
                    tronco2.Draw(nivel1,x,y,app);
                }
                if(nivel1[y][x]==9){
                    tronco1.Draw(nivel1,x,y,app);
                }
                DrawIce(nivel1,app);
            }
        }
        app.display();
        sf::Event e;
        while(app.pollEvent(e)){
            if(e.type == sf::Event::Closed)
                app.close();
        }
    }
}
