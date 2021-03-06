#include "cScreen.hpp"
#include "Plantas.hpp"
#include "estrutura.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <ctime>
#include <sstream>

using namespace std;

class jogo : public cScreen{
private:
    SpotPlantar spots;
    Lista lista;
    Planta mouseplanta;
    Planta retirarslot;
    Planta lixo;
    bool ok;
    bool jataplantado1 = false;
    bool jataplantado2 = false;
    bool jataplantado3 = false;
    bool jataplantado4 = false;
    int valor1;
    int planta;
    int tempo = 0;    
    int metaatual = 0;
    int posicaox, posicaoy, posicao;
    int planta1, planta2, planta3, planta4, planta5, planta6;
    int mousestate;
    int countdown = 60;
    int countdown_vaca = 10;
    int countdown_slot1 = -1;
    int countdown_slot2 = -1;
    int countdown_slot3 = -1;
    int countdown_slot4 = -1;
    sf::Clock clockgeral;
    sf::Font font;
    sf::Text timerText;
    sf::Text timerhead;
    std::string countdownString;
    std::ostringstream converter;
    sf::Texture slotvazio;
    sf::Texture semeado;
    sf::Texture vaquinha;
    sf::Texture vaquinha_leite;
    sf::Texture texcereja;
    sf::Texture texmelancia;
    sf::Texture textomate;
    sf::Texture texcenoura;
    sf::Texture texbrocolis;
    sf::Texture texbeterraba;
    sf::Texture slotcereja;
    sf::Texture slotmelancia;
    sf::Texture slottomate;
    sf::Texture slotcenoura;
    sf::Texture slotbrocolis;
    sf::Texture slotbeterraba;
    sf::Sprite mousesprite;
    sf::Sprite background;
    sf::Texture texture;
    sf::Music music;

public:
	jogo(int meta);
	virtual int Run(sf::RenderWindow &window);
};

jogo::jogo(int meta){
    this->metaatual = meta;
}

