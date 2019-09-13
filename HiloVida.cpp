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

#ifndef HILOVIDA_CPP
#define HILOVIDA_CPP
using namespace std;

class HiloVida{
	private:
		bool vive;
		int espera;
		string texto;
		Usuario* usuario;
		bool pausa;
	public:
		HiloVida(Usuario* usuario){
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
			_beginthread(&HiloVida::runner, 0, static_cast<void*>(this));
		}
		
		static void runner(void* o){
			static_cast<HiloVida*>(o)->runnerEstatico();
		}
		
		void runnerEstatico(){
			while(vive){
				while(pausa){
					
				}
				
				Sleep(espera);
			
				
				if(usuario->getVida() < usuario->getVidamax()){
					cout<<"1+ De vida"<<endl;
					cout<<"Seleccione Opcion:"<<endl;
					usuario->setVida(usuario->getVida()+1);
				}
				
				if(!vive){
					_endthread();
				}
			}
		}
};
#endif
