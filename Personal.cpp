#include "Personal.h"

Personal::Personal(int edad,int telefono,string nombre,string ID,string username,string password,double Sueldo,string contratacion):Usuario(edad,telefono,nombre,ID,username,password){
	this->Sueldo=Sueldo;
	this->contratacion=contratacion;

}
Personal::Personal(){

}void Personal::setSueldo(double Sueldo){
   this-> Sueldo=Sueldo;
}
double Personal::getSueldo(){
   return Sueldo;
}
void Personal::setContratacion(string contratacion){
   this-> contratacion=contratacion;
}
string Personal::getContratacion(){
   return contratacion;
}
Personal::~Personal(){}
string Personal::toString(){
	return "";
}
