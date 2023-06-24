/*
Ej 1) (30 pts) La asignatura Inglés de una carrera universitaria tiene 6 comisiones (1..6) de 30
alumnos (1..30) cada una y ha realizado una evaluación parcial. Escriba un algoritmo que permita
ingresar los resultados de la evaluación en ternas: codComision, codAlumno, nota. Estos datos
llegan sin orden alguno y terminan con codComision cero, pues no todos los estudiantes
asistieron al parcial. El algoritmo debe obtener e informar: a) El promedio de cada comisión,
promComision (debe considerar solo los asistentes para el promedio); b) cuántos alumnos
(cantAprobados) de cada comisión aprobaron la evaluación (nota >=60), c) el % de asistencia de
cada comisión (porAsistencia)
*/
#include <iostream>
#include "lib/matrix.h"
using namespace std;
int Promedio_Por_Comision(const matrix<int> &m, int i){
	int total = 0;
	int presentes = 0;
	for(size_t j=0; j<m.size(1); ++j){
		if(m[i][j] != -1){
			presentes++;
			total += m[i][j];
		}
	}
	int promedio = total/presentes;
	return promedio;
}
int Cantidad_Aprobados(const matrix<int> &m, int i){
	int aprobados = 0;
	for(size_t j=0; j<m.size(1); ++j){
		if(m[i][j] >= 60){
			aprobados++;
		}
	}
	return aprobados;
}
float Porcentaje_Asistencia(const matrix<int> &m, int i){
	int asistencias = 0;
	int total = m.size(0);
	for(size_t j=0; j<m.size(1); ++j){
		if(m[i][j] != -1){
			asistencias++;
		}
	}
	float porcentaje = asistencias*100.0f/total;
	return porcentaje;
	
}
int main() {
	matrix<int> ingles(6,30,-1);
	int CodComision, CodAlumno, nota;
	cout<<"Comision (1-6, terminar con cero): "; cin>>CodComision;
	while(CodComision != 0){
		cout<<"Alumno(1-30): "; cin>>CodAlumno;
		cout<<"Nota: "; cin>>nota;
		ingles[CodComision-1][CodAlumno-1] = nota;
		cout<<"Comision (1-6): "; cin>>CodComision;
	}
	for(int i=0; i<6; ++i){
		cout<<"\nComision "<<i+1<<endl
			<<"Promedio: "<<Promedio_Por_Comision(ingles, i)<<endl
			<<"Cantidad de aprobados: "<<Cantidad_Aprobados(ingles, i)<<endl
			<<"Porcentaje de asistencia: "<<Porcentaje_Asistencia(ingles,i)<<endl;
	}
	
	return 0;
}

