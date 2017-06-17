#include "cScreen.hpp"
#include <SFML/Graphics.hpp>

class jogo : public cScreen{
private:

public:
	jogo(void);
	virtual int Run(sf::RenderWindow &window);
};

jogo::jogo(void){

}

int jogo::Run(sf::RenderWindow &window){

    while (window.isOpen()){
        sf::Event event;
        // Checa os eventos em loop
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close(); 
            }
            if (event.type == sf::Event::KeyPressed){
                if (event.key.code == sf::Keyboard::Space){
                    return 0;
                }
            }
        }
        window.clear(sf::Color::White);
        window.display();
    }
	return (-1);
}