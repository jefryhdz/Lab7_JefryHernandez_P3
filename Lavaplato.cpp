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
