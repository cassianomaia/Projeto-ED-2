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
	sf::Font font;
	sf::Text player[6];
};

Plantas::Plantas(float width, float height){

	if (!font.loadFromFile("../Fonts/barn.otf")){
		//handle error
	}

	player[0].setFont(font);
	player[0].setColor(sf::Color::Black);
	player[0].setString("00");
	player[0].setPosition(sf::Vector2f(175,60));	
	player[0].setCharacterSize(60);	

	player[1].setFont(font);
	player[1].setColor(sf::Color::Black);
	player[1].setString("00");
	player[1].setPosition(sf::Vector2f(350,280));	
	player[1].setCharacterSize(60);	

	player[2].setFont(font);
	player[2].setColor(sf::Color::Black);
	player[2].setString("00");
	player[2].setPosition(sf::Vector2f(270, 350));	
	player[2].setCharacterSize(60);	

	player[3].setFont(font);
	player[3].setColor(sf::Color::Black);
	player[3].setString("00");
	player[3].setPosition(sf::Vector2f(350, 420));	
	player[3].setCharacterSize(60);	

	player[4].setFont(font);
	player[4].setColor(sf::Color::Black);
	player[4].setString("00");
	player[4].setPosition(sf::Vector2f(350, 420));	
	player[4].setCharacterSize(60);	

	player[5].setFont(font);
	player[5].setColor(sf::Color::Black);
	player[5].setString("00");
	player[5].setPosition(sf::Vector2f(350, 420));	
	player[5].setCharacterSize(60);	

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

		}
	}
	if (posicaoy>=498 && posicaoy<=551){
		if (posicaox>= 68 && posicaox<=125){
			planta = 1;
			std::cout << "Melancia" << std::endl;


		}
	}
	if (posicaoy>=498 && posicaoy<=555){
		if (posicaox>= 134 && posicaox<=189){
			planta = 2;
			std::cout << "Tomate" << std::endl;

		}	
	}
	if (posicaoy>=485 && posicaoy<=562){
		if (posicaox>= 199 && posicaox<=245){
			planta = 3;
			std::cout << "Cenoura" << std::endl;

		}	
	}
	if (posicaoy>=498 && posicaoy<=560){
		if (posicaox>= 248 && posicaox<=307){
			planta = 4;
			std::cout << "Brócolis" << std::endl;

		}	
	}
	if (posicaoy>=484 && posicaoy<=564){
		if (posicaox>= 313 && posicaox<=342){
			planta = 5;
			std::cout << "Beterraba" << std::endl;

		}	
	}

	cout << planta << endl;
	//return planta;
}

