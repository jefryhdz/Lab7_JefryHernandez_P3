#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;


#ifndef USUARIO_H
#define USUARIO_H
class Usuario{
	protected:
		int edad;
		int telefono;
		string nombre;
		string ID;
		string username;
		string password;
	public:
		Usuario(int,int,string,string,string,string);
		Usuario();
		int getEdad();
		void setEdad(int);

		int getTelefono();
		void setTelefono(int);

		string getNombre();
		void setNombre(string);

		string getID();
		void setID(string);

		string getUsername();
		void setUsername(string);

		string getPassword();
		void setPassword(string);

		virtual~Usuario();
		virtual string toString();

};
#endif
