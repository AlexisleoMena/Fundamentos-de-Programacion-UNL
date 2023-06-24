/*
Ej 1) (35 pts) Un grupo de 8 universidades nacionales (1..8) realiza un estudio de la cantidad de
los egresados de los últimos 10 años. Escriba una algoritmo que lea ternas (codUniversidad,
anio, numEgresados) correspondientes a los graduados de cada universidad en cada año.
Ejemplo: la terna (3, 2016, 37) implica que la universidad 3 en 2016 tuvo 37 egresados. Estas
ternas no se leen ordenadas. Escriba un algoritmo que lea dichas ternas y organice una matriz (denominada egresadosUniv) de 8 filas (universidades) x 10 columnas (años) que contenga el
total de egresados de cada universidad en cada año. Determinar e informar: a) en qué año se
produjo el mayor número de egresados computando las 8 universidades
(anioMayorNumEgresados); b) el número de egresados de la universidad 4 en 2014; c) cuántas
universidades tuvieron menos de 20 egresados en 2012 (cantUniv)?
*/

#include <iostream>
#include "lib/matrix.h"

using namespace std;

int Anio_con_mas_egresos(const matrix<int> &egresos){
	int anio = 0, mayor = 0;
	for(size_t i=0; i<egresos.size(0); ++i){
		mayor += egresos[i][0];
	}
	for(size_t j=1; j<egresos.size(1); ++j){
		int suma = 0;
		for(size_t i=0; i<egresos.size(0); ++i){
			suma += egresos[i][j];
		}
		if(suma > mayor){
			mayor = suma;
			anio = j;
		}
	}
	return anio+2010;
}

int Universidades_con_egresos_menores_a_x_en_anio_x(matrix<int> egresos, int anio, int limite) {
	int Menores = 0;	
	for(size_t i=0; i<egresos.size(0); ++i){
		int Cantidad_egresados = egresos[i][anio];
		if(Cantidad_egresados < limite){
			Menores++;
		}
	}
	return Menores;
}
	
int main() {
	matrix<int> egresos(8,10,0);
	int universidad, anio, cantidad;
	
	cout<<"Universidad(1-8, terminar con 0): "; cin>>universidad;
	while(universidad != 0){
		cout<<"Año (2010 - 2019): "; cin>>anio;
		cout<<"Cantidad de egresados: ";cin>>cantidad;
		egresos[universidad-1][anio-2010] += cantidad;
		cout<<"Universidad(1-8): "; cin>>universidad;
	}

	cout<<"\nMayor numero de egresados en el año: "<<Anio_con_mas_egresos(egresos)<<endl;
	cout<<"Egresados de la universidad 4 en 2014: "<<egresos[3][4]<<endl;
	cout<<"Universidades con menos de 20 egresados en 2012: "<<Universidades_con_egresos_menores_a_x_en_anio_x(egresos,2,20);
	
	return 0;
}

