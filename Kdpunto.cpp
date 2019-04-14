#include "Kdpunto.h"



Kdpunto::Kdpunto()
{
	coords[0] = coords[1] = coords[2] = 0;
}

Kdpunto::Kdpunto(double _x ,double _y, double _z)
{
	coords[0] = _x;
	coords[1] = _y;
	coords[2] = _z;
}

Kdpunto::Kdpunto(double max, double min)
{
	coords[0] = max;
	coords[1] = min;
	coords[2] = 0;
}



Kdpunto::~Kdpunto()
{
}
