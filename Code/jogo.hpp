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

    sf::Texture vaquinha;
    if(!vaquinha.loadFromFile("../Images/terra.bmp")){
        std::cout << "Error" << std::endl;
    }
    sf::Sprite Vaquinha_acordada(vaquinha);
    Vaquinha_acordada.setPosition(sf::Vector2f(150,150));


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
        window.draw(Vaquinha_acordada);
        window.display();

    }
    
    return (-1);
}