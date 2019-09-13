#include <iostream>
#include <iomanip>
#include <string.h>
#include <vector>
#include <bits/stdc++.h>
#include <typeinfo>
#include <string>
#include <fstream>
#include "HiloBatalla.cpp"
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
