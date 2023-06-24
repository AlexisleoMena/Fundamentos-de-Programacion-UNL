/*
Ejercicio 1 (30 pts) Escriba una programa C++ que permita ingresar los montos presupuestarios
asignados mensualmente a 18 Centros barriales durante los meses de 2019. Organice una tabla o
matriz de 18 filas x 12 columnas con esos presupuestos. Luego ingrese los montos ejecutados
(gastados) por cada Centro Barrial usando ternas: Nro Centro Barrial (1..18), Nro mes (1..12),
monto gastado. Puede haber varios gastos en el mismo mes para un Centro barrial. La carga de
datos finaliza con Nro Centro Barrial igual a -1.
a) El programa debe restar del presupuesto cada monto gastado, y si un gasto excede al presupuesto
quedará el valor negativo en la celda correspondiente.
b) Escriba una función que reciba la matriz de presupuestos, y retorne cuántos centros tuvieron
meses con saldo negativo (déficits) e informe.
c) Escriba una función que reciba la matriz de presupuestos y un Nro mes, y retorne el saldo
promedio considerando todos los centros para ese mes. Utilicela para obtener y mostrar el
promedio del mes de mayo.
d) Agregue una columna (decimotercera) a la tabla con los saldos que quedaron sin ejecutar en el
año por todos los Centros.
*/

#include <iostream>
#include "lib/matrix.h"
#include <iomanip>

using namespace std;

int centros_en_deficit(const matrix<int> &m) {
	int en_deficit = 0;
	for(size_t i=0; i<m.size(0); ++i){
		for(size_t j=0; j<m.size(1); ++j){
			if(m[i][j] < 0){
				en_deficit++;
				j = m.size(1);
			}
		}
	}
	return en_deficit;
}

int saldo_promedio_segun_mes(const matrix<int> &m, int mes) {
	int total = 0;
	for(size_t i=0; i<m.size(0); ++i){
		total += m[i][mes];
	}
	int promedio = total/m.size(0);
	return promedio;
}

int main() {
	matrix<int> presupuestos(18,12,0);
	cout<<"Carga de presupuestos\n";
	for(size_t i=0; i<presupuestos.size(0); ++i){
		cout<<"Centro barrial "<<i+1<<endl;
		for(size_t j=0; j<presupuestos.size(1); ++j){
			cout<<"Presupuesto del mes "<<j+1<<" :"; cin>>presupuestos[i][j];
		}
	}
	cout<<"\nCarga de gastos mensuales\n";
	cout<<"Centro barrial (1-18, finaliza con -1): "; int m;cin>>m;
	while(m != -1){
		cout<<"Mes (1-12): "; int n; cin>>n;
		cout<<"Gasto: "; int gasto; cin>>gasto;
		presupuestos[m-1][n-1] -= gasto;
		cout<<"Centro barrial(1-18): "; cin>>m;
	}
	cout<<"Centros barriales en deficit: "<<centros_en_deficit(presupuestos)<<endl;
	cout<<"Saldo promedio del mes de marzo(mes 3): "<<saldo_promedio_segun_mes(presupuestos, 2);
	return 0;
}
