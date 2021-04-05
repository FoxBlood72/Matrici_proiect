#include <math.h>
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
	std::cout<<this->getDeterminant()<<std::endl;
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


Complex Matrice_patratica::calculateDeterminant(Complex **matrix, int n)
{
	Complex **submatrix = new Complex*[n];
	for(int i = 0; i < n; i++)
		submatrix[i] = new Complex[n];
		
	Complex nComp;
	nComp = (matrix[0][0] * matrix[1][1]);
	Complex det;
	if (n == 2)
		return ((matrix[0][0] * matrix[1][1]) - (matrix[1][0] * matrix[0][1]));
	else 
	{
		for (int x = 0; x < n; x++) {
			int subi = 0;
			for (int i = 1; i < n; i++) {
				int subj = 0;
				for (int j = 0; j < n; j++) {
					if (j == x)
						continue;
				submatrix[subi][subj] = matrix[i][j];
				subj++;
			}
			subi++;
		 }
		det = det + (pow(-1, x) * matrix[0][x] * (Matrice_patratica::calculateDeterminant ( submatrix, n - 1 )));
	  }
	}
	return det;
}

bool Matrice_patratica::is_diagonal()
{
	Complex **elem = this->getComplexElements();
	for(int i = 0; i < this->dim; i++)
		for(int j = 0; j < this->dim; j++)
			if((elem[i][j].getReal() != 0 || elem[i][j].getImag() != 0) && i != j)
				return false;
				
	return true;
}


Complex Matrice_patratica::getDeterminant()
{
	int n = this->getDim();
	Complex **matrix = this->getComplexElements();
	return this->calculateDeterminant(matrix, n);
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

