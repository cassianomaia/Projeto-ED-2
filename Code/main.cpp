#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "Screens.hpp"
    
int main(){
    int meta = 0;
    std::vector<cScreen*> Screens;
    int screen = 0; 

    sf::RenderWindow window(sf::VideoMode(800, 600), "Little Farm");
    sf::Music music;

    mainmenu s0;
    Screens.push_back(&s0);
    jogo s1(meta);
    Screens.push_back(&s1);
    howto s2;
    Screens.push_back(&s2);
    ganhou s3;
    Screens.push_back(&s3);
    perdeu s4;
    Screens.push_back(&s4);

    while (screen >= 0){
        switch (screen = Screens[screen]->Run(window)){
            case 0:
                meta = 0;
            break;
            case 1:
                meta += 500;
                Screens[1] = new jogo(meta);
            break;
            case 2:
                Screens[2] = new howto;
            break;
            case 3:
                Screens[3] = new ganhou;
            break;
            case 4:
                Screens[4] = new perdeu;
                meta = 0;
            break;
            //case 5:
                //window.close();
            //break;
        }
    }
    return -1;
}