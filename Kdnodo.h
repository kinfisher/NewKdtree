#pragma once
#include "Kdpunto.h"

using namespace std;

class Kdnodo
{
public:
	Kdnodo();
	int tamanio;
	Kdnodo(vector<Kdpunto>, int);// el vector de pountos y el tamaño maximo de puntos
	bool hoja;
	vector<Kdpunto> puntosNodos;
	Kdnodo *next[2];
	//creacion del opengl
	Kdpunto coordx;  
	Kdpunto coordy;
	Kdpunto coordz;

	~Kdnodo();
};

