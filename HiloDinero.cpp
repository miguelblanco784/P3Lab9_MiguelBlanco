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
	public:
		HiloDinero(Usuario* usuario){
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
			_beginthread(&Hilo::runner, 0, static_cast<void*>(this));
		}
		
		static void runner(void* o){
			static_cast<Hilo*>(o)->runnerEstatico();
		}
		
		void runnerEstatico(){
			while(vive){
				Sleep(espera);
					usuario->setDinero(usuario->getDinero()+1);
				if(!vive){
					_endthread();
				}
			}
		}
};
#endif
