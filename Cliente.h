#include <iostream>
#include <string>
#include <vector>
#include "Usuario.h"

using namespace std;

#ifndef CLIENTE_H
#define CLIENTE_H
class Cliente :public Usuario{
	protected:
		string Direccion;
		double rating;
	public:
		Cliente(int,int,string,string,string,string,string,double);
		Cliente();
		string getDireccion();
		void setDireccion(string);

		double getRating();
		void setRating(double);

};
#endif