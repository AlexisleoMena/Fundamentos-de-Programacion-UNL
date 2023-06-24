/*
Ejercicio 2 [30 pts] Se desea escribir un programa que permita gestionar una red de verdulerías. Existen 10
puntos de verdulerías diferentes y cada una comercializa 30 productos distintos y se necesita conocer la cantidad
de productos vendidos por cada verdulería. El programa debería leer inicialmente el código de cada producto y
su descripción (por ejemplo: 0, zanahorias. Luego se deberían leer ternas ordenadas con los siguientes datos:
cod. producto, cod. verdulería, cantidad de unidades vendidas. Éstos datos deben disponerse en una matriz de 10
filas por 30 columnas. Luego: a) Agregar una fila adicional con los totales vendidos de cada producto teniendo
en cuenta todas las verdulerías. b) Mostrar la descripción del producto que registró más ventas en la en la
verdulería 5. c) La cantidad de productos con código 3 que se vendieron en la verdulería con código 5.
Importante: al menos el apartado a) ó el apartado b) (queda a elección del alumno) deben resolverse
utilizando una función.
*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
	cout<<"Tamaño de la lista de productos: ";
	int N;
	cin>> N;
	vector<string>Productos(N);
	cout<<"INGRESAR LISTA DE "<<N<<" PRODUCTOS"<<endl;
	for(int i=1;i<=N;++i){
		cout<<"Nombre del producto: ";
		string Prod;
		cin>>Prod;
		cout<<"Codigo de reconocimiento (1-"<<N<<"): ";
		int CodProd;
		cin>>CodProd;
		Productos[CodProd-1] = Prod;
	}
	return 0;
}
