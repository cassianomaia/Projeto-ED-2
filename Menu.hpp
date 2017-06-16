#pragma once
#include "SFML/Graphics.hpp"
#define Max_Itens 4

class Menu{
public:
	Menu (float width, float height);
	~Menu();

	void draw(sf::RenderWindow &window){
		for(int i=0; i < Max_Itens; i++){
		window.draw(menu[i]);
		}
	}
	
	void MoveUp(){
		if(SelectecItemIndex - 1 >= 1){
		menu[SelectecItemIndex].setColor(sf::Color::Black);
		SelectecItemIndex--;
		menu[SelectecItemIndex].setColor(sf::Color::Red);
		}
	}
	void MoveDown(){
		if(SelectecItemIndex + 1 < Max_Itens){
		menu[SelectecItemIndex].setColor(sf::Color::Black);
		SelectecItemIndex++;
		menu[SelectecItemIndex].setColor(sf::Color::Red);
		}
	}

	int GetPressedItem(){
		return SelectecItemIndex;
	}

private:
	int SelectecItemIndex;
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
	menu[0].setPosition(sf::Vector2f(140,60));	
	menu[0].setCharacterSize(60);	

	menu[1].setFont(font);
	menu[1].setColor(sf::Color::Black);
	menu[1].setString("PLAY");
	menu[1].setPosition(sf::Vector2f(240,200));	
	menu[1].setCharacterSize(40);	

	menu[2].setFont(font);
	menu[2].setColor(sf::Color::Black);
	menu[2].setString("HOW TO PLAY");
	menu[2].setPosition(sf::Vector2f(190, 250));	
	menu[2].setCharacterSize(40);	

	menu[3].setFont(font);
	menu[3].setColor(sf::Color::Black);
	menu[3].setString("EXIT");
	menu[3].setPosition(sf::Vector2f(240, 300));	
	menu[3].setCharacterSize(40);	

	SelectecItemIndex = 0;
}

Menu::~Menu(){

}

