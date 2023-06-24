/*
Ejercicio 2 (35 pts). La ciudad asigna un monto fijo de $100.000 por cada mes, a cada una de 10 escuelas
rurales durante todo el 2017 para gastos. Mensualmente cada escuela realiza compras que se irán acumulando.
Escriba un programa que organice una tabla de 10x12 con los totales de montos que cada escuela ha tenido en
cada mes. Los datos que se ingresan por cada compra son: código de de la escuela (entre 1 y 10), dia, mes, año y
el monto, pudiendo haber más de una compra mensual para la misma escuela. Los datos finalizan con el código
de escuela igual a 0. Luego, se desea obtener e informar: a) Al finalizar el año, ¿cuánto dinero le sobró a cada
escuela? b) ¿Cuántos escuelas gastaron todo el dinero en el mes de febrero? c) ¿Cuál fue la escuela que menos
gastó en octubre?
*/

#include <iostream>
#include "lib/matrix.h"
using namespace std;

int main() {
	matrix<int>Gastos(10,13,0);
	int CE,mes, Facturas;
	cout<<"Código de escuela (1-10, concluir con 0): ";
	cin>>CE;
	while(CE!=0){
		cout<<"Mes: ";
		cin>>mes;
		cout<<"Gastos de compra: ";
		cin>>Facturas;
		Gastos[CE-1][mes-1] += Facturas;
		cout<<"Código de escuela: ";
		cin>>CE;
	}
	cout<<endl<<"Dinero sobrante del año 2017: "<<endl;
	for(int i=0;i<10;++i){
		int suma = 0;
		int sobrante = 0;
		for(int j=0;j<12;++j){
			suma += Gastos[i][j];
		}
		Gastos[i][13] = suma;
		sobrante = ((100000*12)-Gastos[i][13]);
		cout<<"Escuela "<<i+1<<": $"<<sobrante<<endl;
	}
	cout<<endl<<"Escuelas que gastaron todo el ingreso del mes de Febrero: "<<endl;
	string validar = "N";
	for(int i=0;i<10;++i){
		if(Gastos[i][1]>=100000){
			cout<<"Escuela: "<<i+1<<endl;
			validar = "S";
		}
	}
	if(validar=="N") cout<<"Ninguna"<<endl;
	int menor = 9999999;
	for(int i=0;i<10;++i){
		if(menor>Gastos[i][9]){
			menor = Gastos[i][9];
		}
	}
	int pos = 0;
	while(Gastos[pos][9] != menor) ++pos;
	cout<<endl<<"La escuela número "<<pos+1<<" realizó menos gastos en Octubre.";
	return 0;
}

