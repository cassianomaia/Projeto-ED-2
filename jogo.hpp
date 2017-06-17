#include "cScreen.hpp"
#include <SFML/Graphics.hpp>

class jogo : public cScreen{
private:

public:
	jogo(void);
	virtual int Run(sf::RenderWindow &Tela);
};

jogo::jogo(void){

}

int jogo::Run(sf::RenderWindow &Tela){

    while (Tela.isOpen()){
        sf::Event event;
        // Checa os eventos em loop
        while (Tela.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                Tela.close(); 
            }
            if (event.type == sf::Event::KeyPressed){
                if (event.key.code == sf::Keyboard::Escape){
                    return 0;
                }
            }
        }

        Tela.clear(sf::Color::White);
        Tela.display();
    }
	return (-1);
}