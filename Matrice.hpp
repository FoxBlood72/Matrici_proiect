#ifndef MATRICE_HPP
#define MATRICE_HPP
#include "Complex.hpp"

class Matrice
{
	protected:
		Complex **cElements;
		virtual void resize() = 0;
	public:
		static unsigned int totalMatrix;
		Matrice();
		Matrice(Complex **cElements);
		Matrice(Matrice &m);
		Complex **getComplexElements();
		virtual void setComplexElements(Complex **cElements) = 0;
		virtual bool setComplexAtPosition(int l, int c, Complex comp);
		virtual Complex *getComplexAtPosition(int l, int c);
		virtual std::ostream &afisare(std::ostream &os) = 0; // a durat mult sa gasesc metoda asta
		friend std::ostream &operator<<(std::ostream &os, Matrice &mat); // fiecare subclasa are proria ei functie de afisare
		friend std::ostream &operator<<(std::ostream &os, Matrice *mat); // aceasta se apeleaza cu operatorul <<
		~Matrice();

};

#endif // MATRICE_HPP
