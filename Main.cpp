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
#include "HiloVida.cpp"

#include <ctime>    // For time()
#include <cstdlib>  // For srand() and rand()

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
	
	HiloVida h3(usuario);
	h3.setVive(true);
	h3.setTexto("Hola Mundo!" );
	h3.setEspera(6000);
	h3.setPausa(false);
	h3.run();
	
	while(true){
		int opcion;
		cout<<"-=Menu=-"<<endl;
		cout<<"1- Datos del Jugador\n2- Curar Vida ($1)\n0- Salir\nSeleccione opcion: "<<endl;
		if(usuario->getEnjuego()){
			h2.setPausa(true);
			h3.setPausa(true);
			h1.setPausa(true);
			int cont = 0;
			while(cont < usuario->getNivel()){
				int herramienta;
				cout<<"1- Piedra\n2- Papel\n3- Tijera\nIngrese: ";
				cin>>herramienta;
				
				int computadora;
				computadora = (rand()%3)+1;
				
				if(computadora == 1 && herramienta == 1) {
				    cout << "Empate" << endl;
				    
				} else if (computadora == 1 && herramienta == 3) {
				    cout << "-1 Vida" << endl;
				    usuario->setVida(usuario->getVida()-1);
				    
				} else if (computadora == 2 && herramienta == 2) {
				    cout << "Empate" << endl;
				    
				} else if (computadora == 2 && herramienta == 1) {
				    cout << "-1 Vida" << endl;
				    usuario->setVida(usuario->getVida()-1);
				    
				} else if (computadora == 3 && herramienta == 3) {
				    cout << "Empate " << endl;
				    
				} else if (computadora == 3 && herramienta == 2) {
				    cout << "-1 Vida" << endl;
				    usuario->setVida(usuario->getVida()-1);
				    
				} else {
				    cout << "Ganaste!" << endl;
				    cont++;
				}
				
				
				if(usuario->getVida() <= 0){
					cout<<endl<<"Moriste!"<<endl;
					h1.setVive(false);
					h2.setVive(false);
					h3.setVive(false);
					usuario->~Usuario();
					delete usuario;
					exit(0);
				}	
			}
			usuario->setNivel(usuario->getNivel()+1);
			usuario->setVidmax(usuario->getVidamax()+1);
			h2.setPausa(false);
			h3.setPausa(false);
			h1.setPausa(false);
			usuario->setEnjuegofalse();
		}else{
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
					h1.setVive(false);
					h2.setVive(false);
					h3.setVive(false);
					usuario->~Usuario();
					delete usuario;
					exit(0);
					break;
				}
			}
		}
	}
	system("pause");
	return 0;
}
