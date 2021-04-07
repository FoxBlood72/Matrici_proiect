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


void check_diagonal_matrix(std::vector<Matrice *> &v_matrix, int &n)
{
	int mat_opt;
	std::cout<<"Ce matrice doriti sa verificati? 0 pentru intoarcere la meniu. "<<std::endl;
	std::cin>>mat_opt;
	if(mat_opt == 0)
		return;
	
	if(mat_opt > n)
	{
		std::cout<<"Matrice invalida! reselectati "<<std::endl;
		return check_diagonal_matrix(v_matrix, n);
	}
	Matrice *m = v_matrix.at(mat_opt-1);
	if(Matrice_patratica *m_sqr = dynamic_cast<Matrice_patratica *>(m)) // concept de downcasting
	{
		std::cout<<"Matricea este: "<<std::endl<<m_sqr<<std::endl;
		if(m_sqr->is_diagonal())
			std::cout<<"Prin urmare este diagonala "<<std::endl;
		else
			std::cout<<"Prin urmare NU este diagonala "<<std::endl;
			
	}
	else
	{
		std::cout<<"Matricea selectata nu este patratica! reselectati "<<std::endl;
		return check_diagonal_matrix(v_matrix, n);
	}
	
	
}


void readNMatrix(std::vector<Matrice *> &v_matrix, int &n)
{
	for(std::vector<Matrice *>::iterator it = v_matrix.begin(); it != v_matrix.end(); it++)
		delete *it;
	v_matrix.clear();
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
		if(mat_opt == 1) // concept de upcasting
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


void sqr_matrix_determinant()
{
	int n;
	std::cout<<"Ce dimensiune sa aiba matricea? "<<std::endl;
	std::cin>>n;
	Complex **v = new Complex*[n];
	for(int i = 0; i < n; i++)
		v[i] = new Complex[n];
	
	
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
		{
			std::cout<<"Citim valoarea ["<<i+1<<"]["<<j+1<<"]: "<<std::endl;
			std::cin>>v[i][j];
		}
	
	Complex result = Matrice_patratica::calculateDeterminant(v, n);
	std::cout<<"Determinantul matricei este: "<<std::endl;
	std::cout<<result<<std::endl;
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
	std::cout<<"5. Obtineti determinantul unei matrici patratice "<<std::endl;
	std::cout<<"6. Inchideti programul "<<std::endl;
}


void display_total_matrix()
{
	std::cout<<"TOTALUL MATRICELOR: "<<Matrice::totalMatrix<<std::endl;
	std::cout<<"TOTALUL MATRICELOR PATRATICE: "<<Matrice_patratica::totalMatrix<<std::endl;
	std::cout<<"TOTALUL MATRICELOR OARECARE: "<<Matrice_oarecare::totalMatrix<<std::endl;
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
	if(opt == 4)
		check_diagonal_matrix(v_matrix, n);
	if(opt == 5)
		sqr_matrix_determinant();
	if(opt == 6)
		return;
		
		
	askForOption(v_matrix, n);
}


int main()
{
	std::vector<Matrice *> v_matrix;
	int n = 0;
	askForOption(v_matrix, n);
	for(std::vector<Matrice *>::iterator it = v_matrix.begin(); it != v_matrix.end(); it++)
		delete *it;
	v_matrix.clear();
	
	return 0;
}
