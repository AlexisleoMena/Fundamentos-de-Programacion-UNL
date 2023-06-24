/*
Ejercicio 2 (30 pts) Un struct definido como struct Evento { string tipo; int jugador; }; representa un evento
ocurrido en un partido de tenis. tipo puede ser “ace”, “error no forzado”, “tiro ganador”, “doble falta”, y
”quiebre”. jugador puede ser 1 o 2. a) Escriba una función llamada resumen_partido que reciba un
arreglo/vector de structs de tipo Evento y un número de jugador, y retorne la cantidad de eventos de cada tipo
para ese jugador. b) Escriba un programa cliente que permita ingresar todos los eventos de un partido durante el
mismo (sin conocer previamente la cantidad de eventos), y luego muestre en pantalla el resumen de cada
jugador.
*/

#include <iostream>
#include <vector>

using namespace std;

void Lista(){
	cout<<"\tTIPOS DE EVENTOS"<<endl;
	cout<<"- ace"<<endl;
	cout<<"- error_no_forzado"<<endl;
	cout<<"- tiro_ganador"<<endl;
	cout<<"- doble_falta"<<endl;
	cout<<"- quiebre"<<endl;
}

struct Evento{
	int jugador;
	string tipo;
};

vector<int> resumen_partido(vector<Evento>v,int n){
	Evento c;
	vector<int> resumen(5,0);
	for(size_t i=0;i<v.size();++i){
		if(v[i].jugador==n){
			if(v[i].tipo == "ace") resumen[0] += 1;
			if(v[i].tipo == "error_no_forzado") resumen[1] += 1;
			if(v[i].tipo == "tiro_ganador") resumen[2] += 1;
			if(v[i].tipo == "doble_falta") resumen[3] += 1;
			if(v[i].tipo == "quiebre") resumen[4] += 1;
		}
	}
return resumen;
}

void Detalles(vector<int>v, int n){
	cout<<endl<<"--------------------------------"<<endl;
	cout<<"\tJUGADOR "<<n<<endl;
	cout<<"Aces: "<<v[0]<<endl;
	cout<<"Errores no forzados: "<<v[1]<<endl;
	cout<<"Tiros ganadores: "<<v[2]<<endl;
	cout<<"Doble faltas: "<<v[3]<<endl;
	cout<<"Quiebres: "<<v[4]<<endl;
	cout<<"--------------------------------"<<endl;
}

int main() {
	Lista();
	vector<Evento> v;
	Evento c;
	cout<<"Numero de jugador (finalizar con 0): ";
	cin>>c.jugador;
	while(c.jugador!=0){
		cout<<"Tipo de evento: ";cin>>c.tipo;
		v.push_back(c);
		cout<<"Numero de jugador: ";
		cin>>c.jugador;
	}
	vector<int>jugador1 = resumen_partido(v,1);
	vector<int>jugador2 = resumen_partido(v,2);
	Detalles(jugador1,1);
	Detalles(jugador2,2);
	return 0;
}
