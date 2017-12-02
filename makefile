main:    main.cpp Usuario.o Cliente.o Personal.o Administrador.o Chef.o Lavaplato.o Mesero.o 
	g++ main.cpp Usuario.o Cliente.o Personal.o Administrador.o Chef.o Lavaplato.o Mesero.o -o main
main.o:	main.cpp Usuario.h Cliente.h Personal.h Administrador.h Chef.h Lavaplato.h Mesero.h 
	g++ -c main.cpp
Usuario:	Usuario.cpp Usuario.h
	g++ -c Usuario.cppCliente:	Cliente.cpp Cliente.h
	g++ -c Cliente.cppPersonal:	Personal.cpp Personal.h
	g++ -c Personal.cppAdministrador:	Administrador.cpp Administrador.h
	g++ -c Administrador.cppChef:	Chef.cpp Chef.h
	g++ -c Chef.cppLavaplato:	Lavaplato.cpp Lavaplato.h
	g++ -c Lavaplato.cppMesero:	Mesero.cpp Mesero.h
	g++ -c Mesero.cpp
clean:
	rm  *.o main 