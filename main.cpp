#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Usuario.h"
#include "Cliente.h"
#include "Personal.h"
#include "Administrador.h"
#include "Chef.h"
#include "Lavaplato.h"
#include "Mesero.h"
#include <stdlib.h>
#include <cstdlib>

using namespace std;

vector<Usuario*> menuadmin(vector<Usuario*>,Usuario*);
vector<Usuario*> Crearcliente(vector<Usuario*>);
Usuario* Crearempleado(vector<Usuario*>);
vector<Usuario*> menuchef(vector<Usuario*>);
vector<Usuario*>  menulavaplatos(vector<Usuario*>,Usuario*);
vector<Usuario*> menumesero(vector<Usuario*>,Usuario*);
vector<Usuario*> leer();
void escribir(vector<Usuario*>);

Usuario* Crearempleado();

int menu();

int main(){
    vector<Usuario*>lista;
		if (lista.size()<1) {
			Usuario* admin= new Administrador(20,22231442,"Admin","000001","admin","1234",20000,"01/12/2017",0,0);
			lista.push_back(admin);
		}
    Administrador* admin;
    Chef* chef;
    Lavaplato* lava;
    Mesero* mesero;
    Cliente* cliente;
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
            if (dynamic_cast<Administrador*>(usuario)!=NULL)
            {
                admin=dynamic_cast<Administrador*>(usuario);
								lista= menuadmin(lista,admin);
            }
            else if (dynamic_cast<Chef*>(usuario)!=NULL)
            {
              chef = dynamic_cast<Chef*>(usuario);
						  lista=menuchef(lista);
            }else if (dynamic_cast<Lavaplato*>(usuario)!=NULL)
            {
              lava=dynamic_cast<Lavaplato*>(usuario);
							lista=menulavaplatos(lista,lava);
            }else if (dynamic_cast<Mesero*>(usuario)!=NULL)
            {
                mesero=dynamic_cast<Mesero*>(usuario);
                lista= menumesero(lista,mesero);
            }else if (dynamic_cast<Cliente*>(usuario)!=NULL)
            {
                cliente= dynamic_cast<Cliente*>(usuario);
            }

        }
           cout<<"Desea continuar en el programa [s/n] "<<endl;
           cin>>ans;
    } while (ans=='S'||ans=='s');
    escribir(lista);
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
vector<Usuario*> menuadmin(vector<Usuario*> lista,Usuario* usuario){
    int resp;
    do
    {
        cout<<"----------Menu de administrador---------"<<endl;
        cout<<"1. Contratar empleado"<<endl;
        cout<<"2. Despedir empleado"<<endl;
        cout<<"3. Empleado peor pagado"<<endl;
        cout<<"4. Agregar un platillo a un mesero"<<endl;
        cout<<"5. Empleado mejor pagado"<<endl;
        cout<<"6. Promedio de sueldo"<<endl;
        cout<<"7. Logout"<<endl;
        cin>>resp;
        if (resp==1)
        {
          Usuario* usuario= Crearempleado(lista);

					lista.push_back(usuario);
					cout<<""<<usuario->getNombre()<<endl;

					for (int i = 0; i < lista.size()-1; i++) {
						if (dynamic_cast<Personal*>(lista.at(i))) {
							Personal* user=dynamic_cast<Personal*>(lista.at(i));
							if ((user->getID()==usuario->getID())&&(user->getPassword()==usuario->getPassword()))
							{
								Administrador* admin= dynamic_cast<Administrador*>(user);
									admin->setContratados(admin->getContratados()+1);
							}
						}
					}
					cout<<""<<lista.size()<<endl;
        }
        if (resp==2)
        {
					for (int i = 0; i < lista.size(); i++) {
						cout<<i<<" "<<lista.at(i)->getNombre();
					}
					int seleccion;
					do {
						cout<<"Seleccione la posicion del empleado a despedir "<<endl;
						cin>>seleccion;
					} while(seleccion<0&&seleccion>lista.size()-1);
					for (int i = 0; i < lista.size(); i++) {
						if (i==seleccion) {
							lista.erase(lista.begin()+i);
						}
					}
					for (int i = 0; i < lista.size(); i++) {
						if (dynamic_cast<Personal*>(lista.at(i))) {
							Personal* user=dynamic_cast<Personal*>(lista.at(i));
							if ((user->getID()==usuario->getID())&&(user->getPassword()==usuario->getPassword()))
							{
								Administrador* admin= dynamic_cast<Administrador*>(user);
									admin->setDespedidos(admin->getDespedidos()+1);
							}
						}
					}
        }
				if (resp==3) {
					double low,temp=500000000000;
					vector<Personal*>menores;
					Personal* menor;
					for (int i = 0; i < lista.size(); i++) {
						if (dynamic_cast<Personal*>(lista.at(i))) {
							Personal* personal= dynamic_cast<Personal*>(lista.at(i));
							if (personal->getSueldo()<temp) {
								low=personal->getSueldo();
								temp=low;
								menor=personal;
							}
						}
					}for (int i = 0; i < lista.size(); i++) {
						if (dynamic_cast<Personal*>(lista.at(i))) {
							Personal* personal= dynamic_cast<Personal*>(lista.at(i));
							if (personal->getSueldo()==menor->getSueldo()) {
								menores.push_back(personal);
							}
						}
					}for (int i = 0; i < menores.size(); i++) {
						cout<<i<<". "<<menores.at(i)->getNombre()<<endl;
					}
				}
        if (resp==4)
        {
					int meseroposicion;
					string plato;
					for (int i = 0; i < lista.size(); i++) {
						if (dynamic_cast<Personal*>(lista.at(i))) {
								Personal* personal = dynamic_cast<Personal*>(lista.at(i));
								if (dynamic_cast<Mesero*>(personal)) {
										cout<<i<<". "<<lista.at(i)->getNombre()<<endl;
								}
						}else{

						}
					}cout<<"Seleccione el numero del mesero"<<endl;
					cin>>meseroposicion;
					cout<<"Ingrese el nombre del plato"<<endl;
					cin>>plato;
					for (int i = 0; i < lista.size(); i++) {
						if (i==meseroposicion) {
							dynamic_cast<Mesero*>(lista.at(i))->getPlatillos().push_back(plato);
							/*mesero->getPlatillos().push_back(plato);
              cout<<mesero->getPlatillos().at(0);*/
					  }
          }
        }
        if (resp==5) {
          vector<Personal*>mayores;
  				Personal* may;
          double mayor,temp=0;
					for (int i = 0; i < lista.size(); i++) {
						if (dynamic_cast<Personal*>(lista.at(i))) {
							Personal* personal= dynamic_cast<Personal*>(lista.at(i));
							if (personal->getSueldo()>temp) {
								mayor=personal->getSueldo();
								temp=mayor;
								may=personal;
							}
						}
					}
					for (int i = 0; i < lista.size(); i++) {
						if (dynamic_cast<Personal*>(lista.at(i))) {
							Personal* personal= dynamic_cast<Personal*>(lista.at(i));
							if (personal->getSueldo()==may->getSueldo()) {
								mayores.push_back(personal);
							}
						}
					}for (int i = 0; i < mayores.size(); i++) {
						cout<<i<<". "<<mayores.at(i)->getNombre()<<endl;
					}
        }
        if (resp==6)
        {
					int cont=0;
					double suma=0,promedio;
					for (int i = 0; i < lista.size(); i++) {
						if (dynamic_cast<Personal*>(lista.at(i))) {
							Personal* personal= dynamic_cast<Personal*>(lista.at(i));
							suma+=personal->getSueldo();
							cont++;
						}
					}promedio=suma/cont;
					cout<<"El promedio es "<<promedio;
        }
    } while (resp!=7);
    return lista;
}

