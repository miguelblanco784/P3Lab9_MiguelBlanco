#include <iostream>
#include <iomanip>
#include <string.h>
#include <vector>
#include <bits/stdc++.h>
#include <typeinfo>
#include <string>
#include <fstream>

using namespace std;

#include "Usuario.cpp"
int main(){
	string temp;
	cout<<"Ingrese usuario: ";
	cin>>temp;
	Usuario* usuario;
	usuario = new Usuario(temp);
	while(true){
		
	}
	system("pause");
	return 0;
}
