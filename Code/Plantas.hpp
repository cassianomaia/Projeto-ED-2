#pragma once
#include <SFML/Graphics.hpp>
//#include <SFML/Audio.hpp>
#include <iostream>
#include <sstream>

using namespace std;

class Plantas{

public:
	Plantas (float width, float height, int x);
	~Plantas();

	void draw(sf::RenderWindow &window);
	int PositionPlants(int posicaox, int posicaoy);
	int RetirarLeite(int posicaox, int posicaoy);
	void addmoney(int qtd);
	bool FimJogo();


private:

	int posicaox, posicaoy;
	int planta, money = 0, leite, valorMeta = 0;


	sf::Font font;
	sf::Text atext[6];
	sf::Text dinheiro[2];
	sf::Text meta[2];

};

Plantas::Plantas(float width, float height, int x){
	valorMeta = x;

	if (!font.loadFromFile("../Fonts/barn.otf")){
		//handle error
	}

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

	meta[0].setFont(font);
	meta[0].setColor(sf::Color::Black);
	meta[0].setPosition(sf::Vector2f(638,55));	
	meta[0].setCharacterSize(40);	
	meta[0].setString("META: ");

	std::ostringstream ss7;
	ss7 << valorMeta << endl;
	meta[1].setFont(font);
	meta[1].setColor(sf::Color::Black);
	meta[1].setPosition(sf::Vector2f(730,55));	
	meta[1].setCharacterSize(40);	
	meta[1].setString(ss7.str());
	

	planta = -1;

}

Plantas::~Plantas(){

}

void Plantas::draw(sf::RenderWindow &window){
	for(int i=0; i < 6; i++){
		window.draw(atext[i]);
	}
	dinheiro[1].setString(to_string(money));
	for(int j=0; j < 2; j++){
		window.draw(dinheiro[j]);
	}
	meta[1].setString(to_string(valorMeta));
	for(int k=0; k < 2; k++){
		window.draw(meta[k]);
	}
}


int Plantas::PositionPlants(int posicaox, int posicaoy){

	planta = -1;


	if (posicaoy>=498 && posicaoy<=549){
		if (posicaox>= 4 && posicaox<=66){
			planta = 0;
		}
	}
	if (posicaoy>=498 && posicaoy<=551){
		if (posicaox>= 68 && posicaox<=125){
			planta = 1;	
		}
	}
	if (posicaoy>=498 && posicaoy<=555){
		if (posicaox>= 134 && posicaox<=189){
			planta = 2;
		}	
	}
	if (posicaoy>=485 && posicaoy<=562){
		if (posicaox>= 199 && posicaox<=245){
			planta = 3;
		}	
	}
	if (posicaoy>=498 && posicaoy<=560){
		if (posicaox>= 248 && posicaox<=307){
			planta = 4;
		}	
	}
	if (posicaoy>=484 && posicaoy<=564){
		if (posicaox>= 313 && posicaox<=342){
			planta = 5;
		}	
	}

	return planta;
}

int Plantas::RetirarLeite(int posicaox, int posicaoy){
	if (posicaoy>=289 && posicaoy<=475){
		if (posicaox>= 568 && posicaox<=733){
			leite = 1;
			return leite;
		}	
	}
}

void Plantas::addmoney(int qtd){
	this->money += qtd;
}

bool Plantas::FimJogo(){
	if(this->money >= this->valorMeta){

		return true;
	}
	else{
		return false;
	}
}
