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

Complex::Complex(Complex &comp)
{
	this->real = comp.getReal();
	this->imag = comp.getImag();
}

void Complex::display()
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

Complex Complex::operator=(Complex &rightC)
{
	this->real = rightC.getReal();
	this->imag = rightC.getImag();
	return *this;
}

std::ostream &operator<<(std::ostream &os, Complex &c)
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

