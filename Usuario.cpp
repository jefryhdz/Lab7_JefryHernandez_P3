#include "Usuario.h"

Usuario::Usuario(int edad,int telefono,string nombre,string ID,string username,string password){
	this->edad=edad;
	this->telefono=telefono;
	this->nombre=nombre;
	this->ID=ID;
	this->username=username;
	this->password=password;
}
Usuario::Usuario(){

}

void Usuario::setEdad(int edad){
   this-> edad=edad;
}
int Usuario::getEdad(){
   return edad;
}
void Usuario::setTelefono(int telefono){
   this-> telefono=telefono;
}
int Usuario::getTelefono(){
   return telefono;
}
void Usuario::setNombre(string nombre){
   this-> nombre=nombre;
}
string Usuario::getNombre(){
   return nombre;
}
void Usuario::setID(string ID){
   this-> ID=ID;
}
string Usuario::getID(){
   return ID;
}
void Usuario::setUsername(string username){
   this-> username=username;
}
string Usuario::getUsername(){
   return username;
}
void Usuario::setPassword(string password){
   this-> password=password;
}
string Usuario::getPassword(){
   return password;
}
Usuario::~Usuario(){
}

