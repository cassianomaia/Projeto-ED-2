#include "cScreen.hpp"
#include "Plantas.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
#include <sstream>

using namespace std;

class jogo : public cScreen{
private:
    int posicaox, posicaoy, posicao;
    int countdown = 30;
    int countdown_vaca = 10;
    sf::Clock clock;
    sf::Clock clock2;
    sf::Font font;
    sf::Text timerText;
    sf::Text timerhead;
    std::string countdownString;
    std::ostringstream converter;
    sf::Texture slotvazio;
    sf::Texture vaquinha;
    sf::Texture vaquinha_leite;
    sf::Sprite background;
    sf::Texture texture;

public:
	jogo(void);
	virtual int Run(sf::RenderWindow &window);
};

jogo::jogo(void){

}

int jogo::Run(sf::RenderWindow &window){

    if (!font.loadFromFile("../Fonts/barn.otf")){
        std::cout << "Error" << std::endl;
    }

    converter << countdown;
    countdownString = converter.str();
    timerText.setFont(font);
    timerText.setString(countdownString);
    timerText.setColor(sf::Color::Black);
    timerText.setPosition(730, 0);
    timerText.setCharacterSize(40);
    timerhead.setFont(font);
    timerhead.setString("Tempo restante:");
    timerhead.setColor(sf::Color::Black);
    timerhead.setPosition(473, 0);
    timerhead.setCharacterSize(40);

    if(!slotvazio.loadFromFile("../Images/vazio.png")){
        std::cout << "Error" << std::endl;
    }
    //Imagem slot baixo direita
    sf::Sprite Slot1(slotvazio);
    Slot1.setPosition(sf::Vector2f(30,-10));

    //Imagem slot baixo esquerda
    sf::Sprite Slot2(slotvazio);
    Slot2.setPosition(sf::Vector2f(-36,-32));

    //Imagem slot cima esquerda
    sf::Sprite Slot3(slotvazio);
    Slot3.setPosition(sf::Vector2f(20,-70));

    //Imagem slot cima direita
    sf::Sprite Slot4(slotvazio);
    Slot4.setPosition(sf::Vector2f(86,-48));

    //Vaquinha
    if(!vaquinha.loadFromFile("../Images/ibagens_png/de_boa.png")){
        std::cout << "Error" << std::endl;
    }
    sf::Sprite Vaquinha(vaquinha);
    Vaquinha.setPosition(sf::Vector2f(0,0));

    if(!vaquinha_leite.loadFromFile("../Images/ibagens_png/dormindo_com_balde.png")){
        std::cout << "Error" << std::endl;
    }

    //Background
    if(!texture.loadFromFile("../Images/background.bmp")){
        std::cout << "Error" << std::endl;
    }
    background.setTexture(texture);

    Plantas player(window.getSize().x, window.getSize().y);


    while (window.isOpen()){
        
        sf::Event event;

        while (window.pollEvent(event)){
            posicaoy = sf::Mouse::getPosition(window).y;
            posicaox = sf::Mouse::getPosition(window).x;

            switch(event.type){
                case sf::Event::MouseButtonPressed:
                    
                    switch(event.key.code){

                        case sf::Mouse::Left:
                            std::cout << "Pressed" << std::endl;
                            std::cout << posicaox << " , "<< posicaoy << std::endl;
                            player.PositionPlants(posicaox, posicaoy);
                        break;
                    }

                case sf::Event::KeyReleased:
                    switch(event.key.code){
                                                
                        case sf::Keyboard::Escape:
                            return 0;
                        break;
                    }
                    
                    break;

                case sf::Event::Closed:
                    window.close();
                    break;
                
            }

        }

        //Cronômetro Geral
        int timer = clock.getElapsedTime().asSeconds();
        if (timer > 0 && countdown > 0){
            countdown--;
            timerText.setString(to_string(countdown));
            clock.restart();
        }

        int timer_vaca = clock2.getElapsedTime().asSeconds();
        if (timer_vaca > 0 && countdown_vaca > 0){
            countdown_vaca--;
            clock2.restart(); //
        }
        if(countdown_vaca==0){
            Vaquinha.setTexture(vaquinha_leite);
        }
        
        window.clear();
        window.draw(background);
        player.draw(window);
        window.draw(Slot1);
        window.draw(Slot2);
        window.draw(Slot3);
        window.draw(Slot4);
        window.draw(Vaquinha);
        window.draw(timerText);
        window.draw(timerhead);
        window.display();

    }
    
    return (-1);
}