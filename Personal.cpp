#include "Personal.h"

Personal::Personal(double Sueldo,string contratacion){
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
