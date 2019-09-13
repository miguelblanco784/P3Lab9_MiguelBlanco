#include <iostream>
#include <iomanip>
#include <string.h>
#include <vector>
#include <bits/stdc++.h>
#include <typeinfo>
#include <string>
#include <fstream>


using namespace std;

#ifndef USUARIO_CPP
#define USUARIO_CPP
class Usuario{
	private:
		string usuario;
		int vida;
		int vidamax;
		int nivel;
		int dinero;
		bool enjuego;
	public:
		Usuario(){
		}
		Usuario(string usuario){
			this->usuario = usuario;
			this->vida = 1;
			this->vidamax = 3;
			this->nivel = 1;
			this->dinero = 0;
			this->enjuego = false;
		}
		
		~Usuario(){
		}
		
		bool getEnjuego(){
			return enjuego;
		}
		
		void setEnjuegotrue(){
			enjuego = true;
		}
		
		void setNivel(int x){
			nivel = x;
		}
		
		void setVidmax(int x){
			vidamax = x;
		}
		
		void setEnjuegofalse(){
			enjuego = false;
		}
		
		int getVida(){
			return vida;
		}
		
		int getVidamax(){
			return vidamax;
		}
		
		int getNivel(){
			return nivel;
		}
		
		int getDinero(){
			return dinero;
		}
		
		void setDinero(int dinero){
			this->dinero = dinero;
		}
		
		void setVida(int vida){
			this->vida = vida;
		}
};
#endif
