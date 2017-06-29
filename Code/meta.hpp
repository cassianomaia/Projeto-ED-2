#include <iostream>

class meta{
public:
	meta();
	int getmeta();	
	void setmeta();
private:
	int valor = 0;
};

meta::meta(){
	valor = 400;
}

int meta::getmeta(){
	return this->valor;
}

void meta::setmeta(){
	this->valor += 400;
}