#include <iostream>
#include <string>
#include <vector>
#include "Usuario.h"

using namespace std;

#ifndef PERSONAL_H
#define PERSONAL_H
class Personal :public Usuario{
	protected:
		double Sueldo;
		string contratacion;
	public:
		Personal(int,int,string,string,string,string,double,string);
		Personal();
		double getSueldo();
		void setSueldo(double);

		string getContratacion();
		void setContratacion(string);
		~Personal();
		string toString();
};
#endif
