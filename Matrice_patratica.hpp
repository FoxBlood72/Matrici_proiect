#ifndef MATRICE_PATRATICA_HPP
#define MATRICE_PATRATICA_HPP
#include "Matrice.hpp"

class Matrice_patratica : public Matrice
{
	private:
		int dim;
		void destruct();
		void resize();
	public:
		static unsigned int totalMatrix;
		Matrice_patratica();
		Matrice_patratica(int dim);
		Matrice_patratica(int dim, Complex **v);
		Matrice_patratica(Matrice_patratica &m);
		int getDim();
		void setComplexElements(Complex **v);
		Complex *getComplexAtPosition(int l, int c);
		bool setComplexAtPosition(int l, int c, Complex comp);
		std::ostream &afisare(std::ostream &os);
		Matrice_patratica operator=(Matrice_patratica &m);
		static Complex calculateDeterminant(Complex **mat, int n);
		Complex getDeterminant();
		bool is_diagonal();
//		std::ostream &operator<<(std::ostream &os);
//		std::istream &operator>>(std::istream &is);
		friend std::istream &operator>>(std::istream &is, Matrice_patratica &m);
		friend std::istream &operator>>(std::istream &is, Matrice_patratica *m);
		~Matrice_patratica();

};

#endif // MATRICE_PATRATICA_HPP
