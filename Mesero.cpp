#include "Mesero.h"

Mesero::Mesero(string platillos){
	this->platillos=platillos;
}
Mesero::Mesero(){

}void Mesero::setPlatillos(string platillos){
   this-> platillos=platillos;
}
string Mesero::getPlatillos(){
   return platillos;
}
