#include <iostream>
#include <string>
#include <vector>
#include "Personal.h"

using namespace std;

#ifndef MESERO_H
#define MESERO_H
class Mesero : Personal{
	protected:
		string platillos;
	public:
		Mesero(string);
		Mesero();
		string getPlatillos();
		void setPlatillos(string);

};
#endif