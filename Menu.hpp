#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#define Max_Itens 4

using namespace std;

class Menu{
public:
	Menu (float width, float height);
	~Menu();

	void draw(sf::RenderWindow &window);
	void MoveUp();
	void MoveDown();
	//void Posicao();
	int GetPressedItem();

private:
	int SelectedItemIndex;
	int posicaoy, posicaox, posicao;
	sf::Font font;
	sf::Text menu[Max_Itens];
};

Menu::Menu(float width, float height){
	if (!font.loadFromFile("barn.otf")){
		//handle error
	}

	menu[0].setFont(font);
	menu[0].setColor(sf::Color::Black);
	menu[0].setString("LITTLE FARM");
	menu[0].setPosition(sf::Vector2f(175,60));	
	menu[0].setCharacterSize(100);	

	menu[1].setFont(font);
	menu[1].setColor(sf::Color::Black);
	menu[1].setString("PLAY");
	menu[1].setPosition(sf::Vector2f(350,280));	
	menu[1].setCharacterSize(60);	

	menu[2].setFont(font);
	menu[2].setColor(sf::Color::Black);
	menu[2].setString("HOW TO PLAY");
	menu[2].setPosition(sf::Vector2f(270, 350));	
	menu[2].setCharacterSize(60);	

	menu[3].setFont(font);
	menu[3].setColor(sf::Color::Black);
	menu[3].setString("EXIT");
	menu[3].setPosition(sf::Vector2f(350, 420));	
	menu[3].setCharacterSize(60);	

	SelectedItemIndex = 0;
}

Menu::~Menu(){

}

void Menu::draw(sf::RenderWindow &window){
	for(int i=0; i < Max_Itens; i++){
		window.draw(menu[i]);
	}
}

void Menu::MoveUp(){
	if(SelectedItemIndex - 1 >= 1){
		menu[SelectedItemIndex].setColor(sf::Color::Black);
		SelectedItemIndex--;
		cout << SelectedItemIndex << endl;
		menu[SelectedItemIndex].setColor(sf::Color::Red);
	}
}

void Menu::MoveDown(){
	if(SelectedItemIndex + 1 < Max_Itens){
		menu[SelectedItemIndex].setColor(sf::Color::Black);
		SelectedItemIndex++;
		cout << SelectedItemIndex << endl;
		menu[SelectedItemIndex].setColor(sf::Color::Red);
	}
}



/*void Menu::Posicao(){

	posicaoy = sf::Mouse::getPosition().y;
	posicaox = sf::Mouse::getPosition().x;

	if (posicaoy>=477 && posicaoy<=508){
		if (posicaox>= 415 && posicaox<=514){
			posicao = 1;
		}
	}
	else if (posicaoy>=547 && posicaoy<=579){
		if (posicaox>= 336 && posicaox<=602){
			posicao = 2;
		}
	}
	else if (posicaoy>=618 && posicaoy<=649){
		if (posicaox>= 415 && posicaox<=621){
			posicao = 3;
		}	
	}

	menu[1].setColor(sf::Color::Black);
	menu[2].setColor(sf::Color::Black);
	menu[3].setColor(sf::Color::Black);


	if (posicao == 1){
		menu[1].setColor(sf::Color::Red);
	}
	else if(posicao == 2){
		menu[2].setColor(sf::Color::Red);
	}
	else if(posicao == 3){
		menu[3].setColor(sf::Color::Red);
	}
}*/


int Menu::GetPressedItem(){


	/*posicaoy = sf::Mouse::getPosition().y;
	posicaox = sf::Mouse::getPosition().x;
	std::cout << posicaox << " , "<< posicaoy << std::endl;

	if (posicaoy>=477 && posicaoy<=508){
		if (posicaox>= 415 && posicaox<=514){
			posicao = 1;
			SelectedItemIndex = 1;

		}
	}
	else if (posicaoy>=547 && posicaoy<=579){
		if (posicaox>= 336 && posicaox<=602){
			posicao = 2;
			SelectedItemIndex = 2;

		}
	}
	else if (posicaoy>=618 && posicaoy<=649){
		if (posicaox>= 415 && posicaox<=621){
			posicao = 3;
			SelectedItemIndex = 3;

		}	
	}*/

	cout << SelectedItemIndex << endl;
	return SelectedItemIndex;
}