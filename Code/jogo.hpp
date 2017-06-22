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
    int mousestate;
    int countdown = 30;
    int countdown_vaca = 10;
    int countdown_slot0 = 0;
    int countdown_slot1 = 0;
    int countdown_slot2 = 0;
    int countdown_slot3 = 0;
    int countdown_slot4 = 0;
    int countdown_slot5 = 0;
    sf::Clock clockgeral;
    sf::Font font;
    sf::Text timerText;
    sf::Text timerhead;
    std::string countdownString;
    std::ostringstream converter;
    sf::Texture slotvazio;
    sf::Texture semeado;
    sf::Texture vaquinha;
    sf::Texture vaquinha_leite;
    sf::Texture texcereja;
    sf::Texture texmelancia;
    sf::Texture textomate;
    sf::Texture texcenoura;
    sf::Texture texbrocolis;
    sf::Texture texbeterraba;
    sf::Sprite mousesprite;
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

    if(!semeado.loadFromFile("../Images/ibagens_png/semente.png")){
        std::cout << "Error" << std::endl;
    }

    if(!slotvazio.loadFromFile("../Images/ibagens_png/terra5.png")){
        std::cout << "Error" << std::endl;
    }
    //Imagem slot baixo direita
    sf::Sprite Slot1(slotvazio);
    Slot1.setPosition(sf::Vector2f(200,420));

    //Imagem slot baixo esquerda
    sf::Sprite Slot2(slotvazio);
    Slot2.setPosition(sf::Vector2f(132,398));

    //Imagem slot cima esquerda
    sf::Sprite Slot3(slotvazio);
    Slot3.setPosition(sf::Vector2f(191,360));

    //Imagem slot cima direita
    sf::Sprite Slot4(slotvazio);
    Slot4.setPosition(sf::Vector2f(260,382));

    //Vaquinha
    if(!vaquinha.loadFromFile("../Images/ibagens_png/de_boa.png")){
        std::cout << "Error" << std::endl;
    }
    sf::Sprite Vaquinha(vaquinha);
    Vaquinha.setPosition(sf::Vector2f(0,0));

    if(!vaquinha_leite.loadFromFile("../Images/ibagens_png/dormindo_com_balde.png")){
        std::cout << "Error" << std::endl;
    }

    //mouse textures
    if(!texcereja.loadFromFile("../Images/Mouse/cereja.png")){
        std::cout << "Error" << std::endl;
    }
    if(!texmelancia.loadFromFile("../Images/Mouse/melancia.png")){
        std::cout << "Error" << std::endl;
    }
    if(!textomate.loadFromFile("../Images/Mouse/tomate.png")){
        std::cout << "Error" << std::endl;
    }
    if(!texcenoura.loadFromFile("../Images/Mouse/cenoura.png")){
        std::cout << "Error" << std::endl;
    }
    if(!texbrocolis.loadFromFile("../Images/Mouse/brocolis.png")){
        std::cout << "Error" << std::endl;
    }
    if(!texbeterraba.loadFromFile("../Images/Mouse/beterraba.png")){
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
                            switch (mousestate = player.PositionPlants(posicaox, posicaoy)){
                                case -1:
                                    if (Slot1.getGlobalBounds().contains(posicaox, posicaoy )){
                                        Slot1.setTexture(semeado);
                                        std::cout << "slot 1" << std::endl;
                                    }
                                    else if(Slot2.getGlobalBounds().contains(posicaox, posicaoy )){
                                        Slot2.setTexture(semeado);
                                        std::cout << "slot 2" << std::endl;
                                    }
                                    else if(Slot3.getGlobalBounds().contains(posicaox, posicaoy )){
                                        Slot3.setTexture(semeado);
                                        std::cout << "slot 3" << std::endl;
                                    }
                                    else if(Slot4.getGlobalBounds().contains(posicaox, posicaoy )){
                                        Slot4.setTexture(semeado);
                                        std::cout << "slot 4" << std::endl;
                                    }
                                break;
                                case 0:
                                    mousesprite.setTexture(texcereja);
                                break;

                                case 1:
                                    mousesprite.setTexture(texmelancia);
                                break;

                                case 2:
                                    mousesprite.setTexture(textomate);
                                break;

                                case 3:
                                    mousesprite.setTexture(texcenoura);
                                break;

                                case 4:
                                    mousesprite.setTexture(texbrocolis);
                                break;

                                case 5:
                                    mousesprite.setTexture(texbeterraba);
                                break;
                            }
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
        int timer = clockgeral.getElapsedTime().asSeconds();
        if (timer > 0 && countdown > 0){
            countdown--;
            if (countdown_vaca > 0){
                countdown_vaca--;
            }
            if (countdown_slot0 > 0){
                countdown_slot0--;
            }
            if (countdown_slot1 > 0){
                countdown_slot1--;
            }
            if (countdown_slot2 > 0){
                countdown_slot2--;
            }
            if (countdown_slot3 > 0){
                countdown_slot3--;
            }
            if (countdown_slot4 > 0){
                countdown_slot4--;
            }
            if (countdown_slot5 > 0){
                countdown_slot5--;
            }
            timerText.setString(to_string(countdown));
            clockgeral.restart();
        }

        if(countdown_vaca==0){
            Vaquinha.setTexture(vaquinha_leite);
            switch(event.type){
                case sf::Event::MouseButtonPressed:
                    
                    switch(event.key.code){

                        case sf::Mouse::Left:
                            std::cout << "Pressed" << std::endl;
                            std::cout << posicaox << " , "<< posicaoy << std::endl;
                            if(player.RetirarLeite(posicaox, posicaoy) == 1){
                                countdown_vaca = 10;
                                Vaquinha.setTexture(vaquinha);
                                player.addmoney(50);
                            }
                        break;
                    }
            }
        }


        mousesprite.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)));
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
        if (mousestate != -1){
            window.draw(mousesprite);
        }

        window.display();

    }
    
    return (-1);
}