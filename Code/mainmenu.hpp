#include "cScreen.hpp"
#include "Menu.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


class mainmenu : public cScreen{
private:
    int posicaoy, posicaox;
    int SelectedItemIndex;
    sf::Music music;


public:
	mainmenu(void);
	virtual int Run(sf::RenderWindow &Tela);
};

mainmenu::mainmenu(void){

}

int mainmenu::Run(sf::RenderWindow &window){

    if (!music.openFromFile("../Sounds/CountrySong.ogg")){

    }
    music.setLoop(true);
    music.play();

    sf::Sprite background;
    sf::Texture texture;

    if(!texture.loadFromFile("../Images/menu_sem_texto.bmp")){
        std::cout << "Error" << std::endl;
    }

    background.setTexture(texture);

    Menu menu(window.getSize().x, window.getSize().y);

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
                            return menu.GetPressedItem(posicaox, posicaoy);
                        break;
                    }


                case sf::Event::Closed:
                    window.close();
                    break;
                
                case sf::Event::MouseMoved:
                	menu.Position(posicaox, posicaoy);
                	break;
            }

        }
        
        window.clear();
        window.draw(background);
        menu.draw(window);
        window.display();

    }
    
	return (-1);
}