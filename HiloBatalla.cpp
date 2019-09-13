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
		bool pausa;
	public:
		HiloBatalla(Usuario* usuario){
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
		
		void run(){
			_beginthread(&HiloBatalla::runner, 0, static_cast<void*>(this));
		}
		
		static void runner(void* o){
			static_cast<HiloBatalla*>(o)->runnerEstatico();
		}
		
		void setPausa(bool x){
			pausa = x;
		}
		
		void runnerEstatico(){
			srand(time(0));
			
			while(vive){
				Sleep(espera);
				
				while(pausa){
				}
				
				int p;
				p =(rand()%100)+1;
				if(p < 80){
					usuario->setEnjuegotrue();
				}
				
				if(!vive){
					_endthread();
				}
			}
		}
};
#endif
