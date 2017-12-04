#include "Cliente.h"

Cliente::Cliente(int edad,int telefono,string nombre,string ID,string username,string password,string Direccion,double rating):Usuario(edad,telefono,nombre,ID,username,password){
	this->Direccion=Direccion;
	this->rating=rating;
}
Cliente::Cliente(){

}void Cliente::setDireccion(string Direccion){
   this-> Direccion=Direccion;
}
string Cliente::getDireccion(){
   return Direccion;
}
void Cliente::setRating(double rating){
   this-> rating=rating;
}
double Cliente::getRating(){
   return rating;
}
Cliente::~Cliente(){
}
string Cliente::toString(){
	ostringstream os;
	string archivo;
	char ar ='C';
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
	archivo+=Direccion;
	archivo+=",";
	os<<rating;
	archivo+=os.str();
	archivo+=";";
	return archivo;
}