vector<Usuario*> menulavaplatos(vector<Usuario*> lista ,Usuario* usuario){
	int ans,aumento, posicion;;
	Personal* personal= dynamic_cast<Personal*>(usuario);
	Lavaplato* lavaplato=dynamic_cast<Lavaplato*>(personal);
	do {
		cout<<"Menu lavaplato"<<endl;
		cout<<"1. Renunciar"<<endl;
		cout<<"2. Pedir aumento"<<endl;
		cin>>ans;
	} while(ans<1&&ans>2);
  for (int i = 0; i < lista.size(); i++) {
    if ((usuario->getUsername()==lista.at(i)->getUsername())&&(usuario->getPassword()==lista.at(i)->getPassword())) {
      posicion=i;
    }
  }
	if (ans==1) {
		if (lavaplato->getSueldo()<=25) {
			lista.erase(lista.begin()+posicion);
		}else{
			cout<<"No puede renunciar"<<endl;
		}
	}if (ans==2) {
		if (lavaplato->getMotivacion()>=100) {
			bool verificar=false;
			do {
				cout<<"Ingrese la cantidad a aumentar"<<endl;
				cin>>aumento;
				if (aumento<=lavaplato->getSueldo()) {
					verificar=true;
				}
			} while(!verificar);
			dynamic_cast<Lavaplato*>(lista.at(posicion))->setSueldo(dynamic_cast<Lavaplato*>(lista.at(posicion))->getSueldo()+aumento);
		}
	}
  return lista;
}

