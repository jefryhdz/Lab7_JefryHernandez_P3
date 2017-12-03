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
