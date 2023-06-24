/*
Ejercicio 2 (35 pts). Una empresa que comercializa jugos en caja, tiene 15 vendedores quienes que levantan
pedidos de clientes durante el mes de junio (30 días). Por cada pedido, se ingresan sin orden alguno las ternas
correspondientes al código del vendedor (1 a 15), el dia (1...30) y la cantidad de cajas de jugo encargadas,
pudiendo haber más de un pedido diario del mismo vendedor. Los datos finalizan con el código de vendedor
igual a 0. Luego, se desea obtener e informar:
 a) ¿Cuál es el código de vendedor que más pedidos hizo para el día 10?
 b) ¿Cuál es la cantidad vendida por día considerando todos los vendedores?
 c) ¿Cuántas cajas vendió en total el vendedor 10?
*/

#include <iostream>
#include "lib/matrix.h"

using namespace std;

int main() {
	cout<<"\tPEDIDOS DEL MES DE JUNIO"<<endl;
	matrix<int> Empresa(16,31,0);
	cout<<"Codigo de vendedor(Terminar con 0): ";
	int CV;
	cin>>CV;
	int Dia,Pedidos;
	while(CV != 0){
		cout<<"Día: ";
		cin>>Dia;
		cout<<"Pedidos: ";
		cin>>Pedidos;
		Empresa[CV-1][Dia-1] += Pedidos; 
		cout<<"Codigo de vendedor: ";
		cin>>CV;
	}
	int pos = Empresa[0][9];
	int CodGan = 0;
	for(int i = 0;i<15;++i){
		if(Empresa[i][9]>pos){
			pos = Empresa[i][9];
			CodGan = i;
		}
	}
	cout<<"Codigo del vendedor que mas pedidos hizo el día 10: "<<CodGan+1<<endl;
	int suma;
	for(int j=0;j<30;++j){
		suma = 0;
		for(int i=0;i<15;++i){
			suma += Empresa[i][j];
		}
		Empresa[15][j] = suma;
	}
	cout<<"Pedidos totales por día "<<endl;
	for(int j=0;j<30;++j){
		cout<<"Día "<<j+1<<": "<<Empresa[15][j]<<endl;
	}
	int acum = 0;
	for(int j=0;j<30;++j){
		acum += Empresa[9][j];
	}
	cout<<"Cantidad de pedidos de junio del vendedor 10: "<<acum;
	return 0;
}

