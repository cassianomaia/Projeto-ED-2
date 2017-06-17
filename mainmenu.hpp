#include "cScreen.hpp"
#include "Menu.hpp"
#include <SFML/Graphics.hpp>

class mainmenu : public cScreen{
private:

public:
	mainmenu(void);
	virtual int Run(sf::RenderWindow &Tela);
};

mainmenu::mainmenu(void){

}

int mainmenu::Run(sf::RenderWindow &window){
    sf::View view(sf::FloatRect(0, 0, 550, 450));

    window.setView(view);

    sf::Sprite background;

    sf::Texture texture;

    if(!texture.loadFromFile("fazenda.jpeg")){
        std::cout << "Error" << std::endl;
    }

    background.setTexture(texture);

    /*sf::Sprite sprite;
    sprite.setTexture(texture);
    sprite.setScale(sf::Vector2f(0.75, 0.75));
    sprite.setPosition(sf::Vector2f(110,10));*/

    Menu menu(window.getSize().x, window.getSize().y);

    while (window.isOpen()){
        
        sf::Event event;

        while (window.pollEvent(event)){

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
                window.close();
            }

            switch(event.type){
                case sf::Event::KeyReleased:
                    switch(event.key.code){
                        case sf::Keyboard::Up:
                            menu.MoveUp();
                        break;
                        
                        case sf::Keyboard::Down:
                            menu.MoveDown();
                        break;

                        case sf::Keyboard::Return:
                            return menu.GetPressedItem();
                        break;
                    }
                    
                    break;

                case sf::Event::Closed:
                    window.close();
                    break;
                
            }
        }

        /*if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            
            std::cout << "Pressed" << std::endl;
            
        }

        //std::cout << sf::Mouse::getPosition(window).x << std::endl;
        std::cout << sf::Mouse::getPosition(window).x << std::endl;

        sf::Mouse::setPosition(sf::vector21(40,50));*/

        window.clear();
        window.draw(background);
        menu.draw(window);
        //window.draw(sprite);
        window.display();

    }
    
	return (-1);
}