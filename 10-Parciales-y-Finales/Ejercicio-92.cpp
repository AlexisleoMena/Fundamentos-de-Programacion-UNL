/*
Ejercicio 2 (30 pts) En una carrera de motos se registraron los tiempos de cada una de las 27 vueltas de cada uno
de los 18 competidores, y ahora se desean analizar estos datos. Escriba un programa para: a) Permitir primero la
carga de los nombres de cada uno de los competidores (en orden), y luego, (también en orden) los tiempos de
cada competidor por cada vuelta (en segundos). b) Encontrar la mejor vuelta de toda la carrera e informar su
tiempo, qué número de vuelta fue, y el nombre del competidor que la logró (nota: la mejor es la de menor
tiempo). c) Informar el tiempo de vuelta promedio considerando los 18x27 tiempos (el promedio de todos los
tiempos). Debe utilizar funciones para los incisos b y c.
*/

#include <iostream>
#include "lib/matrix.h"
#include <vector>
#include <tuple>
#include <iomanip>

using namespace std;
tuple<int,int,int> Mejor_vuelta(matrix<int>A){
	int MasRapida = 9999999;
	int NumCompetidor = 0;
	int NumVuelta = 0;
	for(size_t j=0;j<A.size(1);j++){
		for(size_t i=0;i<A.size(0);i++){
			if(A[i][j]<MasRapida){
				MasRapida = A[i][j];
				NumCompetidor = j;
				NumVuelta = i;
			}
		}
	}
	return make_tuple(NumCompetidor,NumVuelta,MasRapida);
}

int Vuelta_Promedio(matrix<int> Tiempos) {
	int sum = 0, divisor = 0;
	for(size_t i=0;i<Tiempos.size(0);i++){
		for(size_t j=0;j<Tiempos.size(1);j++){
			sum += Tiempos[i][j];
			divisor++;
		}
	}
	int promedio = sum/divisor;
	return promedio;
}	

int main() {
	int m;
	cout<<"Numero de vueltas: ";
	cin>>m;
	int n;
	cout<<"Numero de Competidores: ";
	cin>>n;	
	vector<string> Competidores(n);
	matrix<int>Tiempos(m,n);
	string nom;
	for(size_t i=0;i<Competidores.size();i++){
		cout<<"Nombre del competidor "<<i+1<<": ";
		cin>>nom;
		Competidores[i] = nom;		
	}
	int tiempo;
	for(size_t i=0;i<Tiempos.size(0);i++){
		cout<<"\tVUELTA "<<i+1<<endl;
		for(size_t j=0;j<Tiempos.size(1);j++){
			cout<<"Tiempo de "<<Competidores[j]<<": ";
			cin>>tiempo;
			Tiempos[i][j] = tiempo;
		}
	}
	int Ganador, NumeroVuelta,MejorVuelta;
	tie(Ganador,NumeroVuelta,MejorVuelta) = Mejor_vuelta(Tiempos);
	cout<<"Mejor tiempo: "<<MejorVuelta<<"s"<<" | Vuelta Numero: "<<NumeroVuelta+1<<" | Competidor: "<<Competidores[Ganador];	
	cout<<endl<<"Tiempo de vuelta promedio: "<<Vuelta_Promedio(Tiempos)<<"s";
	return 0;
}

