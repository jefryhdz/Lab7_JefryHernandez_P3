#include "Administrador.h"

Administrador::Administrador(int edad,int telefono,string nombre,string ID,string username,string password,double Sueldo,string contratacion,int Despedidos,int Contratados):Personal(edad,telefono,nombre,ID,username,password,Sueldo,contratacion){
	this->Despedidos=Despedidos;
	this->Contratados=Contratados;
}
Administrador::Administrador(){

}void Administrador::setDespedidos(int Despedidos){
   this-> Despedidos=Despedidos;
}
int Administrador::getDespedidos(){
   return Despedidos;
}
void Administrador::setContratados(int Contratados){
   this-> Contratados=Contratados;
}
int Administrador::getContratados(){
   return Contratados;
}
