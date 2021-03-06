#pragma once
#include <SFML/Graphics.hpp>
//#include <SFML/Audio.hpp>
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
	void Position(int posicaox, int posicaoy);
	int GetPressedItem(int posicaox, int posicaoy);

private:
	int SelectedItemIndex;
	int posicaox, posicaoy, posicao;
	sf::Font font;
	sf::Text menu[Max_Itens];
};

Menu::Menu(float width, float height){

	if (!font.loadFromFile("../Fonts/barn.otf")){
		std::cout << "Error" << std::endl;
	}

	menu[0].setFont(font);
	menu[0].setColor(sf::Color::Black);
	menu[0].setString("LITTLE FARM");
	menu[0].setPosition(sf::Vector2f(175,60));	
	menu[0].setCharacterSize(100);	

	menu[1].setFont(font);
	menu[1].setColor(sf::Color::Black);
	menu[1].setString("Jogar");
	menu[1].setPosition(sf::Vector2f(345,280));	
	menu[1].setCharacterSize(60);	

	menu[2].setFont(font);
	menu[2].setColor(sf::Color::Black);
	menu[2].setString("Como Jogar");
	menu[2].setPosition(sf::Vector2f(280, 350));	
	menu[2].setCharacterSize(60);	

	menu[3].setFont(font);
	menu[3].setColor(sf::Color::Black);
	menu[3].setString("Sair");
	menu[3].setPosition(sf::Vector2f(360, 420));	
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
		menu[SelectedItemIndex].setColor(sf::Color::Red);
	}
}

void Menu::MoveDown(){
	if(SelectedItemIndex + 1 < Max_Itens){
		menu[SelectedItemIndex].setColor(sf::Color::Black);
		SelectedItemIndex++;
		menu[SelectedItemIndex].setColor(sf::Color::Red);
	}
}



void Menu::Position(int posicaox, int posicaoy){

	if (posicaoy>=310 && posicaoy<=341){
		if (posicaox>= 351 && posicaox<=450){
			posicao = 1;

		}
	}
	else if (posicaoy>=380 && posicaoy<=412){
		if (posicaox>= 271 && posicaox<=538){
			posicao = 2;

		}
	}
	else if (posicaoy>=451 && posicaoy<=480){
		if (posicaox>= 351 && posicaox<=450){
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
}


int Menu::GetPressedItem(int posicaox, int posicaoy){


	if (posicaoy>=310 && posicaoy<=341){
		if (posicaox>= 351 && posicaox<=450){
			SelectedItemIndex = 1;

		}
	}
	else if (posicaoy>=380 && posicaoy<=412){
		if (posicaox>= 271 && posicaox<=538){
			SelectedItemIndex = 2;

		}
	}
	else if (posicaoy>=451 && posicaoy<=480){
		if (posicaox>= 351 && posicaox<=450){
			SelectedItemIndex = 5;

		}	
	}
	return SelectedItemIndex;
}