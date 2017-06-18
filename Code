#include <iostream>
#include <cstdlib>
using namespace std;


//classes

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
	
	struct node *esq;
	struct node *dir;
};




class Lista {
	public:
			bool Vazia();
			void Insere(Planta&);
			Planta Retira();
			Lista();
			int Contador();
			
	private:
			node *topo;
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


//métodos

Planta::Planta(){
	
}

Lista::Lista(){
	topo = NULL;
}


Melancia::Melancia() : Planta(){
	tempoCresc = 15;
	valor = 2000;
}

Tomate::Tomate() : Planta(){
	tempoCresc = 9;
	valor = 900;
}

Cenoura::Cenoura() : Planta(){
	tempoCresc = 6;
	valor = 400;
}

Beterraba::Beterraba() : Planta(){
	tempoCresc = 4;
	valor = 250;
}

Brocolis::Brocolis(): Planta(){
	tempoCresc = 2;
	valor = 100;
}

Cereja::Cereja(): Planta(){
	tempoCresc = 12;
	valor = 1250;
}

int Planta::getValor(){
	return valor;
}

void Lista::Insere(Planta& p1){
	
	node *temp = new node;
	
	if (Lista::Vazia() == 1){
		temp->info = p1;
		temp->esq = temp;
		temp->dir = temp;
		topo = temp;
		temp = NULL;
		
		delete temp;
	} else if ((Lista::Vazia() != 1) && (topo->esq == topo->dir)){
				
				temp->info = p1;
				topo->dir = temp;
				topo->esq = temp;
				temp->dir = topo;
				temp->esq = topo;
				topo = temp;
				temp = NULL;
				
				delete temp;
				
		} else {
				topo->dir = temp;
				temp->dir = topo->esq;
				topo->esq->esq = temp;
				temp->esq = topo;
				topo = temp;
				temp = NULL;
				
				delete temp;
				
			}
}

bool Lista::Vazia(){
	if (topo == NULL){
		return 1;
	} else
		return 0;
}

Planta Lista::Retira(){
	node *temp = new node;
	Planta x;
	
	if (Lista::Vazia() != 1){
		if (topo->esq == topo->dir){
			x = topo->info;
			
			delete topo;
		}else if ((topo->esq->esq == topo) && (topo->dir->dir == topo)){
				temp = topo;
				x = temp->info; 
				topo = topo->esq;
				topo->esq = topo;
				topo->dir = topo;
				
				delete temp;
			}else {
					x = topo->info;
					temp = topo;
					topo = temp->esq;
					topo->dir = temp->dir;
					temp->dir->dir = topo;
					
					delete temp;
				}
		
		return x;
	}
	
}

int Lista::Contador(){
	
	Lista fAux;
	int cont = 0;
	Planta aux;
	
	while (this->Vazia() != 1){
		aux = this->Retira();
		cont++;
		fAux.Insere(aux);
	}
	
	while (fAux.Vazia() != 1){
		aux = fAux.Retira();
		this->Insere(aux);
	}
	
	return cont;
}






//int main

int main () {
	
	Melancia m1;
	Cereja c1;
	Cenoura ce1;
	Lista l1;
	
	l1.Insere(m1);
	l1.Insere(c1);
	l1.Insere(ce1);
	
	
	
	
	return 0;
	
	
}


