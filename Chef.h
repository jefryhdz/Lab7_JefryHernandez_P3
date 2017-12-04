#include <iostream>
#include <string>
#include <vector>
#include "Personal.h"

using namespace std;

#ifndef CHEF_H
#define CHEF_H
class Chef :public Personal{
	protected:
		string favorito;
	public:
		Chef(int,int,string,string,string,string,double,string,string);
		Chef();
		string getFavorito();
		void setFavorito(string);
		string toString();
		~Chef();

};
#endif
