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
	int GetPressedItem();

private:
	int SelectedItemIndex;
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

int Menu::GetPressedItem(){
	cout << SelectedItemIndex << endl;
	return SelectedItemIndex;
}