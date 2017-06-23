#include "cScreen.hpp"
#include <SFML/Graphics.hpp>
//#include <SFML/Audio.hpp>


class howto : public cScreen{
private:
    sf::Texture texture;
    sf::Texture htp;
    sf::Text text;
    sf::Text button;
    sf::Font font;
    int posicaox, posicaoy, posicao;
    int index;


public:
	howto(void);
	virtual int Run(sf::RenderWindow &window);
};

howto::howto(void){

}

int howto::Run(sf::RenderWindow &window){

    index = 0;
    posicao = 0;

    sf::Sprite background;

    if(!texture.loadFromFile("../Images/imagens_howtoplay/1.png")){
        std::cout << "Error" << std::endl;
    }

    background.setTexture(texture);

    if (!font.loadFromFile("../Fonts/barn.otf")){
        std::cout << "Error" << std::endl;
    }

    button.setFont(font);
    button.setColor(sf::Color::Black);
    button.setString("NEXT");
    button.setPosition(sf::Vector2f(650,525));  
    button.setCharacterSize(50);   


    while (window.isOpen()){
    	posicaoy = sf::Mouse::getPosition(window).y;
        posicaox = sf::Mouse::getPosition(window).x;

        sf::Event event;
        // Checa os eventos em loop
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close(); 
            }
            if (event.type == sf::Event::KeyPressed){
                if (event.key.code == sf::Keyboard::Escape){
                    return 0;
                }
            }
            switch(event.type){
                case sf::Event::MouseButtonPressed:
                    switch(event.key.code){
                        case sf::Mouse::Left:
                        	std::cout << posicaox << " , " << posicaoy << std::endl;
                           if(posicaox >= 650 && posicaox <= 740){
                            	if (posicaoy >= 545 && posicaoy <= 571){
                            		posicao = 1;
                            		index++;
                            	}
                            }
                        break;
                    }
            	
            	case sf::Event::MouseMoved:
            		button.setColor(sf::Color::Black);
                    if(posicaox >= 650 && posicaox <= 740){
                        if (posicaoy >= 545 && posicaoy <= 571){
                            button.setColor(sf::Color::Red);
                        }
                    }                       	
                break;         
            }

        }

        if (index == 1){
        	if(!texture.loadFromFile("../Images/imagens_howtoplay/2.png")){
    		}

        }
        else if (index == 2){
        	if(!texture.loadFromFile("../Images/imagens_howtoplay/3.png")){
		    }
        }
        else if (index == 3){
        	if(!texture.loadFromFile("../Images/imagens_howtoplay/4.png")){
        	}
		    
        }
        else if (index == 4){
        	if(!texture.loadFromFile("../Images/imagens_howtoplay/5.png")){
		    }
        }
        else if (index == 5){
        	if(!texture.loadFromFile("../Images/imagens_howtoplay/6.png")){
		    }
        }
        else if (index == 6){
        	if(!texture.loadFromFile("../Images/imagens_howtoplay/7.png")){
		    }
        }
        else if(index == 7){
        	return 0;
        }

        window.draw(background);
        window.draw(text);
        //window.draw(howtoplay);
        window.draw(button);
        window.display();
    }
	return (-1);
}