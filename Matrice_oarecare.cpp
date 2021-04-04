#include "Matrice_oarecare.hpp"
#include "Matrice.hpp"
#include "Complex.hpp"

Matrice_oarecare::Matrice_oarecare() 
{
	this->lines = 0;
	this->columns = 0;
	totalMatrix++;
}

Matrice_oarecare::Matrice_oarecare(int lines, int columns)
{
	this->lines = lines;
	this->columns = columns;
	
	this->resize();
	totalMatrix++;
}

Matrice_oarecare::Matrice_oarecare(int lines, int columns, Complex **v) : Matrice(v)
{
	this->lines = lines;
	this->columns = columns;
	totalMatrix++;
}

Matrice_oarecare::Matrice_oarecare(Matrice_oarecare &m)
{
	this->lines = m.getLines();
	this->columns = m.getColumns();
	this->resize();
	Complex **elem = m.getComplexElements();
	for(int i = 0; i < this->lines; i++)
		for(int j = 0; j < this->columns; j++)
			this->cElements[i][j] = elem[i][j];
	
	totalMatrix++;
}

int Matrice_oarecare::getLines()
{
	return this->lines;
}

int Matrice_oarecare::getColumns()
{
	return this->columns;
}




Matrice_oarecare Matrice_oarecare::operator=(Matrice_oarecare &rightMatrix)
{
	this->destruct();
	this->lines = rightMatrix.getLines();
	this->columns = rightMatrix.getColumns();
	
	rightMatrix.resize();
	
	Complex **elem = rightMatrix.getComplexElements();
	for(int i = 0; i < lines; i++)
		for(int j = 0; j < columns; j++)
			this->cElements[i][j] = elem[i][j];
	
	return *this;
}


std::ostream &Matrice_oarecare::afisare(std::ostream &os)
{
	Complex **elem = this->getComplexElements();
	for(int i = 0; i < this->lines; i++)
	{
		for(int j = 0; j < this->columns; j++)
			os<<elem[i][j]<<" ";
			
		os<<std::endl;
	}
	return os;
}

//std::ostream &operator<<(std::ostream &os, Matrice_oarecare &mat)
//{
//	mat.afisare(os);
//	return os;
//}

std::istream &operator>>(std::istream &is, Matrice_oarecare &m)
{
	m.destruct();
	int lines, columns;
	std::cout<<"Linii: ";
	std::cin>>lines;
	std::cout<<"Coloane: ";
	std::cin>>columns;
	
	m.lines = lines;
	m.columns = columns;
	
	
	
	m.resize();
	
	for(int i = 0; i < lines; i++)
		for(int j = 0; j < columns; j++)
		{
			std::cout<<"Valoare pentru ["<<i+1<<"]["<<j+1<<"]: "<<std::endl;
			std::cin>>m.cElements[i][j];
		}
	
	
	
	return is;
}

std::istream &operator>>(std::istream &is, Matrice_oarecare *m)
{
	m->destruct();
	int lines, columns;
	std::cout<<"Linii: ";
	std::cin>>lines;
	std::cout<<"Coloane: ";
	std::cin>>columns;
	
	m->lines = lines;
	m->columns = columns;
	
	
	
	m->resize();
	
	for(int i = 0; i < lines; i++)
		for(int j = 0; j < columns; j++)
		{
			std::cout<<"Valoare pentru ["<<i+1<<"]["<<j+1<<"]: "<<std::endl;
			std::cin>>m->cElements[i][j];
		}
	
	
	
	return is;
}


void Matrice_oarecare::setComplexElements(Complex **v)
{
	for(int i = 0; i < this->lines; i++)
	{
		for(int j = 0; j < this->columns; j++)
			this->cElements[i][j] = v[i][j];
			
	}
}

Complex *Matrice_oarecare::getComplexAtPosition(int l, int c)
{
	Complex *comp = new Complex;
	if(l > this->lines || c > this->columns)
		return comp;
	
	return Matrice::getComplexAtPosition(l, c);
}

bool Matrice_oarecare::setComplexAtPosition(int l, int c, Complex comp)
{
	if(l > this->lines || c > this->columns)
		return false;
	return Matrice::setComplexAtPosition(l, c, comp);
}


unsigned int Matrice_oarecare::totalMatrix = 0;


void Matrice_oarecare::resize()
{
	this->cElements = new Complex*[this->lines];
	for(int i = 0; i < this->lines; i++)
		this->cElements[i] = new Complex[this->columns];
}

void Matrice_oarecare::destruct()
{
	for(int i = 0; i < this->lines; i++)
		delete []this->cElements[i];
		
	delete []this->cElements;
}

Matrice_oarecare::~Matrice_oarecare()
{
	this->destruct();
	totalMatrix--;
}

