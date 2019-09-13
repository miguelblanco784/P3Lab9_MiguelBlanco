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

#ifndef HILODINERO_CPP
#define HILODINERO_CPP
using namespace std;

class HiloDinero{
	private:
		bool vive;
		int espera;
		string texto;
		Usuario* usuario;
		bool pausa;
	public:
		HiloDinero(Usuario* usuario){
			this->usuario = usuario;
			pausa = false;
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
		
		void setPausa(bool x){
			pausa = x;
		}
		void run(){
			_beginthread(&HiloDinero::runner, 0, static_cast<void*>(this));
		}
		
		static void runner(void* o){
			static_cast<HiloDinero*>(o)->runnerEstatico();
		}
		
		
		
		void runnerEstatico(){
			while(vive){
				Sleep(espera);
				while(pausa){
					
				}
				usuario->setDinero(usuario->getDinero()+1);
				cout<<"1+ Le agrego dinero!"<<endl;
				cout<<"Seleccione Opcion: "<<endl;
				if(!vive){
					_endthread();
				}
			}
		}
};
#endif
