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
		Complex(Complex &comp);
		float getReal();
		float getImag();
		void setReal(float real);
		void setImag(float imag);
		void display();
		Complex operator=(Complex &rightC);
		friend std::ostream &operator<<(std::ostream &os, Complex &c);
		friend std::istream &operator>>(std::istream &in, Complex &c);
		~Complex();

};

#endif // COMPLEX_HPP