Usuario* Crearempleado(vector<Usuario*> lista){
    int resp;
    Usuario* usuario;
    do
    {
        cout<<"1. Administrador"<<endl;
        cout<<"2. Chef"<<endl;
        cout<<"3. Mesero"<<endl;
        cout<<"4. Lavaplato"<<endl;
        cin>>resp;
    } while (resp<1&&resp>4);
		string nombre,ID,username,password,contratacion;
		int edad,telefono;
		double sueldo;
		cout<<"Ingrese el nombre del usuario"<<endl;
		cin>>nombre;
		cout<<"Ingrese el username"<<endl;
		cin>>username;
		cout<<"Ingrese la password"<<endl;
		cin>>password;
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
		} while (!verificacion);
		cout<<"Ingrese el sueldo de usuario"<<endl;
		cin>>sueldo;
		cout<<"Ingrese la fecha de contratacion"<<endl;
		cin>>contratacion;
		if (resp==1)
    {
        usuario = new Administrador(edad,telefono,nombre,ID,username,password,sueldo,contratacion,0,0);
    }if (resp==2) {
				string plato;
				cout<<"Ingrese su plato favorito"<<endl;
				cin>>plato;
				cout<<"sd"<<endl;
				usuario = new Chef(edad,telefono,nombre,ID,username,password,sueldo,contratacion,plato);
			//7int,int,string,string,string,string,double,string,string
    }if (resp==4) {
    		usuario = new Lavaplato(edad,telefono,nombre,ID,username,password,sueldo,contratacion,50);

    }if (resp==3) {
    		vector<string>platillos;
				usuario= new Mesero(edad,telefono,nombre,ID,username,password,sueldo,contratacion,platillos);
    }
		return usuario;
}
vector<Usuario*> menuchef(vector<Usuario*> lista){
	int ans=0;
	do {
		cout<<"1. Gritarle a un lavaplato "<<endl;
		cout<<"2. Motivar a un lavaplato"<<endl;
		cin>>ans;
	} while(ans<1&&ans>2);
	int opcion;
	cout<<"Escoja el lavaplato"<<endl;
	for (int i = 0; i < lista.size(); i++) {
		Usuario* usuario= lista.at(i);
		if (dynamic_cast<Personal*>(usuario)!=NULL) {
			Personal* personal = dynamic_cast<Personal*>(usuario);
			if (dynamic_cast<Lavaplato*>(personal)!=NULL) {
				cout<<i<<". "<<lista.at(i)->getNombre()<<endl;
			}
		}
	}
	cin>>opcion;
	if (ans==1) {
		int desmotivacion;
		cout<<"Ingrese el numero del grito"<<endl;
		cin>>desmotivacion;
		Usuario* useri= lista.at(opcion);
		Personal* pers = dynamic_cast<Personal*>(useri);
		Lavaplato* lava =dynamic_cast<Lavaplato*>(pers);
		if (desmotivacion>0) {
			desmotivacion*=-1;
		}
    dynamic_cast<Lavaplato*>(lista.at(opcion))->setMotivacion(dynamic_cast<Lavaplato*>(lista.at(opcion))->getMotivacion()+desmotivacion);
	}if (ans==2) {
		int motivacion;
		cout<<"Ingrese el numero del motivacion"<<endl;
		cin>>motivacion;
		if (motivacion<0) {
			motivacion=motivacion*-1;
		}
    dynamic_cast<Lavaplato*>(lista.at(opcion))->setMotivacion(dynamic_cast<Lavaplato*>(lista.at(opcion))->getMotivacion()+motivacion);
	}
  return lista;
}
vector<Usuario*> menumesero(vector<Usuario*>lista,Usuario* usuario){
  int resp,posicion;
  do {
    cout<<"1. Entregar un plato"<<endl;
    cout<<"2. Entregarlos todos"<<endl;
    cin>>resp;
  } while(resp<1&&resp>2);
  for (int i = 0; i < lista.size(); i++) {
    if ((lista.at(i)->getUsername()==usuario->getUsername())&&(lista.at(i)->getPassword()==usuario->getPassword())) {
      posicion=i;
    }
  }
	if (resp==1) {
    int posicion;
  	vector<string>platillos;
  	Personal* pers = dynamic_cast<Personal*>(usuario);
  	Mesero* mesero =dynamic_cast<Mesero*>(pers);
    Mesero* waiter;
  	platillos=(dynamic_cast<Mesero*>(lista.at(posicion)))->getPlatillos();
  cout<<"Escoja el plato a entregar"<<endl;
  	int plato;
  	for (int i = 0; i < platillos.size(); i++) {
  		cout<<i<<". "<<platillos.at(i)<<endl;
  	}cin>>plato;
    dynamic_cast<Mesero*>(lista.at(posicion))->Eliminaruno(plato);

	}else if (resp==2) {
    dynamic_cast<Mesero*>(lista.at(posicion))->Eliminartodo();
	}
  return lista;
}
void escribir(vector<Usuario*>lista){
  ofstream archivo("Usuario.txt");
  if (archivo.is_open()) {
    for (int i = 0; i < lista.size(); i++) {
      archivo<<lista.at(i)->toString();
    }
  }
  archivo.close();
}
vector<Usuario*> leer(){
  vector<Usuario*> lista;
  fstream archivo("Usuario.txt");
  if (archivo.is_open()) {
  while(!archivo.eof()){
    string emp,edad,telefono,nombre, ID, username, password, contratacion,sueldo;
    double Sueldo;
    int eda,telefon;
    double salario;
    //int edad,int telefono,string nombre,string ID,string username,string password,double Sueldo,string contratacion,int Despedidos,int Contratados
    getline(archivo,emp,',');
    if (emp == "A") {
      int contratado, despedido;
      string contrata,despesdi;
      getline(archivo,edad,',');
      eda = atoi(edad.c_str());
      getline(archivo,telefono,',');
      telefon= atoi(telefono.c_str());
      getline(archivo,nombre,',');
      getline(archivo,ID,',');
      getline(archivo,username,',');
      getline(archivo,password,',');
      getline(archivo,sueldo,',');
      Sueldo = atoi(sueldo.c_str());
      getline(archivo,contratacion,',');
      getline(archivo,contrata,',');
      contratado = atoi(contrata.c_str());
      getline(archivo,despesdi,';');
      despedido= atoi(despesdi.c_str());
      lista.push_back(new Administrador(eda,telefon,nombre,ID,username,password,Sueldo,contratacion,despedido,contratado));
    }

    if (emp == "H") {
      //(int edad,int telefono,string nombre,string ID,string username,string password,double Sueldo,string contratacion,string favorito
      string plato;
      getline(archivo,edad,',');
      eda = atoi(edad.c_str());
      getline(archivo,telefono,',');
      telefon= atoi(telefono.c_str());
      getline(archivo,nombre,',');
      getline(archivo,ID,',');
      getline(archivo,username,',');
      getline(archivo,password,',');
      getline(archivo,sueldo,',');
      Sueldo = atoi(sueldo.c_str());
      getline(archivo,plato,';');
      lista.push_back(new Chef(eda,telefon,nombre,ID,username,password,Sueldo,contratacion,plato));
    }


    if (emp == "C") {
      //int edad,int telefono,string nombre,string ID,string username,string password,string Direccion,double rating
      string direccion,ranking;
      int rating;
      getline(archivo,edad,',');
      eda = atoi(edad.c_str());
      getline(archivo,telefono,',');
      telefon= atoi(telefono.c_str());
      getline(archivo,nombre,',');
      getline(archivo,ID,',');
      getline(archivo,username,',');
      getline(archivo,password,',');
      getline(archivo,direccion,',');
      getline(archivo,ranking,';');
      rating = atoi(ranking.c_str());
      lista.push_back(new Cliente(eda,telefon,nombre,ID,username,password,direccion,rating));
    }

    if (emp == "M") {
      //int edad,int telefono,string nombre,string ID,string username,string password,double Sueldo,string contratacion
      getline(archivo,edad,',');
      eda = atoi(edad.c_str());
      getline(archivo,telefono,',');
      telefon= atoi(telefono.c_str());
      getline(archivo,nombre,',');
      getline(archivo,ID,',');
      getline(archivo,username,',');
      getline(archivo,password,',');
      getline(archivo,sueldo,',');
      Sueldo = atoi(sueldo.c_str());
      vector<string>platos;
      lista.push_back(new Mesero(eda,telefon,nombre,ID,username,password,Sueldo,contratacion,platos));
    }

    if (emp == "L") {
      //int edad,int telefono,string nombre,string ID,string username,string password,double Sueldo,string contratacion,double Motivacion
      string motiv;
      double motivacion;
      getline(archivo,edad,',');
      eda = atoi(edad.c_str());
      getline(archivo,telefono,',');
      telefon= atoi(telefono.c_str());
      getline(archivo,nombre,',');
      getline(archivo,ID,',');
      getline(archivo,username,',');
      getline(archivo,password,',');
      getline(archivo,sueldo,',');
      Sueldo = atoi(sueldo.c_str());
      getline(archivo,motiv,';');
      motivacion = atoi(motiv.c_str());
      lista.push_back(new Lavaplato(eda,telefon,nombre,ID,username,password,Sueldo,contratacion,motivacion));
    }
  }

    archivo.close();
    return lista;

  }
}
