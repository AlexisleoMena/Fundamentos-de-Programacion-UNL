/*
Ejercicio 3 (30 pts) Una empresa exportadora posee filiales en 10 países y desea llevar el control
de ventas durante el año ya transcurrido. Escriba un programa C++ que permita ingresar en forma
desordenada mediante ternas: cod. filial(1..10), mes (1..12), monto facturado por exportación.
Pueden ingresarse más de un monto por filial en un determinado mes y la carga de datos finaliza
cuando se ingresa la filial -1. Cargue estos datos por teclado y luego:
a) Muestre el total exportado en el 1er trimestre del año para una filial que se ingresa por teclado.
b) Indique la filial que menos ventas por exportaciones hizo en el segundo semestre (sumando los
6 meses). 
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include "lib/matrix.h"
using namespace std;

int exportacion_primer_trimestre(const matrix<int> &m, int filial) {
	int expo = 0;
	for(size_t j=0; j<m.size(1)-8; ++j){
		expo += m[filial-1][j];
	}
	return expo;
}
int menor_exportacion_segundo_cuatrimestre(const matrix<int>&m){
	vector<int> v;
	for(size_t i=0; i<m.size(0); ++i){
		int suma = 0;
		for(size_t j=0; j<m.size(0)-6; ++j){
			suma += m[i][j];
		}
		v.push_back(suma);
	}
	auto it = min_element(v.begin(),v.end());
	return distance(v.begin(),it);
}
int main() {
	matrix<int> m(10,12,0);
	cout<<"Codigo filial(1-10): "; int filial; cin>>filial;
	while(filial != -1){
		cout<<"Mes (1-12): "; int mes; cin>>mes;
		cout<<"Monto facturado: "; int monto; cin>>monto;
		m[filial-1][mes-1] += monto;
		cout<<"Codigo filial(1-10): "; cin>>filial;
	}
	cout<<"Exportacion del primer trimestre del año de la filial: "; cin>>filial;
	cout<<"Monto $"<<exportacion_primer_trimestre(m,filial);
	
	return 0;
}

