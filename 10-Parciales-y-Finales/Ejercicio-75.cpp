/*
Ej. 3 (35pts) Se ingresan como datos en un programa C++ las producciones anuales de soja, maíz y trigo (en
miles de Tn) de 8 provincias en el decenio 2005-2014. Para ello se leen 240 gupos de datos: CodProv, Anio,
Cant y TipoCultivo; donde CodProv es un entero entre 1 y 8 correspondiente a la provincia, Anio un enero entre
2005 y 2014 y Cant la cantidad de Tn producidas y TipoCultivo es un string ("soja", "trigo" o "maíz"). a)
Determine cuáles provincias tuvieron una producción menor de trigo en 2014 respecto de 2005. b) Escriba una
función que reciba un entero correspondiente a un año y devuelva cuál fue provincia produjo más soja en dicho
año. Utilice dicha función para obtener la provincia que produjo mayor cantidad de soja en el 2008. c) Informe el
total de maíz producidos por las 8 provincias en 2013.
*/

#include <iostream>
#include "lib/matrix.h"
#include <iomanip>

using namespace std;

struct Datos{
	string TipoCultivo;
	int Cant;
};

int mas_soja(matrix<Datos> A, int n){
	n -= 2005;
	int MejorProduccion = -1;
	int Provincia;
	for(size_t j=0; j<A.size(1); j++){
		if(A[n][j].TipoCultivo == "soja" && A[n][j].Cant>MejorProduccion){
			MejorProduccion = A[n][j].Cant;
			Provincia = j;
		}
	}
	Provincia += 1;
	return Provincia;	
}

int maiz_2013(matrix<Datos> A){
	int Total = 0;
	int anio = 3;
	for(size_t j=0;j<A.size(1);j++){
		if(A[anio][j].TipoCultivo=="maiz"){
			Total += A[anio][j].Cant;
		}
	}
	return Total;
}

int main() {
	cout<<"\tPorduccion anual de soja, maiz y trigo"<<endl<<endl;
	matrix<Datos> M(10,8);
	int CodProv, Anio;
	int conteo=0;
	do{
		cout<<"Año(2005 al 2014): ";
		cin>>Anio;
		Anio -= 2005;
		cout<<"Codigo de provincia(1 al 8): ";
		cin>>CodProv;
		CodProv -= 1;
		cout<<"Tipo de cultivo: ";
		cin>>M[Anio][CodProv].TipoCultivo;
		cout<<"Cantidad de toneladas: ";
		cin>>M[Anio][CodProv].Cant;		
		conteo++;
	} while(conteo<10*8);
	for(size_t i=0;i<M.size(0);i++){
		for(size_t j=0;j<M.size(1);j++){
			cout<<M[i][j].Cant;
		}
		cout<<endl;
	}
	int Soja;
	cout<<"Mayor cantidad de soja; año: ";cin>>Soja;
	int TotalSoja;
	TotalSoja = mas_soja(M,Soja);
	cout<<"Provincia con mayor produccion de soja en 2006: "<<TotalSoja<<endl;
	cout<<"Toneladas de maiz durante el año 2005: "<<maiz_2013(M);
	return 0;
}

