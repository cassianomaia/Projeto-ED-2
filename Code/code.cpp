#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
#define tam 4
#define tamLista 6



//CLASSES

class Planta{
	public: 
			int getValor();
			int getTempo();
			int getTipo();
			Planta();
	
	protected:
		int tipoplanta;
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
	tipoplanta = 2;
	tempoCresc = 15;
	valor = 200;
};

Tomate::Tomate() : Planta(){
	tipoplanta = 3;
	tempoCresc = 9;
	valor = 90;
};

Cenoura::Cenoura() : Planta(){
	tipoplanta = 4;
	tempoCresc = 6;
	valor = 40;
};

Beterraba::Beterraba() : Planta(){
	tipoplanta = 6;
	tempoCresc = 4;
	valor = 25;
};

Brocolis::Brocolis(): Planta(){
	tipoplanta = 5;
	tempoCresc = 2;
	valor = 10;
};

Cereja::Cereja(): Planta(){
	tipoplanta = 1;
	tempoCresc = 12;
	valor = 125;
};


Planta::Planta(){
	
}

int Planta::getValor(){
	return this->valor;
}

int Planta::getTempo(){
	return this->tempoCresc;
}

int Planta::getTipo(){
	return this->tipoplanta;
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


//funciona	
SpotPlantar::SpotPlantar(){
	int i;
	
	for (i=0; i<tam; i++){
		field[i] = new node;
		field[i]->checagem = 0;
	}
}


//funciona
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


//funciona
bool SpotPlantar::Vazia(){
	if (SpotPlantar::getNroElementos() == 0)
		return true;
	else
		return false;
}


//funciona
bool SpotPlantar::Cheia(){
	if (SpotPlantar::getNroElementos() == tam)
		return true;
	else
		return false;
}

//funciona
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
				bool Vazia();
				bool Cheia();
				void Insere();
				Planta Retira(int indiceRetiraLista);
				int getNroElementos();
				int Exibe(int index);
			
		protected:
				node *field[tamLista];
			
};

//METODOS LISTA

//AQUI É NECESSÁRIO QUE A LISTA SEJAM INICIADAS COM PLANTINHAS RANDOM MAS AINDA NÃO SEI COMO IMPLEMENTAR ISSO
//COLOCAR NO LUGAR DE "NULL" QUANDO CONSEGUIR
Lista::Lista(){
	int i;
	
	for (i=0; i<tamLista; i++){
		field[i] = new node;
		field[i]->checagem = 0;
	}
}

int Lista::Exibe(int index){
	return field[index]->info.getTipo();
}

int Lista::getNroElementos(){
	int i, cont;
	cont = 0;
	for (i=0; i<tamLista; i++){
		if (field[i]->checagem != 0)
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

void Lista::Insere(){		//esse metodo nao vai receber nada
	int i;
	for (i=0; i<tamLista; i++){
		int x = rand() % 5;
		Melancia m;
		Tomate t;
		Cenoura c;
		Beterraba b;
		Brocolis br;
		Cereja ce;
		if (field[i]->checagem == 0){
			switch(x){
				case 0:
					field[i]->info = m;
					break;
				case 1:
					field[i]->info = t;
					break;
				case 2:
					field[i]->info = c;
					break;
				case 3:
					field[i]->info = b;
					break;
				case 4:
					field[i]->info = br;
					break;
				case 5:
					field[i]->info = ce;
					break;
			}
			field[i]->checagem = 1;
			if (i < tamLista){
				if (i == 0){
					field[i]->next = field[i+1];
				}else if(i < tamLista-1){
					field[i]->next = field[i+1];
				}else{
					field[i]->next = field[0];
				}
			}
		}
	}
}

Planta Lista::Retira(int indiceRetiraLista){
	int i;
	Planta aux;
	for (i=0; i<tamLista; i++){
		if (indiceRetiraLista == i){
			aux = field[i]->info; 
			field[i]->checagem = 0;
			/*if(i!=tamLista || i!=0){
				field[i-1]->next = field[i+1];
			} else if (i==0){
					field[tamLista]->next = field[i+1];
				} else{
					field[i-1]->next = field[0];
				} reescrever esse if */
		}
	}
	return aux;
}



int main() {
	srand(time(NULL));
	bool teste;
	int tm1, tc1, tb1;

	cout << "Bool e ints criados" <<endl;
	
	Melancia m1;
	Cereja c1;
	Brocolis b1;
	Planta testep;
	
	cout << "Plantas alocadas" << endl;
	
	tm1 = m1.getValor();
	tc1 = c1.getValor();
	tb1 = b1.getValor();

	cout << "Valores:" << tm1 << " - " << tc1 << " - " << tb1 << endl;

	tm1 = m1.getTempo();
	tc1 = c1.getTempo();
	tb1 = b1.getTempo();	

	cout << "Tempo:" << tm1 << " - " << tc1 << " - " << tb1 << endl;

	tm1 = m1.getTipo();
	tc1 = c1.getTipo();
	tb1 = b1.getTipo();

	cout << "Tipo:" << tm1 << " - " << tc1 << " - " << tb1 << endl;
	
	SpotPlantar spot;
	
	cout << "Spot criado" << endl;
	cout << "Spot vazio:" << spot.Vazia() << endl;

	teste = spot.Insere(m1, 1);
	teste = spot.Insere(c1, 2);
	teste = spot.Insere(b1, 3);
	cout << "Inseriu as frutas." << endl;
	
	cout<< spot.getNroElementos() << endl;

	testep = spot.Retira(3, teste);

	cout << "Removeu" << testep.getValor() << endl;

	// remover elementos e testar
	
	Lista lista;
	cout << "Criou lista" << endl;
	cout << lista.Vazia() << endl;
	cout << lista.Cheia() << endl;
	cout << lista.getNroElementos() << endl;
	lista.Insere();
	cout << "Após insere:" << lista.getNroElementos() << endl;

	testep = lista.Retira(1);
	cout << "Retirou elemento." << endl;
	cout << "Removeu" << testep.getValor() << endl;
	cout << "Após remove:" << lista.getNroElementos() << endl;

	cout << lista.Exibe(0) << " " << lista.Exibe(1) << " " << lista.Exibe(2) << " " << lista.Exibe(3) << " " << lista.Exibe(4) << " " << lista.Exibe(5) << endl;
 
	return 0;
}
