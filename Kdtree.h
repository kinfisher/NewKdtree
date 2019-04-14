#pragma once
#include <GL/glut.h>
#include "Kdnodo.h"

class Kdtree
{
public:
	Kdtree(vector<Kdpunto>);
	void creacion(Kdnodo* &, vector<Kdpunto>, int,int); //head, puntos , dimension,limite
	Kdnodo *head;
	~Kdtree();
};

