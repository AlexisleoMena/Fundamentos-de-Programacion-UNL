/*
Ej 3) (35pts) Un cooperadora de un escuela primaria recibe aportes voluntarios y de montos
variables de sus alumnos. La escuela tiene 7 cursos (años) y desea hacer un análisis de los
aportes por curso (por año) y por cada uno de los meses del año pasado. Para ello se leen los datos de cada aporte que hace un alumno: Curso, Mes, Monto: donde curso es un número de 1 a
7, mes es un número de 1 a 12 y monto es el valor monetario del aporte; estos datos terminan con
curso 0. Considere que en un mismo mes se hacen varios aportes de un mismo curso. Se desea:
a) Informar el total aportado por cada curso en cada mes del año; b) el total aportado en Junio en
toda la escuela; c) El monto aportado por todo 6to año (6to curso) en Marzo.
*/

#include <iostream>
#include "lib/matrix.h"

using namespace std;

void Mostrar_aportes(const matrix<int> &m){
	for(size_t i=0; i<m.size(0); ++i){
		cout<<"\nCurso "<<i+1<<endl;
		for(size_t j=0; j<m.size(1); ++j){
			cout<<"Aportes del mes "<<j+1<<": $"<<m[i][j]<<endl;
		}
	}
}

int Aportes_mensuales(matrix<int> cooperadora, int mes) {
	int aportes = 0;
	for(size_t i=0; i<cooperadora.size(0); ++i){
		aportes += cooperadora[i][mes]; 
	}
	return aportes;
}
	
int main() {
	matrix<int>cooperadora(7,12,0);
	int curso, mes, monto;
	cout<<"Curso (1-7, concluir con 0): ";cin>>curso;
	while(curso != 0){
		cout<<"Mes (1-12): ";cin>>mes;
		cout<<"Monto: ";cin>>monto;
		cooperadora[curso-1][mes-1] += monto; 
		cout<<"Curso(1-7): ";cin>>curso;
	}
	Mostrar_aportes(cooperadora);
	cout<<"Total de aportes en el mes de junio: "<<Aportes_mensuales(cooperadora, 5);
	cout<<"Monto aportado por 6to a�o en Marzo: "<<cooperadora[5][2];
	return 0;
}

