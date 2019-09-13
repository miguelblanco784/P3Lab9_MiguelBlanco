#include <iostream>
#include <iomanip>
#include <string.h>
#include <vector>
#include <bits/stdc++.h>
#include <typeinfo>
#include <string>
#include <fstream>

#include <windows.h>
#include <process.h>
#include <time.h>

#include "Usuario.cpp"

#include <ctime>    // For time()
#include <cstdlib>  // For srand() and rand()

#ifndef HILOBATALLA_CPP
#define HILOBATALLA_CPP
using namespace std;

class HiloBatalla{
	private:
		bool vive;
		int espera;
		string texto;
		Usuario* usuario;
	public:
		HiloBatalla(Usuario* usuario){
			this->usuario = usuario;
		}	
		
		void setVive(bool v){
			vive = v;
		}	
		
		void setTexto(string t){
			texto = t;
		}
		
		void setEspera(int e){
			espera = e;
		}
		
		void stop(){
			vive = false;
		}
		
		void run(){
			_beginthread(&HiloBatalla::runner, 0, static_cast<void*>(this));
		}
		
		static void runner(void* o){
			static_cast<HiloBatalla*>(o)->runnerEstatico();
		}
		
		void runnerEstatico(){
			srand(time(0));
			
			while(vive){
				Sleep(espera);
				int p;
				p =(rand()%100)+1;
				cout<<p<<endl;
				if(p < 80){
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
							exit(0);
						}
					}	
				}	
				if(!vive){
					_endthread();
				}
			}
		}
};
#endif
