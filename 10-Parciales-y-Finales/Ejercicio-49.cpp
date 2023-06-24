/*
Ejercicio 1 (25 pts). Se ingresan 200 valores numéricos provenientes de un sensor de presión. Debido a fallas de
comunicación, se ingresaron algunos valores negativos. Realice un programa que reemplace todos los valores
negativos por en promedio entre el máximo y mínimo valor lista (tenga en cuenta de no considerar los valores
negativos en la obtención del menor). Muestre el arreglo modificado y informe cuántos reemplazos hizo.
*/
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

void Mostrar(vector<int> Enteros) {
	cout<<"--------LISTA---------"<<endl;
	for(size_t i=0;i<Enteros.size();i++){
		cout<<"["<<i<<"] = "<<Enteros[i]<<endl;
	}
	cout<<"----------------------"<<endl;
}

int main() {
	cout<<"Tamaño: ";
	int n;
	cin>>n;
	vector<int> Enteros(n);
	int x;
	for(size_t i=0;i<Enteros.size();i++){
		cout<<"["<<i<<"] = ";
		cin>>x;
		Enteros[i]=x;
	}
	int mayor = 0,menor = 9999;
	for(size_t i=0;i<Enteros.size();i++){
		if(Enteros[i]>mayor){
			mayor = Enteros[i];
		}
		if(Enteros[i]>=0 and Enteros[i]<menor){
			menor = Enteros[i];
		}
	}
	int Media = trunc((mayor-menor)/2);
	int reemp=0;
	for(size_t i=0;i<Enteros.size();i++){
		if(Enteros[i]<0){
			Enteros[i] = Media;
			reemp = reemp+1;
		}
	}
	Mostrar(Enteros);
	cout<<"Cantidad de reemplazos: "<<reemp;
	return 0;
}

