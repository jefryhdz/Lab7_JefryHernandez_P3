#include "Lavaplato.h"

Lavaplato::Lavaplato(int edad,int telefono,string nombre,string ID,string username,string password,double Sueldo,string contratacion,double Motivacion):Personal(edad,telefono,nombre,ID,username,password,Sueldo,contratacion){
	this->Motivacion=Motivacion;
}
Lavaplato::Lavaplato(){

}void Lavaplato::setMotivacion(double Motivacion){
   this-> Motivacion=Motivacion;
}
double Lavaplato::getMotivacion(){
   return Motivacion;
}
string Lavaplato::toString(){
	ostringstream os;
	string archivo;
	char ar='L';
	archivo+=ar;
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
	os<<Motivacion;
	archivo+=os.str();
	archivo+=";";
	return archivo;
}
Lavaplato::~Lavaplato(){}
