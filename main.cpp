#include <iostream>
#include <string>
#include "Usuario.h"
#include "Cliente.h"
#include "Personal.h"
#include "Administrador.h"
#include "Chef.h"
#include "Lavaplato.h"
#include "Mesero.h"

using namespace std;

vector<Usuario*> Crearcliente(vector<Usuario*>);
/*vector<Usuario*>;
vector<Usuario*>;
vector<Usuario*>;
vector<Usuario*>;
vector<Usuario*>;*/
int menu();

int main(){
	vector<Usuario*>lista;
    char ans='s';
    do
    {
    	int resp =menu();	     
	    if (resp==1)
	    {
	    	lista=Crearcliente(lista);
	    	for (int i = 0; i < lista.size(); ++i)
	    	{
	    		Usuario* user  = lista.at(i);
	    		cout<<i<<" "<<user->getNombre()<<endl;
	    	}
	    }else{
	    	string user,password;
	    	cout<<"Ingrese el username"<<endl;
	    	cin>>user;
	    	cout<<"Ingrese la contraseña"<<endl;
	    	cin>>password;
	    	Usuario* usuario;
	    	for (int i = 0; i < lista.size(); ++i)
	    	{
	    		Usuario* persona  = lista.at(i);
	    		if ((persona->getUsername()==user)&&(persona->getPassword()==password))
	    		{ 
	    			usuario= persona;
	    		}
	    	}
	    }
	   	cout<<"Desea continuar en el programa [s/n] ";
	   	cin>>ans;
    } while (ans=='S'||ans=='s');

   	return 0;
}

int menu(){
	int ans;
	do
	{
		cout<<"1. Crear cliente"<<endl;
		cout<<"2. Login"<<endl;
		cin>>ans;
	} while (ans<1&&ans>2);

	return ans;
}
vector<Usuario*> Crearcliente(vector<Usuario*>lista){
	string nombre,ID,username,password,direccion;
	double rating;
	int edad,telefono;
	cout<<"Ingrese el nombre del usuario"<<endl;
	cin>>nombre;
	cout<<"Ingrese el username"<<endl;
	cin>>username;
	cout<<"Ingrese la password"<<endl;
	cin>>password;
	cout<<"Ingrese la direccion del usuario"<<endl;
	cin>>direccion;
	bool verificacion= true;//para verificar ID unico y edad 
	do
	{
		cout<<"Ingrese el ID"<<endl;
		cin>>ID;	
		for (int i = 0; i < lista.size(); ++i)
		{
			Usuario* user = lista.at(i);
			if (user->getID()==ID)
			{
				cout<<"ID no se pueden ser igual"<<endl;
				verificacion=false;
			}else{
				verificacion=true;
			}
		}
	} while (!verificacion);
	
	cout<<"Ingrese el rating"<<endl;
	cin>>rating;
	cout<<"Ingrese el telefono"<<endl;
	cin>>telefono;
	verificacion= true;
	do
	{
		cout<<"Ingrese la edad"<<endl;
		cin>>edad;
		if (edad<18)
		{
			verificacion=false;
		}else{
			verificacion=true;
		}
		edad= 0;
	} while (!verificacion);
	Usuario* cliente = new Cliente(edad,telefono,nombre,ID,username,password,direccion,rating);
	lista.push_back(cliente);

	return lista;
}
