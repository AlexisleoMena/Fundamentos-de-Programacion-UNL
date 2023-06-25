/*
Ejercicio 1(30 pts) Considere struct covid19{ int infectados, muertes;}, con 2 miembros para almacenar numero de infectados y numero
de muertos por COVID19. Escriba una programa C++ que ingrese los datos diarios de 15 paises (365 registros por pais); cada registro diario
consta de  5 numeros enteros: dia, mes, codigo pais, numero infectados, numero de muertes. El programa debe organizar una matriz de 15 filas 
(paises) por 12 columnas (meses de 2020) cuyos elementos sean de tipo struct covid19. Cada elemento de la matriz debe contener el total 
de infectados y el total de muertes de cada mes y de cada pais. 
a) Informe cuantos paises tuvieron % de mortalidad (100*cant. muertes/cantidad contagios) superior al 3% en octubre 2020.
b) Calcule e informe el total de muertes de todo 2020 para el pais 11.
*/

#include <iostream>
#include "lib/matrix.h"
using namespace std;
struct covid19{
	int infectados=0, muertes=0;
};
int main() {
	matrix<covid19>m(15,12);
	int dia, mes, CodPais, num_infectados, num_muertes;
	int registros = 0;
	while(registros<365*15){
		cout<<"Pais [1-15]: "; cin>>CodPais;
		cout<<"dia: ";cin>>dia;
		cout<<"mes[1-12]: ";cin>>mes;
		cout<<"Cantidad infectados: ";cin>>num_infectados;
		cout<<"Cantidad muertes: ";cin>>num_muertes;
		m[CodPais-1][mes-1].infectados += num_infectados;
		m[CodPais-1][mes-1].muertes += num_muertes;
		registros++;
	}
	cout<<"\npaises con porcentaje de mortalidad superior al 3% en octubre: \n";
	for(size_t i=0; i<m.size(0); ++i){
		if((100*m[i][9].muertes/m[i][9].infectados) > 3)
			cout<<"Pais "<<i+1<<endl;
	}
	cout<<"Cantidad de muertes en 2020 del pais 11: ";
	int sumar = 0;
	for(size_t j=0; j<m.size(1); ++j)
		sumar += m[10][j].muertes;
	cout<<sumar;
	
	return 0;
}

