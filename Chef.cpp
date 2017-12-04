#include "Chef.h"

Chef::Chef(int edad,int telefono,string nombre,string ID,string username,string password,double Sueldo,string contratacion,string favorito):Personal(edad,telefono,nombre,ID,username,password,Sueldo,contratacion){
	this->favorito=favorito;
}
Chef::Chef(){

}void Chef::setFavorito(string favorito){
   this-> favorito=favorito;
}
string Chef::getFavorito(){
   return favorito;
}
string Chef::toString(){
	ostringstream os;
	string archivo;
	char ar= 'H';
	archivo+=ar;
	archivo+=",";
	os<<edad;
	archivo+=os.str();
	archivo+=",";
	os<<telefono;
	archivo+=os.str();
	archivo+=",";
	archivo+=nombre;
	archivo+=",";
	archivo+=ID;
	archivo+=",";
	archivo+=username;
	archivo+=",";
	archivo+=password;
	archivo+=",";
	os<<Sueldo;
	archivo+=os.str();
	archivo+=",";
	archivo+=contratacion;
	archivo+=",";
	archivo+=favorito;
	archivo+=";";
}
Chef::~Chef(){}
