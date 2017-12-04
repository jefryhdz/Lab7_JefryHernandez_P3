#include <iostream>
#include <string>
#include <vector>
#include "Personal.h"

using namespace std;

#ifndef MESERO_H
#define MESERO_H
class Mesero :public Personal{
	protected:
		vector<string> platillos;
	public:
		Mesero(int,int,string,string,string,string,double,string,vector<string>);
		Mesero();
		vector<string> getPlatillos();
		void setPlatillos(vector<string>);
		void Agregarplatillo(string);
		void Eliminaruno(int);
		void Eliminartodo();
		string toString();
		~Mesero();
};
#endif
