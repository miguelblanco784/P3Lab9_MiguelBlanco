#include <iostream>
#include <iomanip>
#include <string.h>
#include <vector>
#include <bits/stdc++.h>
#include <typeinfo>
#include <string>
#include <fstream>

using namespace std;

#include "Usuario.cpp"
int main(){
	string temp;
	cout<<"Ingrese usuario: ";
	cin>>temp;
	Usuario* usuario;
	usuario = new Usuario(temp);
	while(true){
		int opcion;
		cout<<"-=Menu=-"<<endl;
		cout<<"1- Datos del Jugador\n2- Curar Vida ($1)\n0- Salir\nSeleccione opcion: "<<endl;
		cin>>opcion;
		switch(opcion){
			case 1:{
				
				break;
			}
			case 2:{
				
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
