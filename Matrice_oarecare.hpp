#ifndef MATRICE_OARECARE_HPP
#define MATRICE_OARECARE_HPP
#include "Matrice.hpp"
#include "Complex.hpp"

class Matrice_oarecare: public Matrice
{
	private:
		int lines;
		int columns;
		void destruct();
		void resize();
	public:
		static unsigned int totalMatrix;
		Matrice_oarecare();
		Matrice_oarecare(int lines, int columns);
		Matrice_oarecare(int lines, int columns, Complex **v);
		Matrice_oarecare(Matrice_oarecare &m);
		int getLines();
		int getColumns();
		friend std::istream &operator>>(std::istream &os, Matrice_oarecare &m);
		friend std::istream &operator>>(std::istream &os, Matrice_oarecare *m);
//		std::ostream &operator<<(std::ostream &os, Matrice_oarecare &mat);
		std::ostream &afisare(std::ostream &os);
		Matrice_oarecare operator=(Matrice_oarecare &rightMatrix);
		void setComplexElements(Complex **cElements);
		Complex *getComplexAtPosition(int l, int c);
		bool setComplexAtPosition(int l, int c, Complex comp);
		~Matrice_oarecare();

};

#endif // MATRICE_OARECARE_HPP
