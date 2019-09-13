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


#ifndef HILO_CPP
#define HILO_CPP
using namespace std;

class Hilo{
	private:
		bool vive;
		int espera;
		string texto;
	public:
		Hilo(){
			
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
				   // current date/time based on current system
				   time_t now = time(0);
				   
				   // convert now to string form
				   char* dt = ctime(&now);
							
				   // convert now to tm struct for UTC
				   tm *gmtm = gmtime(&now);
				   dt = asctime(gmtm);
				ofstream Escribir;
				Escribir.open("./hilo.txt",ios::app);
				Escribir<<dt<<endl;
				Escribir.close();	
				if(!vive){
					_endthread();
				}
			}
		}
};
#endif
