/*
Ejercicio 3 (25 pts)
Considere el struct ficha{ string cliente; int DNI, edad; char sexo;}. a) Escriba una función C++ que reciba un vector de
tipo ficha y coloque todos los elementos de sexo 'F' al principio del vector, los elementos de clientes masculinos (sexo es
'M') deben estar al final. La función debe retornar un valor entero indicando cuántos clientes de sexo 'F' tiene la lista. b)
Escriba un programa cliente que permita ingresar los datos de un conjunto de clientes. Se desconoce a priori la
cantidad, los datos terminan cuando se ingresa el nombre de cliente "fin”. Utilice la función y muestre la lista
reordenada.
*/

#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

struct ficha{
	string cliente;
	int DNI, edad;
	char sexo;
};

tuple<int,int> Reordenar(vector<ficha> &V){
	vector<ficha> Aux;
	int masculinos = 0, femeninos = 0;
	for(ficha x:V){
		if(x.sexo == 'F'){
			Aux.push_back(x);
			femeninos++;
		}
	}
	for(ficha x:V){
		if(x.sexo == 'M'){
			Aux.push_back(x);
			masculinos++;
		}
	}
	V = Aux;
	return make_tuple(masculinos,femeninos);
}

void Mostrar(const vector<ficha> &V){
	for(ficha x:V)
		cout<<"Nombre: "<<x.cliente<<endl;
}

int main() {
	vector<ficha> V;
	ficha x;
	cout<<"Nombre: ";cin>>x.cliente;
	while(x.cliente != "fin"){
		cout<<"DNI: "; cin>>x.DNI;
		cout<<"Edad: "; cin>>x.edad;
		cout<<"Sexo (F/M): "; cin>>x.sexo;
		V.push_back(x);
		cout<<"\nNombre: "; cin>>x.cliente;
	}
	int masculinos, femeninos;
	tie(masculinos, femeninos) = Reordenar(V);
	cout<<"Hombres: "<<masculinos<<"\nMujeres: "<<femeninos<<endl;
	Mostrar(V);
	return 0;
}

