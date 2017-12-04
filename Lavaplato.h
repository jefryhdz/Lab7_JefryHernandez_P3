#include <iostream>
#include <string>
#include <vector>
#include "Personal.h"

using namespace std;

#ifndef LAVAPLATO_H
#define LAVAPLATO_H
class Lavaplato :public Personal{
	protected:
		double Motivacion;
	public:
		Lavaplato(int,int,string,string,string,string,double,string,double);
		Lavaplato();
		double getMotivacion();
		void setMotivacion(double);
		string toString();
		~Lavaplato();
};
#endif
