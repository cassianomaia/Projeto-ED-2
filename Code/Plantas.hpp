#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include <sstream>

using namespace std;

class Plantas{

public:
	Plantas (float width, float height);
	~Plantas();

	void draw(sf::RenderWindow &window);
	void PositionPlants(int posicaox, int posicaoy);

private:

	int posicaox, posicaoy;
	int planta, money;
	int icereja, imelancia, itomate, icenoura, ibrocolis, ibeterraba;

	sf::Font font;
	sf::Text atext[6];
	sf::Text dinheiro[2];

};

Plantas::Plantas(float width, float height){

	icereja = 5;
	icenoura = 5;
	itomate = 5;
	imelancia = 5; 
	ibeterraba = 5;
	ibrocolis = 5;

	money = 0;

	if (!font.loadFromFile("../Fonts/barn.otf")){
		//handle error
	}


	std::ostringstream ss0;
	ss0 << icereja << endl;
	atext[0].setFont(font);
	atext[0].setColor(sf::Color::Black);
	atext[0].setPosition(sf::Vector2f(25,550));	
	atext[0].setCharacterSize(30);	
	atext[0].setString(ss0.str());

	std::ostringstream ss1;
	ss1 << imelancia << endl;
	atext[1].setFont(font);
	atext[1].setColor(sf::Color::Black);
	atext[1].setPosition(sf::Vector2f(92,550));	
	atext[1].setCharacterSize(30);	
	atext[1].setString(ss1.str());

	std::ostringstream ss2;
	ss2 << itomate << endl;
	atext[2].setFont(font);
	atext[2].setColor(sf::Color::Black);
	atext[2].setPosition(sf::Vector2f(152,550));	
	atext[2].setCharacterSize(30);	
	atext[2].setString(ss2.str());

	std::ostringstream ss3;
	ss3 << icenoura << endl;
	atext[3].setFont(font);
	atext[3].setColor(sf::Color::Black);
	atext[3].setPosition(sf::Vector2f(205,550));	
	atext[3].setCharacterSize(30);	
	atext[3].setString(ss3.str());

	std::ostringstream ss4;
	ss4 << ibrocolis << endl;
	atext[4].setFont(font);
	atext[4].setColor(sf::Color::Black);
	atext[4].setPosition(sf::Vector2f(275,550));	
	atext[4].setCharacterSize(30);	
	atext[4].setString(ss4.str());

	std::ostringstream ss5;
	ss5 << ibeterraba << endl;
	atext[5].setFont(font);
	atext[5].setColor(sf::Color::Black);
	atext[5].setPosition(sf::Vector2f(320,550));	
	atext[5].setCharacterSize(30);	
	atext[5].setString(ss5.str());

	dinheiro[0].setFont(font);
	dinheiro[0].setColor(sf::Color::Black);
	dinheiro[0].setPosition(sf::Vector2f(580,27));	
	dinheiro[0].setCharacterSize(40);	
	dinheiro[0].setString("DINHEIRO: ");

	std::ostringstream ss6;
	ss6 << money << endl;
	dinheiro[1].setFont(font);
	dinheiro[1].setColor(sf::Color::Black);
	dinheiro[1].setPosition(sf::Vector2f(730,27));	
	dinheiro[1].setCharacterSize(40);	
	dinheiro[1].setString(ss6.str());


	

	planta = -1;

}

Plantas::~Plantas(){

}

void Plantas::draw(sf::RenderWindow &window){
	for(int i=0; i < 6; i++){
		window.draw(atext[i]);
	}
	for(int j=0; j < 2; j++){
		window.draw(dinheiro[j]);
	}
}


void Plantas::PositionPlants(int posicaox, int posicaoy){

	if (posicaoy>=498 && posicaoy<=549){
		if (posicaox>= 4 && posicaox<=66){
			planta = 0;
			std::cout << "Cereja" << std::endl;
				icereja--;
				if (icereja >= 0){
					std::ostringstream ss0;
					ss0 << icereja << endl;
					atext[0].setString(ss0.str());
				}
				
		}
	}
	if (posicaoy>=498 && posicaoy<=551){
		if (posicaox>= 68 && posicaox<=125){
			planta = 1;
			std::cout << "Melancia" << std::endl;
			imelancia--;
			if (imelancia >= 0){
					std::ostringstream ss1;
					ss1 << imelancia << endl;
					atext[1].setString(ss1.str());
				}
		}
	}
	if (posicaoy>=498 && posicaoy<=555){
		if (posicaox>= 134 && posicaox<=189){
			planta = 2;
			std::cout << "Tomate" << std::endl;
			itomate--;
			if (itomate >= 0){
					std::ostringstream ss2;
					ss2 << itomate << endl;
					atext[2].setString(ss2.str());
				}

		}	
	}
	if (posicaoy>=485 && posicaoy<=562){
		if (posicaox>= 199 && posicaox<=245){
			planta = 3;
			std::cout << "Cenoura" << std::endl;
			icenoura--;
			if (icenoura >= 0){
					std::ostringstream ss3;
					ss3 << icenoura << endl;
					atext[3].setString(ss3.str());
				}
		}	
	}
	if (posicaoy>=498 && posicaoy<=560){
		if (posicaox>= 248 && posicaox<=307){
			planta = 4;
			std::cout << "Brócolis" << std::endl;
			ibrocolis--;
			if (ibrocolis >= 0){
					std::ostringstream ss4;
					ss4 << ibrocolis << endl;
					atext[4].setString(ss4.str());
				}
		}	
	}
	if (posicaoy>=484 && posicaoy<=564){
		if (posicaox>= 313 && posicaox<=342){
			planta = 5;
			std::cout << "Beterraba" << std::endl;
			ibeterraba--;
			if (ibeterraba >= 0){
					std::ostringstream ss5;
					ss5 << ibeterraba << endl;
					atext[5].setString(ss5.str());
				}
		}	
	}

	cout << planta << endl;
}

