#include <iostream>
#include <string>
#include <vector>
#include "Personal.h"

using namespace std;

#ifndef CHEF_H
#define CHEF_H
class Chef : Personal{
	protected:
		string favorito;
	public:
		Chef(string);
		Chef();
		string getFavorito();
		void setFavorito(string);

};
#endif