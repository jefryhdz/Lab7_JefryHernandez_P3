#include <iostream>
#include <string>
#include <vector>
#include "Usuario.h"

using namespace std;

#ifndef PERSONAL_H
#define PERSONAL_H
class Personal : Usuario{
	protected:
		double Sueldo;
		string contratacion;
	public:
		Personal(double,string);
		Personal();
		double getSueldo();
		void setSueldo(double);

		string getContratacion();
		void setContratacion(string);

};
#endif