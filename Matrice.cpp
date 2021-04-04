#include "Matrice.hpp"


Matrice::Matrice()
{
	this->cElements = NULL;
	totalMatrix++;
}

Matrice::Matrice(Complex **cElements)
{
	this->cElements = cElements;
	totalMatrix++;
}

Matrice::Matrice(Matrice &m)
{
	this->cElements = m.getComplexElements();
	totalMatrix++;
}

Complex **Matrice::getComplexElements()
{
	return this->cElements;
}

Complex *Matrice::getComplexAtPosition(int l, int c)
{
	return &(this->cElements[l][c]);
}

std::ostream &operator<<(std::ostream &os, Matrice &m)
{
	return m.afisare(os);
}

std::ostream &operator<<(std::ostream &os, Matrice *m)
{
	return m->afisare(os);
}

bool Matrice::setComplexAtPosition(int l, int c, Complex comp)
{
	this->cElements[l][c] = comp;
	return true;
}

unsigned int Matrice::totalMatrix = 0;

Matrice::~Matrice()
{
//	if(cElements != NULL)
//	{
//		delete []cElements;
//		*(this->cElements) = NULL;
//	}
	totalMatrix--;
}

