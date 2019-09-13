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
	public:
		Usuario(){
		}
		Usuario(string usuario){
			this->usuario = usuario;
			this->vida = 1;
			this->vidamax = 3;
			this->nivel = 1;
		}
};
#endif
