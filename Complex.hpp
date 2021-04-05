#ifndef COMPLEX_HPP
#define COMPLEX_HPP
#include <iostream>

class Complex
{
	private:
		float real;
		float imag;
	public:
		Complex();
		Complex(float real);
		Complex(float real, float imag);
		Complex(Complex const &comp);
		float getReal();
		float getImag();
		void setReal(float real);
		void setImag(float imag);
		void display() const; // pentru a obtine sire de operatii
		Complex operator=(const Complex &rightC);
		Complex operator+(const Complex &rightC) const;// pentru a obtine sire de operatii
		Complex operator-(const Complex &rightC) const;// pentru a obtine sire de operatii
		Complex operator*(const Complex &rightC) const;// pentru a obtine sire de operatii
		friend Complex operator*(const double d, const Complex &rightC);
		friend std::ostream &operator<<(std::ostream &os, const Complex &c);// pentru a obtine sire de operatii
		friend std::istream &operator>>(std::istream &in, Complex &c);
		~Complex();

};

#endif // COMPLEX_HPP
