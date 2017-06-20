#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>

using namespace std;

class Plantas{

public:
	Plantas (float width, float height);
	~Plantas();

	void draw(sf::RenderWindow &window);
	void PositionPlants(int posicaox, int posicaoy);

private:

	int posicaox, posicaoy;
	int planta;
	int quantidadecej, quantidademel, quantidadetom, quantidadecen, quantidadebro, quantidadebet;

	sf::Font font;
	sf::Text player[6];
};

Plantas::Plantas(float width, float height){

	quantidadecej = 5;
	quantidademel = 5;
	quantidadetom = 5;
	quantidadecen = 5; 
	quantidadebro = 5;
	quantidadebet = 5;

	if (!font.loadFromFile("../Fonts/barn.otf")){
		//handle error
	}

	player[0].setFont(font);
	player[0].setColor(sf::Color::Black);
	player[0].setString("05");
	player[0].setPosition(sf::Vector2f(25,550));	
	player[0].setCharacterSize(30);	

	player[1].setFont(font);
	player[1].setColor(sf::Color::Black);
	player[1].setString("05");
	player[1].setPosition(sf::Vector2f(92,550));	
	player[1].setCharacterSize(30);	

	player[2].setFont(font);
	player[2].setColor(sf::Color::Black);
	player[2].setString("05");
	player[2].setPosition(sf::Vector2f(152, 550));	
	player[2].setCharacterSize(30);	

	player[3].setFont(font);
	player[3].setColor(sf::Color::Black);
	player[3].setString("05");
	player[3].setPosition(sf::Vector2f(205, 550));	
	player[3].setCharacterSize(30);	

	player[4].setFont(font);
	player[4].setColor(sf::Color::Black);
	player[4].setString("05");
	player[4].setPosition(sf::Vector2f(270, 550));	
	player[4].setCharacterSize(30);	

	player[5].setFont(font);
	player[5].setColor(sf::Color::Black);
	player[5].setString("05");
	player[5].setPosition(sf::Vector2f(315, 550));	
	player[5].setCharacterSize(30);	


	planta = -1;

}

Plantas::~Plantas(){

}

void Plantas::draw(sf::RenderWindow &window){
	for(int i=0; i < 6; i++){
		window.draw(player[i]);
	}
}


void Plantas::PositionPlants(int posicaox, int posicaoy){

	if (posicaoy>=498 && posicaoy<=549){
		if (posicaox>= 4 && posicaox<=66){
			planta = 0;
			std::cout << "Cereja" << std::endl;
			quantidadecej--;
			if (quantidadecej==4){
				player[0].setString("04");
			}
			if(quantidadecej==3){
				player[0].setString("03");
			}
			if(quantidadecej==2){
				player[0].setString("02");
			}
			if(quantidadecej==1){
				player[0].setString("01");
			}
			if(quantidadecej==0){
				player[0].setString("00");
			}
			if(quantidadecej < 0){
				//não pega mais a plantinha
			}


		}
	}
	if (posicaoy>=498 && posicaoy<=551){
		if (posicaox>= 68 && posicaox<=125){
			planta = 1;
			std::cout << "Melancia" << std::endl;
			quantidademel--;
			if (quantidademel==4){
				player[1].setString("04");
			}
			if(quantidademel==3){
				player[1].setString("03");
			}
			if(quantidademel==2){
				player[1].setString("02");
			}
			if(quantidademel==1){
				player[1].setString("01");
			}
			if(quantidademel==0){
				player[1].setString("00");
			}
			if(quantidademel < 0){
				//não pega mais a plantinha
			}


		}
	}
	if (posicaoy>=498 && posicaoy<=555){
		if (posicaox>= 134 && posicaox<=189){
			planta = 2;
			std::cout << "Tomate" << std::endl;
			quantidadetom--;
			if (quantidadetom==4){
				player[2].setString("04");
			}
			if(quantidadetom==3){
				player[2].setString("03");
			}
			if(quantidadetom==2){
				player[2].setString("02");
			}
			if(quantidadetom==1){
				player[2].setString("01");
			}
			if(quantidadetom==0){
				player[2].setString("00");
			}
			if(quantidadetom < 0){
				//não pega mais a plantinha
			}

		}	
	}
	if (posicaoy>=485 && posicaoy<=562){
		if (posicaox>= 199 && posicaox<=245){
			planta = 3;
			std::cout << "Cenoura" << std::endl;
			quantidadecen--;
			if (quantidadecen==4){
				player[3].setString("04");
			}
			if(quantidadecen==3){
				player[3].setString("03");
			}
			if(quantidadecen==2){
				player[3].setString("02");
			}
			if(quantidadecen==1){
				player[3].setString("01");
			}
			if(quantidadecen==0){
				player[3].setString("00");
			}
			if(quantidadecen < 0){
				//não pega mais a plantinha
			}

		}	
	}
	if (posicaoy>=498 && posicaoy<=560){
		if (posicaox>= 248 && posicaox<=307){
			planta = 4;
			std::cout << "Brócolis" << std::endl;
			quantidadebro--;
			if (quantidadebro==4){
				player[4].setString("04");
			}
			if(quantidadebro==3){
				player[4].setString("03");
			}
			if(quantidadebro==2){
				player[4].setString("02");
			}
			if(quantidadebro==1){
				player[4].setString("01");
			}
			if(quantidadebro==0){
				player[4].setString("00");
			}
			if(quantidadebro < 0){
				//não pega mais a plantinha
			}

		}	
	}
	if (posicaoy>=484 && posicaoy<=564){
		if (posicaox>= 313 && posicaox<=342){
			planta = 5;
			std::cout << "Beterraba" << std::endl;
			quantidadebet--;
			if (quantidadebet==4){
				player[5].setString("04");
			}
			if(quantidadebet==3){
				player[5].setString("03");
			}
			if(quantidadebet==2){
				player[5].setString("02");
			}
			if(quantidadebet==1){
				player[5].setString("01");
			}
			if(quantidadebet==0){
				player[5].setString("00");
			}
			if(quantidadebet < 0){
				//não pega mais a plantinha
			}

		}	
	}

	cout << planta << endl;
	//return planta;
}

