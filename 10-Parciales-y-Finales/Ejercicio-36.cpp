/*
Ejercicio 3 (25 pts) Se pretende analizar el rendimiento académico de 200 egresados de una carrera cuyo plan
contiene 35 materias. Escriba un programa que permita a) ingresar 200x35 ternas de datos compuestas por
número de alumno (1 a 200), número de materia (1 a 35) y nota final (6 a 10) y muestre: b) el mejor promedio de
la carrera; c) la materia más difícil (la que tenga menor promedio de nota), y d) la nota que obtuvo el alumno del
mejor promedio para esa materia más difícil.
*/

#include <iostream>
#include "lib/matrix.h"
#include <iomanip>
using namespace std;
int main() {
	cout<<"Cantidad de egresados: ";
	int m;
	cin>>m;
	cout<<"Cantidad de materias: ";
	int n;
	cin>>n;
	matrix<int>A(m,n,0);
	int NumeroAlumno,NumeroMateria,NotaFinal;
	cout<<"N�mero de alumno(concluye con n�mero de alumno: -1) : ";
	cin>>NumeroAlumno;
	while(NumeroAlumno!=-1){
		cout<<"N�mero de materia: ";
		cin>>NumeroMateria;
		cout<<"Nota final: ";
		cin>>NotaFinal;
		A[NumeroAlumno-1][NumeroMateria-1] = NotaFinal;
		cout<<"N�mero de alumno: ";
		cin>>NumeroAlumno;
	}
	A.resize(A.size(0)+1,A.size(1)+1,0);
	for(size_t i=0;i<A.size(0)-1;++i){
		int sum=0;
		for(size_t j=0;j<A.size(1)-1;++j){
			sum += A[i][j];
		}
		A[i][A.size(1)-1]=sum;
	}
	int MejorPromedio = 0;
	int AlumnoConMejorP;
	for(size_t i=0;i<A.size(0)-1;++i){
		if(A[i][A.size(1)-1]>MejorPromedio){
			MejorPromedio = A[i][A.size(1)-1];
			AlumnoConMejorP = i+1;
		}
	}
	MejorPromedio /= n;
	cout<<"\aAlumno con mejor promedio; alumno n�mero: "<<AlumnoConMejorP<<" | Promedio: "<<MejorPromedio<<endl;
	for(size_t j=0;j<A.size(1)-1;++j){
		int sum = 0;
		for(size_t i=0; i<A.size(0)-1;++i){
			sum += A[i][j];
		}
		A[A.size(0)-1][j]=sum;
	}
	int MateriaPromedioMasBajo = 999;
	int pos = 0;
	for(size_t j=0;j<A.size(1)-1;++j){
		if(A[A.size(0)-1][j]<MateriaPromedioMasBajo){
			MateriaPromedioMasBajo = A[A.size(0)-1][j];
			pos = j+1;
		}
	}
	MateriaPromedioMasBajo /= m;
	cout<<"Materia m�s dificil; materia n�mero: "<<pos<<" | Promedio: "<<MateriaPromedioMasBajo<<endl;
	cout<<"En tal materia el alumno con mejor promedio obtuvo una nota de: "<<A[AlumnoConMejorP-1][pos-1]<<endl;
	return 0;
}

