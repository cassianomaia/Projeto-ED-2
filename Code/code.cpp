#include <iostream>
#include <cstdlib>
using namespace std;
#define tam 4
#define tamLista 6




//CLASSES

class Planta{
	public: 
			int getValor();
			int getTempo();
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

int Planta::getValor(){
	return this->valor;
}

int Planta::getTempo(){
	return this->tempoCresc;
}



class SpotPlantar {
	public:
			SpotPlantar();
			bool Vazia();
			bool Cheia();
			bool Insere(Planta&, int);
			Planta Retira(int indiceRetira, bool& deuCerto);
			int getNroElementos();
			
	protected:
			node *field[tam];
};

//METODOS DA SPOTPLANTAR
	
SpotPlantar::SpotPlantar(){
	int i;
	
	for (i=0; i<tam; i++){
		field[i] = new node;
		field[i]->checagem = 0;
	}
}

int SpotPlantar::getNroElementos(){
	int i, cont;
	cont = 0;
	for (i=0; i<tam; i++){
		if (field[i]->checagem != 0){
			cont++;
		}
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


bool SpotPlantar::Insere(Planta& p1, int i){
	if (SpotPlantar::Cheia() != true){
		if (field[i]->checagem == 0){
			field[i]->info = p1;
			field[i]->checagem = 1;
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
			field[i]->checagem = 0;
			return field[i]->info;
		} else
			deuCerto = false;
	}
}


//CLASSE LISTA DE ESCOLHA ONDE AS PLANTAS VEM RANDOM

class Lista {
		public:
				Lista();
				~Lista();
				bool Vazia();
				bool Cheia();
				void Insere(Planta&);
				Planta Retira(int indiceRetiraLista);
				int getNroElementos();
			
		protected:
				node *field[tamLista];
			
};

//METODOS LISTA

//AQUI É NECESSÁRIO QUE A LISTA SEJAM INICIADAS COM PLANTINHAS RANDOM MAS AINDA NÃO SEI COMO IMPLEMENTAR ISSO
//COLOCAR NO LUGAR DE "NULL" QUANDO CONSEGUIR
Lista::Lista(){
	int i;
	
	for (i=0; i<0; i++){
		field[i] = new node;
		field[i]->checagem = 0;
	}
	
}

Lista::~Lista(){
	delete [] field;
}

int Lista::getNroElementos(){
	int i, cont;
	
	for (i=0; i<tamLista; i++){
		if (field[0]->checagem != 0)
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
		if (field[i]->checagem == 0){
			field[i]->info = p1;
			field[i]->checagem = 1;
			if (i!= tam){
				field[i]->next = field[i+1];
				field[i-1]->next = field[i];
				}
			else {
				field[i]->next = field[0];
				field[i-1]->next = field[i];
			}
		}
	}
}

Planta Lista::Retira(int indiceRetiraLista){
	int i;
	for (i=0; i<0; i++){
		if (indiceRetiraLista == i){
			if(i!=tamLista || i!=0){
				field[i-1]->next = field[i+1];
			} else if (i==0){
					field[tamLista]->next = field[i+1];
				} else
					field[i-1]->next = field[0];
		}
	}
}





int main() {
	
	bool teste;
	int tm1, tc1, tb1;

	cout << "Bool e ints criados" <<endl;
	
	Melancia m1;
	Cereja c1;
	Brocolis b1;
	
	cout << "Plantas alocadas" << endl;
	
	tm1 = m1.getValor();
	tc1 = c1.getValor();
	tb1 = b1.getValor();

	cout << "Valores:" << tm1 << " - " << tc1 << " - " << tb1 << endl;

	tm1 = m1.getTempo();
	tc1 = c1.getTempo();
	tb1 = b1.getTempo();	

	cout << "Tempo:" << tm1 << " - " << tc1 << " - " << tb1 << endl;

	SpotPlantar spot;
	
	cout << "Spot criado" << endl;
	cout << "Spot vazio:" << spot.Vazia() << endl;

	teste = spot.Insere(m1, 1);

	cout << "Inseriu m1" << endl;
	
	cout<< spot.getNroElementos() << endl;
	
	return 0;
}
