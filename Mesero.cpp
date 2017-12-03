#include "Mesero.h"

Mesero::Mesero(int edad,int telefono,string nombre,string ID,string username,string password,double Sueldo,string contratacion,vector<string> platillos):Personal(edad,telefono,nombre,ID,username,password,Sueldo,contratacion){
	this->platillos=platillos;
}
Mesero::Mesero(){

}void Mesero::setPlatillos(vector<string> platillos){
   this-> platillos=platillos;
}
vector<string>Mesero::getPlatillos(){
   return platillos;
}
void Mesero::Agregarplatillo(string platillo){
	platillos.push_back(platillo);
}
void Mesero::Eliminaruno(int posicion){
	for (int i = 0; i < platillos.size() ; i++) {
		if (posicion ==i) {
			platillos.erase(platillos.begin()+i);
			break;
		}
	}
}
void Mesero::Eliminartodo(){
	for (int i = 0; i < platillos.size(); i++) {
		platillos.erase(platillos.begin()+i);
	}
}
