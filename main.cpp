#include <iostream>
#include <vector>
#include <typeinfo>
#include "Complex.hpp"
#include "Matrice.hpp"
#include "Matrice_oarecare.hpp"
#include "Matrice_patratica.hpp"

void demoMatrix()
{
	Complex **v = new Complex*[2];
	for(int i = 0; i < 2; i++)
		v[i] = new Complex[3];
	
	for(int i = 0; i < 2; i++)
		for(int j = 0; j < 3; j++)
		{
			v[i][j].setReal(5);
			v[i][j].setImag(1);
		}
}


void readNMatrix(std::vector<Matrice *> &v_matrix, int &n)
{
	std::cout<<"Cate matrici doriti sa cititi? "<<std::endl;
	std::cin>>n;
	
	for(int i = 0; i < n; i++)
	{
		int mat_opt = 0;
		std::cout<<"Ce tip de matrice doriti sa cititi? "<<std::endl;
		std::cout<<"1. Matrice oarecare cu n linii si m coloane."<<std::endl;
		std::cout<<"2. Matrice patratica cu n linii si n coloane."<<std::endl;
		std::cin>>mat_opt;
		if(mat_opt != 1 && mat_opt != 2)
		{
			i--;
			std::cout<<"Valoare invalida! Reselectati "<<std::endl;
		}
		if(mat_opt == 1)
		{
			Matrice_oarecare *mat = new Matrice_oarecare;
			std::cin>>mat;
			v_matrix.push_back(mat);
		}
		if(mat_opt == 2)
		{
			Matrice_patratica *mat = new Matrice_patratica; // ca pointer deoarece 
			std::cin>>mat;									// obiectul se distruge odata iesit din blocul curent
			v_matrix.push_back(mat);						// o alta metoda era sa declaram obiectul ca static
		}
	}
	
}


void display_matrix(std::vector<Matrice *> &v_matrix, int &n)
{
	int mat_opt;
	std::cout<<"Ce matrice doriti sa afisati? "<<std::endl;
	std::cin>>mat_opt;
	if(mat_opt > n)
	{
		std::cout<<"Valoare invalida, reselectati "<<std::endl;
		display_matrix(v_matrix, n);
	}
	else
	{
		Matrice *disMat = v_matrix.at(mat_opt-1);
		std::cout<<disMat;
	}
}

void menu()
{
	std::cout<<"1. Cititi n matrici patratice sau oarecare "<<std::endl;
	std::cout<<"2. Afisati o matrice patratica sau oarecare din cele memorate "<<std::endl;
	std::cout<<"3. Afisati cate matrici s-au citit de fiecare tip "<<std::endl;
	std::cout<<"4. Verificati daca o matrice triunghiulara este diagonala "<<std::endl;
	std::cout<<"5. Inchideti programul "<<std::endl;
}


void display_total_matrix()
{
	std::cout<<"TOTALUL MATRICILOR: "<<Matrice::totalMatrix<<std::endl;
	std::cout<<"TOTALUL MATRICILOR PATRATICE: "<<Matrice_patratica::totalMatrix<<std::endl;
	std::cout<<"TOTALUL MATRICILOR OARECARE: "<<Matrice_oarecare::totalMatrix<<std::endl;
}


void askForOption(std::vector<Matrice *> &v_matrix, int &n)
{
	menu();
	int opt;
	std::cout<<"Introduceti optiunea: "<<std::endl;
	std::cin>>opt;
	if(opt == 1)
		readNMatrix(v_matrix, n);
	if(opt == 2)
		display_matrix(v_matrix, n);
	if(opt == 3)
		display_total_matrix();
		
		
	askForOption(v_matrix, n);
}


int main()
{
	std::vector<Matrice *> v_matrix;
	int n = 0;
	askForOption(v_matrix, n);
	
	
	return 0;
}
