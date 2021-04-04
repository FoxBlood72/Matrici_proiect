#include "Matrice_patratica.hpp"
#include "Complex.hpp"

Matrice_patratica::Matrice_patratica()
{
	this->dim = 0;
	totalMatrix++;
}

Matrice_patratica::Matrice_patratica(int dim) 
{
	this->dim = dim;
	this->resize();
	totalMatrix++;
}

Matrice_patratica::Matrice_patratica(int dim, Complex **v) : Matrice(v)
{
	this->dim = dim;
	totalMatrix++;
}

Matrice_patratica::Matrice_patratica(Matrice_patratica &m)
{
	this->dim = m.getDim();
	this->resize();
	Complex **rightElem = m.getComplexElements();
	for(int i = 0; i < this->dim; i++)
		for(int j = 0; j < this->dim; j++)
			this->cElements[i][j] = rightElem[i][j];
	
	totalMatrix++;
}

void Matrice_patratica::setComplexElements(Complex **v)
{
	for(int i = 0; i < this->dim; i++)
		for(int j = 0; j < this->dim; j++)
			this->cElements[i][j] = v[i][j];
}

int Matrice_patratica::getDim()
{
	return this->dim;
}


Matrice_patratica Matrice_patratica::operator=(Matrice_patratica &m)
{
	this->dim = m.getDim();
	this->resize();
	Complex **elem = m.getComplexElements();
	for(int i = 0; i < this->dim; i++)
		for(int j = 0; j < this->dim; j++)
			this->cElements[i][j] = elem[i][j];
	
	
	return *this;
}


std::ostream &Matrice_patratica::afisare(std::ostream &os)
{
	for(int i = 0; i < this->dim; i++)
	{
		for(int j = 0; j < this->dim; j++)
			os<<this->cElements[i][j]<<" ";
		
		os<<std::endl;
	}
	return os;
}


//std::ostream &Matrice_patratica::operator<<(std::ostream &os)
//{
//	for(int i = 0; i < this->dim; i++)
//	{
//		for(int j = 0; j < this->dim; j++)
//			std::cout<<this->cElements[i][j]<<" ";
//		
//		std::cout<<std::endl;
//	}
//	return os;
//}

std::istream &operator>>(std::istream &is, Matrice_patratica &m)
{
	m.destruct();
	std::cout<<"Dimensiunea matricei: "<<std::endl;
	std::cin>>m.dim;
	
	m.resize();
	for(int i = 0; i < m.dim; i++)
		for(int j = 0; j < m.dim; j++)
		{
			std::cout<<"Se citeste urmatoarea pozitie: ["<<i<<"]["<<j<<"]"<<std::endl;
			std::cin>>m.cElements[i][j];
		}
	
	
	return is;
}

std::istream &operator>>(std::istream &is, Matrice_patratica *m)
{
	m->destruct();
	std::cout<<"Dimensiunea matricei: "<<std::endl;
	std::cin>>m->dim;
	
	m->resize();
	for(int i = 0; i < m->dim; i++)
		for(int j = 0; j < m->dim; j++)
		{
			std::cout<<"Se citeste urmatoarea pozitie: ["<<i+1<<"]["<<j+1<<"]"<<std::endl;
			std::cin>>m->cElements[i][j];
		}
	
	
	return is;
}

Complex *Matrice_patratica::getComplexAtPosition(int l, int c)
{
	Complex *comp = new Complex;
	if(l > this->dim || c > this->dim)
		return comp;
		
	return Matrice::getComplexAtPosition(l, c);
}

bool Matrice_patratica::setComplexAtPosition(int l, int c, Complex comp)
{
	if(l > this->dim || c > this->dim)
		return false;
		
	return Matrice::setComplexAtPosition(l, c, comp);
}


unsigned int Matrice_patratica::totalMatrix = 0;


void Matrice_patratica::resize()
{
	this->cElements = new Complex*[this->dim];
	for(int i = 0; i < this->dim; i++)
		this->cElements[i] = new Complex[this->dim];
}

void Matrice_patratica::destruct()
{
	for(int i = 0; i < this->dim; i++)
		delete []this->cElements[i];
		
	delete []this->cElements;
}

Matrice_patratica::~Matrice_patratica()
{
	this->destruct();
	totalMatrix--;
}