int jogo::Run(sf::RenderWindow &window){
    lista.Insere();
    if (!font.loadFromFile("../Fonts/barn.otf")){
        std::cout << "Error" << std::endl;
    }

    converter << countdown;
    countdownString = converter.str();
    timerText.setFont(font);
    timerText.setString(countdownString);
    timerText.setColor(sf::Color::Black);
    timerText.setPosition(730, 0);
    timerText.setCharacterSize(40);
    timerhead.setFont(font);
    timerhead.setString("Tempo restante:");
    timerhead.setColor(sf::Color::Black);
    timerhead.setPosition(473, 0);
    timerhead.setCharacterSize(40);

    if(!semeado.loadFromFile("../Images/semeado.png")){
        std::cout << "Error" << std::endl;
    }

    if(!slotvazio.loadFromFile("../Images/vazio.png")){
        std::cout << "Error" << std::endl;
    }
    //Imagem slot baixo direita
    sf::Sprite Slot1(slotvazio);
    Slot1.setPosition(sf::Vector2f(220,380));

    //Imagem slot baixo esquerda
    sf::Sprite Slot2(slotvazio);
    Slot2.setPosition(sf::Vector2f(132,360));

    //Imagem slot cima esquerda
    sf::Sprite Slot3(slotvazio);
    Slot3.setPosition(sf::Vector2f(191,310));

    //Imagem slot cima direita
    sf::Sprite Slot4(slotvazio);
    Slot4.setPosition(sf::Vector2f(280,330));

    //Vaquinha
    if(!vaquinha.loadFromFile("../Images/acordada.png")){
        std::cout << "Error" << std::endl;
    }
    sf::Sprite Vaquinha(vaquinha);
    Vaquinha.setPosition(sf::Vector2f(0,0));

    if(!vaquinha_leite.loadFromFile("../Images/dormindo_com_balde.png")){
        std::cout << "Error" << std::endl;
    }

    //mouse textures
    if(!texcereja.loadFromFile("../Images/Mouse/cereja.png")){
        std::cout << "Error" << std::endl;
    }
    if(!texmelancia.loadFromFile("../Images/Mouse/melancia.png")){
        std::cout << "Error" << std::endl;
    }
    if(!textomate.loadFromFile("../Images/Mouse/tomate.png")){
        std::cout << "Error" << std::endl;
    }
    if(!texcenoura.loadFromFile("../Images/Mouse/cenoura.png")){
        std::cout << "Error" << std::endl;
    }
    if(!texbrocolis.loadFromFile("../Images/Mouse/brocolis.png")){
        std::cout << "Error" << std::endl;
    }
    if(!texbeterraba.loadFromFile("../Images/Mouse/beterraba.png")){
        std::cout << "Error" << std::endl;
    }

    //Slots plantados textures
    if(!slotcereja.loadFromFile("../Images/cereja.png")){
        std::cout << "Error" << std::endl;
    }
    if(!slotmelancia.loadFromFile("../Images/melancia.png")){
        std::cout << "Error" << std::endl;
    }
    if(!slottomate.loadFromFile("../Images/tomate.png")){
        std::cout << "Error" << std::endl;
    }
    if(!slotcenoura.loadFromFile("../Images/cenoura.png")){
        std::cout << "Error" << std::endl;
    }
    if(!slotbrocolis.loadFromFile("../Images/brocolis.png")){
        std::cout << "Error" << std::endl;
    }
    if(!slotbeterraba.loadFromFile("../Images/beterraba.png")){
        std::cout << "Error" << std::endl;
    }

    //Background
    if(!texture.loadFromFile("../Images/fundo_com_retangulo.bmp")){
        std::cout << "Error" << std::endl;
    }
    background.setTexture(texture);

    Plantas player(window.getSize().x, window.getSize().y, metaatual);

    std::cout << lista.Exibe(0) << " " << lista.Exibe(1) << " " << lista.Exibe(2) << " " << lista.Exibe(3) << " " << lista.Exibe(4) << " " << lista.Exibe(5) <<endl;
    
    //Plantinhas

    sf::Sprite Planta1;
    Planta1.setPosition(sf::Vector2f(4,495));
    switch (lista.Exibe(0)){
        case 1:
            Planta1.setTexture(texcereja);
        break;
        case 2:
            Planta1.setTexture(texmelancia);
        break;
        case 3:
            Planta1.setTexture(textomate);
        break;
        case 4:
            Planta1.setTexture(texcenoura);
        break;
        case 5:
            Planta1.setTexture(texbrocolis);
        break;
        case 6:
            Planta1.setTexture(texbeterraba);
        break;
    }
    sf::Sprite Planta2;
    Planta2.setPosition(sf::Vector2f(60,495));
    switch (lista.Exibe(1)){
        case 1:
            Planta2.setTexture(texcereja);
        break;
        case 2:
            Planta2.setTexture(texmelancia);
        break;
        case 3:
            Planta2.setTexture(textomate);
        break;
        case 4:
            Planta2.setTexture(texcenoura);
        break;
        case 5:
            Planta2.setTexture(texbrocolis);
        break;
        case 6:
            Planta2.setTexture(texbeterraba);
        break;
    }

    sf::Sprite Planta3;
    Planta3.setPosition(sf::Vector2f(120,495));
    switch (lista.Exibe(2)){
        case 1:
            Planta3.setTexture(texcereja);
        break;
        case 2:
            Planta3.setTexture(texmelancia);
        break;
        case 3:
            Planta3.setTexture(textomate);
        break;
        case 4:
            Planta3.setTexture(texcenoura);
        break;
        case 5:
            Planta3.setTexture(texbrocolis);
        break;
        case 6:
            Planta3.setTexture(texbeterraba);
        break;
    }

    sf::Sprite Planta4;
    Planta4.setPosition(sf::Vector2f(170,495));
    switch (lista.Exibe(3)){
        case 1:
            Planta4.setTexture(texcereja);
        break;
        case 2:
            Planta4.setTexture(texmelancia);
        break;
        case 3:
            Planta4.setTexture(textomate);
        break;
        case 4:
            Planta4.setTexture(texcenoura);
        break;
        case 5:
            Planta4.setTexture(texbrocolis);
        break;
        case 6:
            Planta4.setTexture(texbeterraba);
        break;
    }
    sf::Sprite Planta5;
    Planta5.setPosition(sf::Vector2f(230,495));
    switch (lista.Exibe(4)){
        case 1:
            Planta5.setTexture(texcereja);
        break;
        case 2:
            Planta5.setTexture(texmelancia);
        break;
        case 3:
            Planta5.setTexture(textomate);
        break;
        case 4:
            Planta5.setTexture(texcenoura);
        break;
        case 5:
            Planta5.setTexture(texbrocolis);
        break;
        case 6:
            Planta5.setTexture(texbeterraba);
        break;
    }

    sf::Sprite Planta6;
    Planta6.setPosition(sf::Vector2f(280,495));
    switch (lista.Exibe(5)){
        case 1:
            Planta6.setTexture(texcereja);
        break;
        case 2:
            Planta6.setTexture(texmelancia);
        break;
        case 3:
            Planta6.setTexture(textomate);
        break;
        case 4:
            Planta6.setTexture(texcenoura);
        break;
        case 5:
            Planta6.setTexture(texbrocolis);
        break;
        case 6:
            Planta6.setTexture(texbeterraba);
        break;
    }


    while (window.isOpen()){
        
        sf::Event event;

        while (window.pollEvent(event)){
            posicaoy = sf::Mouse::getPosition(window).y;
            posicaox = sf::Mouse::getPosition(window).x;

            switch(event.type){
                case sf::Event::MouseButtonPressed:
                    switch(event.key.code){
                        case sf::Mouse::Left:
                            switch (mousestate = player.PositionPlants(posicaox, posicaoy)){
                                case -1:
                                    if (Slot1.getGlobalBounds().contains(posicaox, posicaoy )){
                                    	if(mouseplanta.getTipo() != 0 && jataplantado1 == false){
                                            spots.Insere(mouseplanta, 0); //aqui temos de retirar a planta do mouse, e deixar uma planta generica com valores zero
                                            Slot1.setTexture(semeado);    // /\ ou da pra usar o mouse state 
                                            countdown_slot1 = mouseplanta.getTempo(); 
                                            jataplantado1 = true;
    
                                            switch (mouseplanta.getTipo()){
									           case 1:
									               planta1 = 1;
									           break;
									           case 2:
									               planta1 = 2;
									           break;
									           case 3:
									               planta1 = 3;
									           break;
									   	   	   case 4:
									               planta1 = 4;
									           break;
									           case 5:
									               planta1 = 5;
									           break;
									           case 6:
									               planta1 = 6;
									           break;
									       }
                                            mouseplanta.removePlanta();
                                        }
                                    }
                                    else if(Slot2.getGlobalBounds().contains(posicaox, posicaoy )){
                                        if(mouseplanta.getTipo() != 0 && jataplantado2 == false){
                                            spots.Insere(mouseplanta, 1);
                                                Slot2.setTexture(semeado);
                                                countdown_slot2 = mouseplanta.getTempo();
                                                jataplantado2 = true;
    
                                            switch (mouseplanta.getTipo()){
									           case 1:
									               planta2 = 1;
									           break;
									           case 2:
									               planta2 = 2;
									           break;
									           case 3:
									               planta2 = 3;
									           break;
									   	   	   case 4:
									               planta2 = 4;
									           break;
									           case 5:
									               planta2 = 5;
									           break;
									           case 6:
									               planta2 = 6;
									           break;
									       }
                                            mouseplanta.removePlanta();                                      
                                        }
                                    }
                                    else if(Slot3.getGlobalBounds().contains(posicaox, posicaoy )){
                                        if(mouseplanta.getTipo() != 0 && jataplantado3 == false){
                                            spots.Insere(mouseplanta, 2);
                                            Slot3.setTexture(semeado);
                                            countdown_slot3 = mouseplanta.getTempo();
                                            jataplantado3 = true;
                                            switch (mouseplanta.getTipo()){
    									      case 1:
    									          planta3 = 1;
    									      break;
    									      case 2:
    									          planta3 = 2;
    									      break;
    									      case 3:
    									          planta3 = 3;
    									      break;
    									   	   case 4:
    									          planta3 = 4;
    									      break;
    									      case 5:
    									          planta3 = 5;
    									      break;
    									      case 6:
    									          planta3 = 6;
    									      break;
    									   }
                                            mouseplanta.removePlanta();
                                        }
                                    }
                                    else if(Slot4.getGlobalBounds().contains(posicaox, posicaoy )){
                                        if(mouseplanta.getTipo() != 0 && jataplantado4 == false){
                                            spots.Insere(mouseplanta, 3);                                        
                                                Slot4.setTexture(semeado);
                                                countdown_slot4 = mouseplanta.getTempo();
                                                jataplantado4 = true;
    
                                            switch (mouseplanta.getTipo()){
									           case 1:
									               planta4 = 1;
									           break;
									           case 2:
									               planta4 = 2;
									           break;
									           case 3:
									               planta4 = 3;
									           break;
									   	   	   case 4:
									               planta4 = 4;
									           break;
									           case 5:
									               planta4 = 5;
									           break;
									           case 6:
									               planta4 = 6;
									           break;
									       }
                                            mouseplanta.removePlanta();
                                        }
                                    }
                                break;
                                
                                case 0:
                                	mouseplanta = lista.Retira(0);
                                    //colocar lista insere abaixo de cada um
                                    // no final colocar para gerar os sprites novamente;                              
                                    switch (mouseplanta.getTipo()){
								        case 1:
											mousesprite.setTexture(texcereja);
                                        break;
								        case 2:
								            mousesprite.setTexture(texmelancia);
								        break;
								        case 3:
								            mousesprite.setTexture(textomate);
								        break;
								        case 4:
								            mousesprite.setTexture(texcenoura);
								        break;
								        case 5:
								            mousesprite.setTexture(texbrocolis);
								        break;
								        case 6:
								            mousesprite.setTexture(texbeterraba);
								        break;

								    }
                                    lista.Insere();
                                break;

                                case 1:
                                	mouseplanta = lista.Retira(1);

                                    switch (mouseplanta.getTipo()){
								        case 1:
											mousesprite.setTexture(texcereja);
								        break;
								        case 2:
								            mousesprite.setTexture(texmelancia);
								        break;
								        case 3:
								            mousesprite.setTexture(textomate);
								        break;
								        case 4:
								            mousesprite.setTexture(texcenoura);
								        break;
								        case 5:
								            mousesprite.setTexture(texbrocolis);
								        break;
								        case 6:
								            mousesprite.setTexture(texbeterraba);
								        break;
								    }

                                    lista.Insere();
                                break;

                                case 2:

                                	mouseplanta = lista.Retira(2);
                                    
                                    switch (mouseplanta.getTipo()){
								        case 1:
											mousesprite.setTexture(texcereja);
								        break;
								        case 2:
								            mousesprite.setTexture(texmelancia);
								        break;
								        case 3:
								            mousesprite.setTexture(textomate);
								        break;
								        case 4:
								            mousesprite.setTexture(texcenoura);
								        break;
								        case 5:
								            mousesprite.setTexture(texbrocolis);
								        break;
								        case 6:
								            mousesprite.setTexture(texbeterraba);
								        break;
								    } 
                                    lista.Insere();
                                break;

                                case 3:

                                	mouseplanta = lista.Retira(3);
                                    
                                    switch (mouseplanta.getTipo()){
								        case 1:
											mousesprite.setTexture(texcereja);
								        break;
								        case 2:
								            mousesprite.setTexture(texmelancia);
								        break;
								        case 3:
								            mousesprite.setTexture(textomate);
								        break;
								        case 4:
								            mousesprite.setTexture(texcenoura);
								        break;
								        case 5:
								            mousesprite.setTexture(texbrocolis);
								        break;
								        case 6:
								            mousesprite.setTexture(texbeterraba);
								        break;
								    }
                                    lista.Insere();
                                break;

                                case 4:

                                	mouseplanta = lista.Retira(4);
                                    
                                    switch (mouseplanta.getTipo()){
								        case 1:
											mousesprite.setTexture(texcereja);
								        break;
								        case 2:
								            mousesprite.setTexture(texmelancia);
								        break;
								        case 3:
								            mousesprite.setTexture(textomate);
								        break;
								        case 4:
								            mousesprite.setTexture(texcenoura);
								        break;
								        case 5:
								            mousesprite.setTexture(texbrocolis);
								        break;
								        case 6:
								            mousesprite.setTexture(texbeterraba);
								        break;
								    } 
                                    lista.Insere();
                                break;

                                case 5:

                                	mouseplanta = lista.Retira(5);
                                    
                                    switch (mouseplanta.getTipo()){
								        case 1:
											mousesprite.setTexture(texcereja);
								        break;
								        case 2:
								            mousesprite.setTexture(texmelancia);
								        break;
								        case 3:
								            mousesprite.setTexture(textomate);
								        break;
								        case 4:
								            mousesprite.setTexture(texcenoura);
								        break;
								        case 5:
								            mousesprite.setTexture(texbrocolis);
								        break;
								        case 6:
								            mousesprite.setTexture(texbeterraba);
								        break;
								    } 
                                    lista.Insere();
                                break;
                            }
                        break;
                    }


                case sf::Event::KeyReleased:
                    switch(event.key.code){
                        case sf::Keyboard::Escape:
                            return 0;
                        break;
                    } 
                break;

                case sf::Event::Closed:
                    window.close();
                break;
            }
        }

        //Cronômetro Geral   
        
        int timer = clockgeral.getElapsedTime().asSeconds();
        if (timer > 0 && countdown > 0){
            countdown--;
            if (countdown_vaca > 0){
                countdown_vaca--;
            }
            if (countdown_slot1 > 0){
                countdown_slot1--;
            }
            if (countdown_slot2 > 0){
                countdown_slot2--;
            }
            if (countdown_slot3 > 0){
                countdown_slot3--;
            }
            if (countdown_slot4 > 0){
                countdown_slot4--;
            }
            
            timerText.setString(to_string(countdown));
            clockgeral.restart();
        }

        if(countdown_vaca==0){
            Vaquinha.setTexture(vaquinha_leite);
            switch(event.type){
                case sf::Event::MouseButtonPressed:
                    
                    switch(event.key.code){

                        case sf::Mouse::Left:
                            if(player.RetirarLeite(posicaox, posicaoy) == 1){
                                countdown_vaca = 10;
                                Vaquinha.setTexture(vaquinha);
                                player.addmoney(50);
                            }
                        break;
                    }
            }
        }

        if (countdown_slot1 == 0){
	       	if(jataplantado1 == true){
	            switch (planta1){
    		        case 1:
    		            Slot1.setTexture(slotcereja);
    		        break;
    		        case 2:
    		            Slot1.setTexture(slotmelancia);
    		        break;
    		        case 3:
    		            Slot1.setTexture(slottomate);
    		        break;
    		   		case 4:
    		            Slot1.setTexture(slotcenoura);
    		        break;
    		        case 5:
    		            Slot1.setTexture(slotbrocolis);
    		        break;
    		        case 6:
    		            Slot1.setTexture(slotbeterraba);
    		        break;

		        }

                switch(event.type){
                    case sf::Event::MouseButtonPressed:                    
                        switch(event.key.code){
                            case sf::Mouse::Left:
                                if(Slot1.getGlobalBounds().contains(posicaox, posicaoy)){
                                    countdown_slot1 = -1;
                                    Slot1.setTexture(slotvazio);                                    
                                    lixo = spots.Retira(0, ok);
                                    player.addmoney(lixo.getValor());
                                    lixo.removePlanta();
                                    jataplantado1 = false;
                                }
                            break;
                        }
                    break;
                }
	        }

        }

    	if(countdown_slot2 == 0){
            if(jataplantado2 == true){
	            switch (planta2){
    		        case 1:
    		            Slot2.setTexture(slotcereja);
    		        break;
    		        case 2:
    		            Slot2.setTexture(slotmelancia);
    		        break;
    		        case 3:
    		            Slot2.setTexture(slottomate);
    		        break;
    		   		case 4:
    		            Slot2.setTexture(slotcenoura);
    		        break;
    		        case 5:
    		            Slot2.setTexture(slotbrocolis);
    		        break;
    		        case 6:
    		            Slot2.setTexture(slotbeterraba);
    		        break;
		        }

                switch(event.type){
                    case sf::Event::MouseButtonPressed:                    
                        switch(event.key.code){
                            case sf::Mouse::Left:
                                if(Slot2.getGlobalBounds().contains(posicaox, posicaoy)){
                                    countdown_slot2 = -1;
                                    Slot2.setTexture(slotvazio);                                    
                                    lixo = spots.Retira(1, ok);
                                    player.addmoney(lixo.getValor());
                                    lixo.removePlanta();
                                    jataplantado2 = false;
                                }
                            break;
                        }
                    break;
                }
	        }
       	}
                   
            
    	if(countdown_slot3 == 0){
            if(jataplantado3 == true){
	            switch (planta3){
    		        case 1:
    		            Slot3.setTexture(slotcereja);
    		        break;
    		        case 2:
    		            Slot3.setTexture(slotmelancia);
    		        break;
    		        case 3:
    		            Slot3.setTexture(slottomate);
    		        break;
    		   		case 4:
    		            Slot3.setTexture(slotcenoura);
    		        break;
    		        case 5:
    		            Slot3.setTexture(slotbrocolis);
    		        break;
    		        case 6:
    		            Slot3.setTexture(slotbeterraba);
    		        break;

		        }

                switch(event.type){
                    case sf::Event::MouseButtonPressed:                    
                        switch(event.key.code){
                            case sf::Mouse::Left:
                                if(Slot3.getGlobalBounds().contains(posicaox, posicaoy)){
                                    countdown_slot3 = -1;
                                    Slot3.setTexture(slotvazio);                                    
                                    lixo = spots.Retira(2, ok);
                                    player.addmoney(lixo.getValor());
                                    lixo.removePlanta();
                                    jataplantado3 = false;
                                }
                            break;
                        }
                    break;
                }
	        }
       	}
        

    	if(countdown_slot4 == 0){
            if(jataplantado4 == true){
	            switch (planta4){
    		        case 1:
    		            Slot4.setTexture(slotcereja);
    		        break;
    		        case 2:
    		            Slot4.setTexture(slotmelancia);
    		        break;
    		        case 3:
    		            Slot4.setTexture(slottomate);
    		        break;
    		   		case 4:
    		            Slot4.setTexture(slotcenoura);
    		        break;
    		        case 5:
    		            Slot4.setTexture(slotbrocolis);
    		        break;
    		        case 6:
    		            Slot4.setTexture(slotbeterraba);
    		        break;

		        }

                switch(event.type){
                    case sf::Event::MouseButtonPressed:                    
                        switch(event.key.code){
                            case sf::Mouse::Left:
                                if(Slot4.getGlobalBounds().contains(posicaox, posicaoy)){
                                    countdown_slot4 = -1;
                                    Slot4.setTexture(slotvazio);                                    
                                    lixo = spots.Retira(3, ok);
                                    player.addmoney(lixo.getValor());
                                    lixo.removePlanta();
                                    jataplantado4 = false;
                                }
                            break;
                        }
                    break;
                }
	        }
       	}

        switch (lista.Exibe(0)){
            case 1:
                Planta1.setTexture(texcereja);
            break;
            case 2:
                Planta1.setTexture(texmelancia);
            break;
            case 3:
                Planta1.setTexture(textomate);
            break;
            case 4:
                Planta1.setTexture(texcenoura);
            break;
            case 5:
                Planta1.setTexture(texbrocolis);
            break;
            case 6:
                Planta1.setTexture(texbeterraba);
            break;
    }
    switch (lista.Exibe(1)){
        case 1:
            Planta2.setTexture(texcereja);
        break;
        case 2:
            Planta2.setTexture(texmelancia);
        break;
        case 3:
            Planta2.setTexture(textomate);
        break;
        case 4:
            Planta2.setTexture(texcenoura);
        break;
        case 5:
            Planta2.setTexture(texbrocolis);
        break;
        case 6:
            Planta2.setTexture(texbeterraba);
        break;
    }
    switch (lista.Exibe(2)){
        case 1:
            Planta3.setTexture(texcereja);
        break;
        case 2:
            Planta3.setTexture(texmelancia);
        break;
        case 3:
            Planta3.setTexture(textomate);
        break;
        case 4:
            Planta3.setTexture(texcenoura);
        break;
        case 5:
            Planta3.setTexture(texbrocolis);
        break;
        case 6:
            Planta3.setTexture(texbeterraba);
        break;
    }
    switch (lista.Exibe(3)){
        case 1:
            Planta4.setTexture(texcereja);
        break;
        case 2:
            Planta4.setTexture(texmelancia);
        break;
        case 3:
            Planta4.setTexture(textomate);
        break;
        case 4:
            Planta4.setTexture(texcenoura);
        break;
        case 5:
            Planta4.setTexture(texbrocolis);
        break;
        case 6:
            Planta4.setTexture(texbeterraba);
        break;
    }
    switch (lista.Exibe(4)){
        case 1:
            Planta5.setTexture(texcereja);
        break;
        case 2:
            Planta5.setTexture(texmelancia);
        break;
        case 3:
            Planta5.setTexture(textomate);
        break;
        case 4:
            Planta5.setTexture(texcenoura);
        break;
        case 5:
            Planta5.setTexture(texbrocolis);
        break;
        case 6:
            Planta5.setTexture(texbeterraba);
        break;
    }
    switch (lista.Exibe(5)){
        case 1:
            Planta6.setTexture(texcereja);
        break;
        case 2:
            Planta6.setTexture(texmelancia);
        break;
        case 3:
            Planta6.setTexture(textomate);
        break;
        case 4:
            Planta6.setTexture(texcenoura);
        break;
        case 5:
            Planta6.setTexture(texbrocolis);
        break;
        case 6:
            Planta6.setTexture(texbeterraba);
        break;
    }


        mousesprite.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)));
        window.clear();
        window.draw(background);
        player.draw(window);
        window.draw(Slot4);
        window.draw(Slot3);
        window.draw(Slot2);
        window.draw(Slot1);
        window.draw(Vaquinha);
        window.draw(timerText);
        window.draw(timerhead);
        window.draw(Planta1);
        window.draw(Planta2);
        window.draw(Planta3);
        window.draw(Planta4);
        window.draw(Planta5);
        window.draw(Planta6);

        if (mousestate != -1){
            window.draw(mousesprite);
        }

        window.display();

        if (countdown == 0){
            if (player.FimJogo() == true){
                return 3;
            }else{
                return 4;
            }
        }

    }
    
    return (-1);
}