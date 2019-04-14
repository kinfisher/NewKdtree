#include "Kdtree.h"



Kdtree::Kdtree(vector<Kdpunto> vec)
{
}

void Kdtree::creacion(Kdnodo* &P, vector<Kdpunto> vec, int dimension,int limite)
{
	if (P->hoja)
	{
		P->puntosNodos = vec;
	}
}


Kdtree::~Kdtree()
{
}
