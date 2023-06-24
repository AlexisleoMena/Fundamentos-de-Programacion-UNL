/*
Ejercicio 3 [30 pts] Se desea escribir un programa que permita gestionar puntos de venta para pasajes de
colectivos durante el año 2016. Existen 10 puntos de venta y se desea conocer la cantidad de pasajes vendidos
mensualmente. El programa debe recibir como entrada ternas desordenadas de datos: cód de punto de venta (1-
10), fecha (con formato aaaammdd) y cantidad de pasajes vendidos. Se desea conocer: a) cuántos pasajes vendió
el punto de venta 5 durante todo el año, b) cuántos pasajes se vendieron, teniendo en cuanta todos los puntos de
venta, en un determinado mes ingresado por el usuario, c) la cantidad puntos de venta no vendieron pasajes
durante el mes de octubre. Resolver al menos 1 de los 3 apartados empleando una función.
*/
#include <iostream>
#include "lib/matrix.h"
#include <iomanip>

using namespace std;

int Buscar_Venta_Mes(matrix<int> Ventas, int BuscarMes) {
	int Cant = 0;
	for(size_t j=0;j<Ventas.size(1);++j){
		Cant += Ventas[BuscarMes-1][j];
	}
	return Cant;
}

int No_vendidos_octubre(matrix<int> Ventas) {
	int Cant = 0;
	for(size_t j=0;j<Ventas.size(1);++j){
		if(Ventas[9][j]==0) Cant++;
	}
	return Cant;
}

int main() {
	cout<<"VENTA DE PASAJES DE COLECTIVO EN 10 PUNTOS DE VENTA (2016)"<<endl;
	matrix<int>Ventas(12,10,0);
	int CodPV,fecha,PasajesV;
	cout<<"Punto de venta(Terminar con -1): ";
	cin>>CodPV;
	while(CodPV!=-1){
		cout<<"fecha(aaaammdd): ";
		cin>>fecha;
		fecha = (fecha/100)%100;
		cout<<"Cantidad de pasajes vendidos: ";
		cin>>PasajesV;
		Ventas[fecha-1][CodPV-1] += PasajesV;
		cout<<"---------------"<<endl;
		cout<<"Punto de venta: ";
		cin>>CodPV;
	}
	int VentasPV5=0;
	for(size_t i=0;i<Ventas.size(0);++i){
		VentasPV5 += Ventas[i][4];
	}
	cout<<"\nCantidad de pasajes vendida en el año por el punto de venta 5: "<<VentasPV5<<endl;
	cout<<"\nCANTIDAD DE PASAJES VENDIDOS SEGUN MES"<<endl;
	cout<<"Mes: ";
	int BuscarMes;
	cin>>BuscarMes;
	int Cant = Buscar_Venta_Mes(Ventas,BuscarMes);
	cout<<"\nEn el mes "<<BuscarMes<<" se vendieron "<<Cant<<" pasajes"<<endl;
	int PasNoVendOct = No_vendidos_octubre(Ventas); 
	cout<<"\nPuntos de venta que no vendieron pasajes en octubre: "<<PasNoVendOct;
	return 0;
}

