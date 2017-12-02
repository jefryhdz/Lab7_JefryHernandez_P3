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
