#include "cScreen.hpp"
#include "Plantas.hpp"
#include <SFML/Graphics.hpp>

class jogo : public cScreen{
private:
    int posicaox, posicaoy, posicao;
    int player;



public:
	jogo(void);
	virtual int Run(sf::RenderWindow &window);
};

jogo::jogo(void){

}

int jogo::Run(sf::RenderWindow &window){

    sf::Sprite background;
    sf::Texture texture;

    if(!texture.loadFromFile("principal_acordada.bmp")){
        std::cout << "Error" << std::endl;
    }

    background.setTexture(texture);

    while (window.isOpen()){
        sf::Event event;
        // Checa os eventos em loop
        while (window.pollEvent(event)){

            posicaoy = sf::Mouse::getPosition(window).y;
            posicaox = sf::Mouse::getPosition(window).x;

            if (event.type == sf::Event::Closed){
                window.close(); 
            }
            if (event.type == sf::Event::KeyPressed){
                if (event.key.code == sf::Keyboard::Space){
                    return 0;
                }
                if (event.key.code == sf::Keyboard::Escape){
                    window.close();
                }
            }

            switch(event.type){
                case sf::Event::MouseButtonPressed:
                    switch(event.key.code){

                        case sf::Mouse::Left:
                            std::cout << "Pressed" << std::endl;
                            std::cout << posicaox << " , "<< posicaoy << std::endl;
                            return player.PositionPlantas(posicaox, posicaoy);
                        break;
                    }
            break;
            }
        }

        window.clear(sf::Color::White);
        window.draw(background);
        window.display();
    }
	return (-1);
}