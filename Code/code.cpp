#include <iostream>
#include <cstdlib>
using namespace std;
#define tam 3
#define tamLista 6




//CLASSES

class Planta{
	public: 
			int getValor();
			Planta();
	
	protected:
			int tempoCresc;
			int valor;
	
};

struct node{
	
	Planta info;
	int checagem;
	
	struct node *next;
};

class SpotPlantar {
	public:
			SpotPlantar();
			bool Vazia();
			bool Cheia();
			bool Insere(Planta&);
			Planta Retira(int indiceRetira, bool& deuCerto);
			int getNroElementos();
			
	protected:
			node *field[tam];
};


//CLASSE LISTA DE ESCOLHA ONDE AS PLANTAS VEM RANDOM

class Lista {
		public:
				Lista();
				bool Vazia();
				bool Cheia();
				void Insere(Planta&);
				Planta Retira(int indiceRetiraLista);
				int getNroElementos();
			
		protected:
				node *field[tamLista];
			
};

class Melancia : public Planta {
	
	public: 
		Melancia();
};


class Tomate : public Planta {
	
	public:
		Tomate();
};

class Cenoura : public Planta {
	
	public:
		Cenoura();
};

class Beterraba : public Planta {
	
	public:
		Beterraba();
};

class Brocolis : public Planta {
	
	public:
		Brocolis();
};

class Cereja : public Planta {
	
	public:
		Cereja();
};

Melancia::Melancia() : Planta(){
	tempoCresc = 15;
	valor = 2000;
};

Tomate::Tomate() : Planta(){
	tempoCresc = 9;
	valor = 900;
};

Cenoura::Cenoura() : Planta(){
	tempoCresc = 6;
	valor = 400;
};

Beterraba::Beterraba() : Planta(){
	tempoCresc = 4;
	valor = 250;
};

Brocolis::Brocolis(): Planta(){
	tempoCresc = 2;
	valor = 100;
};

Cereja::Cereja(): Planta(){
	tempoCresc = 12;
	valor = 1250;
};

Planta::Planta(){
	
}




//METODOS DA SPOTPLANTAR

bool deuCerto = true;

SpotPlantar::SpotPlantar(){
	int i;
	
	for (i=0; i<tam; i++)
		this->field[i]->checagem = 0;
	
}

int SpotPlantar::getNroElementos(){
	int i, cont;
	
	for (i=0; i<tam; i++){
		if (this->field[i]->checagem != 0)
			cont++;
	}
	
	return cont;
}

bool SpotPlantar::Vazia(){
	if (SpotPlantar::getNroElementos() == 0)
		return true;
	else
		return false;
}

bool SpotPlantar::Cheia(){
	if (SpotPlantar::getNroElementos() == tam)
		return true;
	else
		return false;
}


bool SpotPlantar::Insere(Planta& p1){
	int i = 0;
	
	if (SpotPlantar::Cheia() != 1){
		for (i=0; i<tam; i++){
			if (this->field[i]->checagem == 0)
				this->field[i]->info = p1;
				this->field[i]->checagem = 1;
		}
		
		return true;
	} else
		return false;
}

//ESSE INDICE RETIRA É O QUE O MÉTODO RECEBE DO MOUSE PARA RETIRAR O ELEMENTO CLICADO

Planta SpotPlantar::Retira(int indiceRetira, bool& deuCerto){
	int i;
	
	for (i=0; i< tam;i++){
		if (indiceRetira == i){
			deuCerto = true;
			this->field[i]->checagem = 0;
			return this->field[i]->info;
		} else
			deuCerto = false;
	}
}



//METODOS LISTA

//AQUI É NECESSÁRIO QUE A LISTA SEJAM INICIADAS COM PLANTINHAS RANDOM MAS AINDA NÃO SEI COMO IMPLEMENTAR ISSO
//COLOCAR NO LUGAR DE "NULL" QUANDO CONSEGUIR
Lista::Lista(){
	int i;
	
	for (i=0; i<0; i++){
		this->field[i]->checagem = 0;
	}
	
}

int Lista::getNroElementos(){
	int i, cont;
	
	for (i=0; i<tamLista; i++){
		if (this->field[0]->checagem != 0)
			cont++;
	}
	
	return cont;
}

bool Lista::Vazia(){
	if (Lista::getNroElementos() == 0)
		return true;
	else
		return false;
}

bool Lista::Cheia(){
	if (Lista::getNroElementos() == tamLista)
		return true;
	else
		return false;
}

//TODA A VEZ QUE ALGUM ELEMENTO FOR RETIRADO, É CHAMADA AUTOMATICAMENTE ESSA FUNÇÃO TAMBÉM PARA QUE OUTRO SEJA COLOCADO NO LUGAR

void Lista::Insere(Planta& p1){
	int i;
	
	for (i=0; i<0; i++){
		if (this->field[i]->checagem == 0){
			this->field[i]->info = p1;
			this->field[i]->checagem = 1;
			if (i!= tam){
				this->field[i]->next = this->field[i+1];
				this->field[i-1]->next = this->field[i];
				}
			else {
				this->field[i]->next = this->field[0];
				this->field[i-1]->next = this->field[i];
			}
		}
	}
}

Planta Lista::Retira(int indiceRetiraLista){
	int i;
	for (i=0; i<0; i++){
		if (indiceRetiraLista == i){
			if(i!=tamLista || i!=0){
				this->field[i-1]->next = this->field[i+1];
			} else if (i==0){
					this->field[tamLista]->next = this->field[i+1];
				} else
						this->field[i-1]->next = this->field[0];
		}
	}
}





int main() {
	
	bool teste;
	
	Melancia m1;
	Cereja c1;
	Brocolis b1;
	
	SpotPlantar spot;
	
	teste = spot.Insere(m1);
	cout<< spot.getNroElementos() << endl;
	
	return 0;
}
