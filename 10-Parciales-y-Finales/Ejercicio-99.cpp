/*
Ejercicio 2 (35 pts) En una region agricola se ubican N parcelas (campos) pequeñas codificadas de 1 a N. N es dato inicial. 
En cada parcela se han registrado en un periodo de varios meses mediciones diarias de humedad del suelo (valores de humedad:  0% a 100%). 
Escriba un programa C++ que lea los N datos de humedad del dia1, luego los N datos de humedad del daa 2, y así sucesivamente. 
Estos datos terminan con humedad -1. Luego, determine e informe:
a) La humedad promedio diaria del suelo de cada parcela. Crear una funcion.
b) Cual es la mayor diferencia de promedio de  humedad registrada en el periodo (diferencia entre la mayor humedad media y la menor).
 Crear una funcion.
c) cuantas veces en la parcela 9 se midia una humedad superior a  40% por mes de 15 dias seguidos.
*/

#include <iostream>
#include "lib/matrix.h"
using namespace std;
struct empleado{
	string apellido, nombre;
	int nota;
};
int Porcentaje_de_aprobados(const matrix<empleado> &m){
	int Cantidad_Aprob = 0;
	for(size_t i=0; i<m.size(0); ++i){
		int Materias_Aprob = 0; 
		for(size_t j=0; j<m.size(1); ++j){
			if(m[i][j].nota >=6){
				Materias_Aprob++;
			}
		}
		if(Materias_Aprob >= 4){
			Cantidad_Aprob++;
		}
	}
	int porcentaje = Cantidad_Aprob*100/m.size(0);
	return porcentaje;
}
int Promedio_de_aprobados_del_test_x(const matrix<empleado> &m, int test) {
	int suma = 0, Cantidad_Aprob = 0;
	for(size_t i=0; i<m.size(0); ++i){
		if(m[i][test].nota >= 6){
			suma += m[i][test].nota;
			Cantidad_Aprob++;
		}
	}
	int promedio = suma*100/Cantidad_Aprob;
	return promedio;
}
void No_Aprobaron_el_curso(const matrix<empleado> &m) {
	cout<<"\nLista de no aprobados: \n";
	for(size_t i = 0; i<m.size(0);++i){
		int materias_Aprob = 0;
		for(size_t j=0; j<m.size(1); ++j){
			if(m[i][j].nota >= 6){
				materias_Aprob++;
			}
		}
		if(materias_Aprob<4){
			cout<<m[i][0].nombre<<" "<<m[i][0].apellido<<endl;
		}
	}
}

int main() {
	matrix<empleado> empresa(52,7);
	int CodEmpleado, test, nota;
	string nomb, ape;
	cout<<"Codigo de empleado (1-52 , terminar con 0): "; cin>>CodEmpleado;
	while(CodEmpleado != 0){
		cout<<"Numero de test (1-7): "; cin>>test;
		cout<<"Nombre: "; cin>>nomb;
		cout<<"Apelido: "; cin>>ape;
		cout<<"Nota: "; cin>>nota;
		if(nota < 6){
			cout<<"Nota del recuperatorio :"; cin>>nota;
		}
		empresa[CodEmpleado-1][test-1].nombre = nomb;
		empresa[CodEmpleado-1][test-1].apellido = ape;
		empresa[CodEmpleado-1][test-1].nota = nota;
		cout<<"\nCodigo de empleado (1-52): "; cin>>CodEmpleado;
	}
	cout<<"Porcentaje de aprobados: "<<Porcentaje_de_aprobados(empresa)<<endl;
	cout<<"Promedio de las notas de los que aprobaron la evaluacion numero 3: "<<Promedio_de_aprobados_del_test_x(empresa, 2);
	No_Aprobaron_el_curso(empresa);
	return 0;
}

