#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Kdpunto
{
public:
	Kdpunto();
	double coords[3];
	Kdpunto(double, double, double);
	Kdpunto(double, double); //creacion de puntos graficos
	~Kdpunto();
};

