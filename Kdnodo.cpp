#include "Kdnodo.h"



Kdnodo::Kdnodo()
{
}

Kdnodo::Kdnodo(vector<Kdpunto> vec, int limite)
{
	puntosNodos = vec;
	tamanio = limite;
	next[0] = next[1] = NULL;
	hoja = true;
}



Kdnodo::~Kdnodo()
{
}
