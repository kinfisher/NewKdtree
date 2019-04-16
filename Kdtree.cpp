#include "Kdtree.h"



Kdtree::Kdtree(vector<Kdpunto> vec,int lim)
{
	creacion(head, vec, 0, lim);
}

Kdtree::Kdtree(vector<Kdpunto> vec, Kdpunto X, Kdpunto Y, Kdpunto Z, int lim)
{
	head = new Kdnodo(X, Y, Z);
	limite = lim;
	creacion(head, vec, 0, lim);
}


void Kdtree::creacion(Kdnodo* &P, vector<Kdpunto> vec, int dimension,int lim)
{
	P = new Kdnodo();
	//cout << "ite" << endl;
	limite = lim;
	if (vec.size() <= limite)
	{
		P->puntosNodos = vec;
		return;
	}
	
	P->hoja = false;
	sort(vec.begin(), vec.end(), [dimension](Kdpunto p1, Kdpunto p2)
	{
		return p1.coords[dimension] < p2.coords[dimension];
	});

	int medio = vec.size() / 2;
	if (dimension == 3)
	{
		dimension = 0;
	}
	else
	{
		dimension++;
	}
	creacion(P->next[0], vector<Kdpunto>(vec.begin(), vec.begin() + medio), dimension, limite);
	creacion(P->next[1], vector<Kdpunto>(vec.begin()+medio+1, vec.end()), dimension, limite);



}

void Kdtree::_imprimir(Kdnodo *P)
{
	for (int i = 0; i < P->puntosNodos.size(); i++)
	{
		P->puntosNodos[i].imprimir();
		cout << endl;
	}

	_imprimir(P->next[0]);
	_imprimir(P->next[1]);

}



void Kdtree::dibujar()
{
	Kdnodo *P = head;
	if (P->hoja)
	{
		for (int i = 0; i < P->puntosNodos.size(); i++)
		{
			glPointSize(5.0);
			glBegin(GL_POINTS);
			glColor3f(0, 0, 255);
			glVertex3d(P->puntosNodos[i].coords[0], P->puntosNodos[i].coords[1], P->puntosNodos[i].coords[2]);
			glEnd();
		}
		return;
	}

	glBegin(GL_LINES);

	//lineas horizontales

	glColor3d(255, 0, 0);
	glVertex3d(P->coordx.coords[0], P->coordy.coords[1], P->coordz.coords[1]);  //x=negativo,y=positivo,z=positivo
	glVertex3d(P->coordx.coords[1], P->coordy.coords[1], P->coordz.coords[1]);

	glColor3d(255, 0, 0);
	glVertex3d(P->coordx.coords[0], P->coordy.coords[0], P->coordz.coords[1]);
	glVertex3d(P->coordx.coords[1], P->coordy.coords[0], P->coordz.coords[1]);

	glColor3d(255, 0, 0);
	glVertex3d(P->coordx.coords[0], P->coordy.coords[1], P->coordz.coords[0]);
	glVertex3d(P->coordx.coords[1], P->coordy.coords[1], P->coordz.coords[0]);


	glColor3d(255, 0, 0);
	glVertex3d(P->coordx.coords[0], P->coordy.coords[0], P->coordz.coords[0]);
	glVertex3d(P->coordx.coords[1], P->coordy.coords[0], P->coordz.coords[0]);

	//linesa verticales

	glColor3d(255, 0, 0);
	glVertex3d(P->coordx.coords[0], P->coordy.coords[0], P->coordz.coords[1]); 
	glVertex3d(P->coordx.coords[0], P->coordy.coords[1], P->coordz.coords[1]);

	glColor3d(255, 0, 0);
	glVertex3d(P->coordx.coords[1], P->coordy.coords[0], P->coordz.coords[1]);
	glVertex3d(P->coordx.coords[1], P->coordy.coords[1], P->coordz.coords[1]);

	glColor3d(255, 0, 0);
	glVertex3d(P->coordx.coords[0], P->coordy.coords[0], P->coordz.coords[0]);
	glVertex3d(P->coordx.coords[0], P->coordy.coords[1], P->coordz.coords[0]);

	glColor3d(255, 0, 0);
	glVertex3d(P->coordx.coords[1], P->coordy.coords[0], P->coordz.coords[0]);
	glVertex3d(P->coordx.coords[1], P->coordy.coords[1], P->coordz.coords[0]);

	//lineas diagonales

	glColor3d(255, 0, 0);
	glVertex3d(P->coordx.coords[0], P->coordy.coords[1], P->coordz.coords[1]);
	glVertex3d(P->coordx.coords[0], P->coordy.coords[1], P->coordz.coords[0]);

	glColor3d(255, 0, 0);
	glVertex3d(P->coordx.coords[1], P->coordy.coords[1], P->coordz.coords[1]);
	glVertex3d(P->coordx.coords[1], P->coordy.coords[1], P->coordz.coords[0]);

	glColor3d(255, 0, 0);
	glVertex3d(P->coordx.coords[0], P->coordy.coords[0], P->coordz.coords[1]);
	glVertex3d(P->coordx.coords[0], P->coordy.coords[0], P->coordz.coords[0]);

	glColor3d(255, 0, 0);
	glVertex3d(P->coordx.coords[1], P->coordy.coords[0], P->coordz.coords[1]);
	glVertex3d(P->coordx.coords[1], P->coordy.coords[0], P->coordz.coords[0]);

	glEnd();

}



Kdtree::~Kdtree()
{
}
