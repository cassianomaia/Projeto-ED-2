#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>

using namespace std;

class Plantas{
	
public:
	Plantas ();
	~Plantas();

	int PositionPlantas(int posicaox, int posicaoy);

private:
	int posicaox, posicaoy, posicao;
	int planta;
};

Plantas::Plantas(){

}

Plantas::~Plantas(){

}


int Plantas::PositionPlantas(int posicaox, int posicaoy){

	if (posicaoy>=310 && posicaoy<=341){
		if (posicaox>= 351 && posicaox<=450){
			planta = 0;
			cout << "Cereja" << endl;

		}
	}
	else if (posicaoy>=380 && posicaoy<=412){
		if (posicaox>= 271 && posicaox<=538){
			planta = 1;
			cout << "Melancia" << endl;


		}
	}
	else if (posicaoy>=451 && posicaoy<=480){
		if (posicaox>= 351 && posicaox<=450){
			planta = 2;
			cout << "Tomate" << endl;

		}	
	}
	else if (posicaoy>=451 && posicaoy<=480){
		if (posicaox>= 351 && posicaox<=450){
			planta = 3;
			cout << "Cenoura" << endl;

		}	
	}
	else if (posicaoy>=451 && posicaoy<=480){
		if (posicaox>= 351 && posicaox<=450){
			planta = 4;
			cout << "Brócolis" << endl;

		}	
	}
	else if (posicaoy>=451 && posicaoy<=480){
		if (posicaox>= 351 && posicaox<=450){
			planta = 5;
			cout << "Beterraba" << endl;

		}	
	}

	//cout << SelectedItemIndex << endl;
	return planta;
}

