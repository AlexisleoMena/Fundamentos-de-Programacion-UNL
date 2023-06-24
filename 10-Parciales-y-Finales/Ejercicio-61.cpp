/*
Ejercicio 1 [25 pts] Escriba un programa que permita leer una serie de valores numéricos enteros y los almacene
en un arreglo. Se desconoce de antemano de cuántos valores se trata, pero se sabe que la lectura de datos termina
cuando se ingresa el valor -1. Escriba una función que cuente la cantidad de valores que se encuentran por
encima del promedio e inserte dicha cantidad al principio del arreglo. Utilizar la función desde el programa
principal y mostrar el arreglo antes y después de la inserción.
*/
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void Mostrar(vector<int> Lista) {
	cout<<"----------"<<endl;
	for(size_t i=0;i<Lista.size();++i){
		cout<<"["<<i<<"]= "<<Lista[i]<<endl;
	}
	cout<<"----------"<<endl;
}

vector<int> Mayores_al_promedio(vector<int> Lista) {
	int suma=0;
	for(size_t i=0;i<Lista.size();++i){
		suma += Lista[i];
	}
	int Promedio = trunc(suma/Lista.size());
	int May = 0;
	for(size_t i=0;i<Lista.size();++i){
		if(Lista[i]>Promedio)May++;
	}
	Lista.resize(Lista.size()+1);
	for(size_t i = Lista.size()-1; 0<i ; --i){
		Lista[i] = Lista[i-1];
	}
	Lista[0] = May;
	return Lista;
}

int main() {
	vector<int>Lista;
	cout<<"Ingrese valor(Terminar con -1): ";
	int nuevo_valor;
	cin>>nuevo_valor;
	while(nuevo_valor != -1){
		Lista.push_back(nuevo_valor);
		cout<<"Ingrese valor: ";
		cin>>nuevo_valor;
	}
	cout<<endl<<"Lista original"<<endl;
	Mostrar(Lista);
	Lista = Mayores_al_promedio(Lista);
	cout<<"Lista modificada"<<endl;
	Mostrar(Lista);
	return 0;
}

