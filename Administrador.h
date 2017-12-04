#include <iostream>
#include <string>
#include <vector>
#include "Personal.h"
#include "Usuario.h"

using namespace std;

#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H
class Administrador :public Personal{
	protected:
		int Despedidos;
		int Contratados;
	public:
		Administrador(int,int,string,string,string,string,double,string,int,int);
		Administrador();
		int getDespedidos();
		void setDespedidos(int);

		int getContratados();
		void setContratados(int);
		string toString();
		~Administrador();

};
#endif
