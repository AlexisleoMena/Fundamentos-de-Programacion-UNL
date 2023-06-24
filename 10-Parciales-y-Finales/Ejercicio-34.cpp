/*
Ejercicio 1 (25 pts) En una carrera de ciclismo por etapas, el ganador es el competidor que acumula menor
cantidad de tiempo sumando sus tiempos de todas las etapas. Escriba un programa que permita ingresar la
cantidad de competidores de una carrera de tres etapas y a continuación, por cada competidor, ingresar primero
nombre y apellido, y luego los tres tiempos (uno por cada etapa). Cada tiempo se ingresa mediante dos enteros,
que corresponden a minutos y segundos. El programa debe mostrar el nombre del ganador y su tiempo total en
minutos y segundos. Advertencia: 40m 40s + 50m 50s no es 90m 90s, sino 91m 30s.
*/
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct 	corredor{
	string nombre;
	string apellido;
	int tiempos;
};

int main() {
	cout<<"Numero de competidores: ";
	int n;
	cin>>n;
	vector<corredor>Participantes(n);
	int min,seg,total;
	for(size_t i=0;i<Participantes.size();i++){
		cout<<"----------------------"<<endl;
		cout<<"Nombre: ";
		cin>>Participantes[i].nombre;
		cout<<"Apellido: ";
		cin>>Participantes[i].apellido;
		min=0;seg=0; total=0;
		for(int j=1;j<=3;j++){
			cout<<"TIEMPO EN LA ETAPA "<<j<<endl;
			cout<<"Minutos: ";cin>>min;
			cout<<"Segundos: ";cin>>seg;
			total += ((min*60)+seg);
		}
		Participantes[i].tiempos = total;
		cout<<"----------------------"<<endl;
	}
	int Ganador = 9999999;
	int pos=0;
	for(size_t i=0;i<Participantes.size();i++){
		if(Participantes[i].tiempos<Ganador){
			Ganador = Participantes[i].tiempos;
			pos=i;
		}
	}
	int minutos = trunc(Ganador/60);
	int segundos = (Ganador-(minutos*60));
	cout<<"GANADOR: "<<Participantes[pos].nombre<<" "<<Participantes[pos].apellido<<" | Tiempo: "<<minutos<<"m "<<segundos<<"s";
	return 0;
}
