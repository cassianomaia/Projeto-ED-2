#include "cScreen.hpp"
#include <SFML/Graphics.hpp>
//#include <SFML/Audio.hpp>


class ganhou : public cScreen{
private:
    sf::Sprite background;
    sf::Texture texture;
    sf::Texture htp;
    sf::Text button1;
    sf::Text button2;
    sf::Text textganhou;
    sf::Font font;
    int posicaox, posicaoy;


public:
	ganhou(void);
	virtual int Run(sf::RenderWindow &window);
};

ganhou::ganhou(void){

}

int ganhou::Run(sf::RenderWindow &window){

    if (!font.loadFromFile("../Fonts/barn.otf")){
        std::cout << "Error" << std::endl;
    }

    textganhou.setFont(font);
    textganhou.setColor(sf::Color::Black);
    textganhou.setString("Parabéns!!");
    textganhou.setPosition(sf::Vector2f(175,60));  
    textganhou.setCharacterSize(100);  

    if(!texture.loadFromFile("../Images/menu_sem_texto.bmp")){
        std::cout << "Error" << std::endl;
    }
    
    background.setTexture(texture);

    


    while (window.isOpen()){
    	posicaoy = sf::Mouse::getPosition(window).y;
        posicaox = sf::Mouse::getPosition(window).x;

        sf::Event event;
        // Checa os eventos em loop
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close(); 
            }
            switch(event.type){
                case sf::Event::MouseButtonPressed:
                    
            	case sf::Event::MouseMoved:
            		                   	
                break;         
            }

        }

        window.draw(background);
        window.draw(textganhou);
        window.display();
    }
	return (-1);
}