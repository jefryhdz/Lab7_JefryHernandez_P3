#include <iostream>
#include <string>
#include <vector>
#include "Personal.h"

using namespace std;

#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H
class Administrador : Personal{
	protected:
		int Despedidos;
		int Contratados;
	public:
		Administrador(int,int);
		Administrador();
		int getDespedidos();
		void setDespedidos(int);

		int getContratados();
		void setContratados(int);

};
#endif