#include "cScreen.hpp"
#include <SFML/Graphics.hpp>
//#include <SFML/Audio.hpp>


class perdeu : public cScreen{
private:
    sf::Sprite background;
    sf::Texture texture;
    sf::Texture htp;
    sf::Text textperdeu;
    sf::Text button;
    sf::Font font;
    int posicaox, posicaoy;


public:
	perdeu(void);
	virtual int Run(sf::RenderWindow &window);
};

perdeu::perdeu(void){

}

int perdeu::Run(sf::RenderWindow &window){


    if (!font.loadFromFile("../Fonts/barn.otf")){
        std::cout << "Error" << std::endl;
    }

    textperdeu.setFont(font);
    textperdeu.setColor(sf::Color::Black);
    textperdeu.setString("GAME OVER");
    textperdeu.setPosition(sf::Vector2f(190,60));  
    textperdeu.setCharacterSize(110);  

    button.setFont(font);
    button.setColor(sf::Color::Black);
    button.setString("Voltar ao Menu");
    button.setPosition(sf::Vector2f(220,250));  
    button.setCharacterSize(60);  

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

            std::cout << posicaox << " , "<< posicaoy << std::endl;
          
            switch(event.type){
                case sf::Event::MouseButtonPressed:
                   if (posicaoy>=281 && posicaoy<=311){
                        if (posicaox>= 220 && posicaox<=574){
                            return 0;
                        }
                    } 
                break;
            	case sf::Event::MouseMoved:
            	   if (posicaoy>=281 && posicaoy<=311){
                        if (posicaox>= 220 && posicaox<=574){
                            button.setColor(sf::Color::Red);
                        }
                    }else{
                        button.setColor(sf::Color::Black);
                    }
                break;
            }

        }

        window.draw(background);
        window.draw(textperdeu);
        window.draw(button);
        window.display();
    }
	return (-1);
}