#include "cScreen.hpp"
#include <SFML/Graphics.hpp>

class howto : public cScreen{
private:

public:
	howto(void);
	virtual int Run(sf::RenderWindow &window);
};

howto::howto(void){

}

int howto::Run(sf::RenderWindow &window){

    while (window.isOpen()){
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
        }
        window.clear(sf::Color::White);
        window.display();
    }
	return (-1);
}