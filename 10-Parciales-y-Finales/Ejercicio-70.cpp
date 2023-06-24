/*
Ej. 2 (35pts) En una localidad se realizan elecciones municipales. Se presentan 7 partidos políticos y existen 18
barrios en el municipio. Escriba un programa en C++ que lea inicialmente los nombres de cada candidato y el
código de partido (1..7) al que pertenece. Luego debe leer los datos que llegan de cada una de las 145 mesas
electorales. Se ingresan 9 datos por mesa: cod. barrio, cant. votos blanco, cant. votos partido 1, cant. votos
partido 2, ..., cant. votos partido 7. a) Escriba una función que permita obtener el código del partido ganador y el
% de votos obtenido sobre el total. b) Informe el nombre del próximo intendente. c) Muestre el % de votos
obtenido por cada candidato. d) Escriba una función que devuelva el cod. del barrio que obtuvo mayor cantidad
de votos en blanco.
*/
#include <iostream>
#include <iomanip>
#include "lib/matrix.h"
#include <vector>
#include <cmath>
#include <tuple>

using namespace std;

tuple<int,int,int> Partido_Ganador(matrix<int> &Escrutinio) {
	Escrutinio.resize(Escrutinio.size(0)+1,Escrutinio.size(1),0);
	int totalvotos=0;
	for(size_t j=0; j<Escrutinio.size(1);++j){
		int sum=0;
		for(size_t i=0;i<Escrutinio.size(0);++i){
			sum += Escrutinio[i][j];
		}
		Escrutinio[Escrutinio.size(0)-1][j] = sum;
		totalvotos += sum;
	}
	int may=0,posmay;
	for(size_t j=0;j<Escrutinio.size(1);++j){
		if(Escrutinio[Escrutinio.size(0)-1][j]>may){
			may = Escrutinio[Escrutinio.size(0)-1][j];
			posmay=j;
		}
	}
	int PartidoGan = posmay+1;
	float porcentaje=may*100/totalvotos;
	return make_tuple(PartidoGan,porcentaje,totalvotos);
}

void Porcentajes_candidatos(matrix<int> Escrutinio,vector<string>Candidatos,int totalvotos) {
	cout<<endl<<"---------RESUMEN DE VOTOS---------"<<endl;
	for(size_t j=0;j<Candidatos.size();++j){
		cout<<endl<<"Candidato: "<<Candidatos[j]<<" | Porcentaje de votos: "<<Escrutinio[Escrutinio.size(0)-1][j]*100/totalvotos<<"%";
	}
	cout<<endl<<"----------------------------------"<<endl;
}

int Mas_votos_blanco(matrix<int> Escrutinio) {
	int MasEnBlanco = 0,barrio=0;
	for(size_t i=0;i<Escrutinio.size(0)-1;++i){
		if(Escrutinio[i][Escrutinio.size(1)-1]>MasEnBlanco){
			MasEnBlanco=Escrutinio[i][Escrutinio.size(1)-1];
			barrio = i;
		}
	}
	return barrio;
}

int main() {
	vector<string>Candidatos(7);
	int CodPart;
	string Nom;
	for(size_t i=0;i<Candidatos.size();i++){
		cout<<"Nombre del candidato: ";
		cin>>Nom;
		cout<<"Numero de partido (1-7): ";
		cin>>CodPart;
		Candidatos[CodPart-1]=Nom;
	}
	matrix<int>Escrutinio(18,8,0);
	int barrio,votos;
	for(int i=1;i<=145;i++){
		cout<<"\tMESA "<<i<<endl;
		cout<<"Barrio(1-18): ";
		cin>>barrio;
		int k=0;
		for(size_t j=0;j<Escrutinio.size(1)-1;++j){
			cout<<"Votos al partido "<<j+1<<": ";
			cin>>votos;
			Escrutinio[barrio-1][j] += votos;
			k++;
		}
		cout<<"Votos en blanco: ";
		cin>>Escrutinio[barrio-1][k];
	}
	int PartidoGan;
	float Porcentaje,totalvotos;
	tie(PartidoGan,Porcentaje,totalvotos)=Partido_Ganador(Escrutinio);
	cout<<endl<<"Partido Ganador: "<<PartidoGan<<endl;
	cout<<"Porcentaje: "<<Porcentaje<<"%"<<endl;
	cout<<endl<<"Nombre del nuevo intendente: "<<Candidatos[PartidoGan-1]<<endl;
	Porcentajes_candidatos(Escrutinio,Candidatos,totalvotos);
	int MasEnBlanco = Mas_votos_blanco(Escrutinio);
	cout<<endl<<"Barrio con mas votos en blanco: "<<MasEnBlanco+1<<endl;
	return 0;
}
