#include "Administrador.h"

Administrador::Administrador(int Despedidos,int Contratados){
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
