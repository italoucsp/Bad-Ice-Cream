#include "Game.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Hielo.h"

using namespace std;

sf::Sprite Game::TtoS(char *rute,sf::Texture &t){
    t.loadFromFile(rute);
    t.setSmooth(true);
    sf::Sprite s;
    s.setTexture(t);
    return s;
}

void Game::Run(sf::RenderWindow &app){
    sf::Texture ba;
    sf::Texture pl;
    sf::Texture ic;

    char *ice = "Images/bloque.png";
    char *bg = "Images/background.png";
    char *player = "Images/stand1.png";
    int nivel1[15][15] = {{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
                          {9,1,0,0,0,0,0,0,0,0,0,0,0,0,9},
                          {9,0,0,0,0,0,0,0,0,0,0,0,0,0,9},
                          {9,0,0,0,0,0,0,0,0,0,0,0,0,0,9},
                          {9,0,0,0,0,0,1,1,1,1,0,0,0,0,9},
                          {9,0,0,0,1,0,0,0,0,0,0,1,0,0,9},
                          {9,0,0,0,1,0,0,0,0,0,0,1,0,0,9},
                          {9,0,0,0,1,0,0,0,0,0,0,1,0,0,9},
                          {9,0,0,0,1,0,0,0,0,0,0,1,0,0,9},
                          {9,0,0,0,0,1,2,0,0,0,0,0,0,0,9},
                          {9,0,0,0,0,0,1,1,1,1,0,0,0,0,9},
                          {9,0,0,0,0,0,0,1,1,0,0,0,0,0,9},
                          {9,0,0,0,0,0,0,0,0,0,0,0,0,0,9},
                          {9,1,0,0,0,0,0,0,0,0,1,0,0,0,9},
                          {9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},};
    sf::Sprite Ice = TtoS(ice,ic);
    sf::Sprite Background = TtoS(bg,ba);
    sf::Sprite Icecream = TtoS(player,pl);

    Background.setPosition(50,50);

    Player helado(Icecream,nivel1);
    Hielo hielo(Ice);

    while(app.isOpen()){
        app.setFramerateLimit(FPS);
        app.clear(sf::Color (200,200,200));
        app.draw(Background);
        for(int y=1;y<14;y++){
            for(int x=1;x<14;x++){
                if(nivel1[y][x]==2){
                    helado.Controls(app,nivel1);
                    helado.Draw(nivel1,x,y,app);
                }
                if(nivel1[y][x]==1){
                    hielo.Draw(nivel1,x,y,app);
                }
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
