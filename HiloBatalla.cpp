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
			int p;
			while(vive){
				p =(rand()%100)+1;
				if(p < 80){
					
				}
//				Sleep(espera);
//				   // current date/time based on current system
//				   time_t now = time(0);
//				   
//				   // convert now to string form
//				   char* dt = ctime(&now);
//							
//				   // convert now to tm struct for UTC
//				   tm *gmtm = gmtime(&now);
//				   dt = asctime(gmtm);
//				ofstream Escribir;
//				Escribir.open("./hilo.txt",ios::app);
//				Escribir<<dt<<endl;
//				Escribir.close();	
				if(!vive){
					_endthread();
				}
			}
		}
};
#endif
