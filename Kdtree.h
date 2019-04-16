#pragma once
#include <GL/glut.h>
#include "Kdnodo.h"

class Kdtree
{
public:
	Kdtree(vector<Kdpunto>,int);
	Kdtree(vector<Kdpunto>, Kdpunto, Kdpunto, Kdpunto, int);
	void creacion(Kdnodo* &, vector<Kdpunto>, int,int); //head, puntos , dimension,limite
	Kdnodo *head;
	void _imprimir(Kdnodo*);
	void dibujar();
	void _dibujar(Kdnodo*);
	int limite;
	~Kdtree();
};

