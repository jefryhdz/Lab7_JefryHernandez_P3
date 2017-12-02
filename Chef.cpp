#include "Chef.h"

Chef::Chef(string favorito){
	this->favorito=favorito;
}
Chef::Chef(){

}void Chef::setFavorito(string favorito){
   this-> favorito=favorito;
}
string Chef::getFavorito(){
   return favorito;
}
