#include <iostream>
#include <iomanip>
#include <string.h>
#include <vector>
#include <bits/stdc++.h>
#include <typeinfo>
#include <string>
#include <fstream>
#include "HiloBatalla.cpp"
#include "HiloDinero.cpp"
using namespace std;

#include "Usuario.cpp"
int main(){
	string temp;
	cout<<"Ingrese usuario: ";
	cin>>temp;
	Usuario* usuario;
	usuario = new Usuario(temp);
	
	HiloBatalla h1(usuario);
	h1.setVive(true);
	h1.setTexto("Hola Mundo!" );
	h1.setEspera(10000);
	h1.run();
	
	HiloDinero h2(usuario);
	h2.setVive(true);
	h2.setTexto("Hola Mundo!" );
	h2.setEspera(7000);
	h2.setPausa(false);
	h2.run();
	
	HiloDinero h3(usuario);
	h3.setVive(true);
	h3.setTexto("Hola Mundo!" );
	h3.setEspera(6000);
	h3.setPausa(false);
	h3.run();
	
	while(true){
		int opcion;
		cout<<"-=Menu=-"<<endl;
		cout<<"1- Datos del Jugador\n2- Curar Vida ($1)\n0- Salir\nSeleccione opcion: "<<endl;
		cin>>opcion;
		switch(opcion){
			case 1:{
				cout<<"Vida: "<<usuario->getVida()<<"/"<<usuario->getVidamax()<<endl;
				cout<<"Dinero: "<<usuario->getDinero()<<endl;
				cout<<"Nivel: "<<usuario->getNivel()<<endl;
				break;
			}
			case 2:{
				if(usuario->getDinero() != 0){
					usuario->setDinero(usuario->getDinero()-1);
					usuario->setVida(usuario->getVida()+1);
				}
				break;
			}
			case 0:{
				exit(0);
				break;
			}
		}
	}
	system("pause");
	return 0;
}
