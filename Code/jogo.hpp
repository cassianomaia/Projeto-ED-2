#include "cScreen.hpp"
#include "Plantas.hpp"
#include <SFML/Graphics.hpp>

class jogo : public cScreen{
private:
    int posicaox, posicaoy, posicao;

public:
	jogo(void);
	virtual int Run(sf::RenderWindow &window);
};

jogo::jogo(void){

}

int jogo::Run(sf::RenderWindow &window){

    //Imagem slot baixo direita
    sf::Texture slot1;
    if(!slot1.loadFromFile("../Images/vazio.png")){
        std::cout << "Error" << std::endl;
    }
    sf::Sprite Slot1(slot1);
    Slot1.setPosition(sf::Vector2f(30,-10));

    //Imagem slot baixo esquerda
    sf::Texture slot2;
    if(!slot2.loadFromFile("../Images/vazio.png")){
        std::cout << "Error" << std::endl;
    }
    sf::Sprite Slot2(slot2);
    Slot2.setPosition(sf::Vector2f(-36,-32));

    //Imagem slot cima esquerda
    sf::Texture slot3;
    if(!slot3.loadFromFile("../Images/vazio.png")){
        std::cout << "Error" << std::endl;
    }
    sf::Sprite Slot3(slot3);
    Slot3.setPosition(sf::Vector2f(20,-70));

    //Imagem slot cima direita
    sf::Texture slot4;
    if(!slot4.loadFromFile("../Images/vazio.png")){
        std::cout << "Error" << std::endl;
    }
    sf::Sprite Slot4(slot4);
    Slot4.setPosition(sf::Vector2f(86,-48));

    //Background
    sf::Sprite background;
    sf::Texture texture;
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
                            window.close();
                        break;
                        case sf::Keyboard::Space:
                            return 0;
                        break;
                    }
                    
                    break;

                case sf::Event::Closed:
                    window.close();
                    break;
                
            }

        }
        
        window.clear();
        window.draw(background);
        player.draw(window);
        window.draw(Slot1);
        window.draw(Slot2);
        window.draw(Slot3);
        window.draw(Slot4);
        window.display();

    }
    
    return (-1);
}