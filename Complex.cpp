#include <iostream>
#include "Complex.hpp"

Complex::Complex()
{
	this->real = 0;
	this->imag = 0;
}

Complex::Complex(float real)
{
	this->real = real;
	this->imag = 0;
}

Complex::Complex(float real, float imag)
{
	this->real = real;
	this->imag = imag;
}

Complex::Complex(Complex const &comp)
{
	this->real = comp.real;
	this->imag = comp.imag;
}

void Complex::display() const
{
	if(imag >= 0)
		std::cout<<real<<"+"<<imag<<"i";
	else
		std::cout<<real<<imag<<"i";
}

float Complex::getReal()
{
	return this->real;
}

float Complex::getImag()
{
	return this->imag;
}

void Complex::setReal(float real)
{
	this->real = real;
}

void Complex::setImag(float imag)
{
	this->imag = imag;
}

Complex Complex::operator=(const Complex &rightC)
{
	this->real = rightC.real;
	this->imag = rightC.imag;
	return *this;
}

Complex Complex::operator+(const Complex &rightC) const
{
	Complex comp;
	comp.setReal(this->real + rightC.real);
	comp.setImag(this->imag + rightC.imag);
	
	return comp;
}

Complex Complex::operator-(const Complex &rightC) const
{
	Complex comp;
	comp.setReal(this->real - rightC.real);
	comp.setImag(this->imag - rightC.imag);
	return comp;
}

Complex Complex::operator*(const Complex &rightC) const
{
	Complex comp;
	float real = this->real * rightC.real - this->imag * rightC.imag;
	float imag = this->real* rightC.imag + rightC.real * this->imag; 
	comp.setImag(imag);
	comp.setReal(real);
	return comp;
}

Complex operator*(const double d, const Complex &rightC)
{
	Complex comp;
	comp.setReal(d * rightC.real);
	comp.setImag(d * rightC.imag);
	return comp;
}

std::ostream &operator<<(std::ostream &os, const Complex &c)
{
	c.display();
	return os;
}

std::istream &operator>>(std::istream &is, Complex &c)
{
	std::cout<<"Partea reala: ";
	std::cin>>c.real;
	std::cout<<"Partea imaginara: ";
	std::cin>>c.imag;
	return is;
}






Complex::~Complex()
{
	this->real = 0;
	this->imag = 0;
}

