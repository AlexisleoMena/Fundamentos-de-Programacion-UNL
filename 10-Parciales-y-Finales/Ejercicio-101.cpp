/*
Ej Libres (1 pts): Escriba una funcion que reciba un arreglo v de enteros ordenados de menor a mayor, y un entero adicional x. 
La funcion debe insertar el elemento x en el arreglo v, solamente si el elemento no estaba en el mismo (si ya estaba no debe hacer nada),
y en la posicion adecuada para que el arreglo se mantenga ordenado de menor a mayor luego de la insercion. La funcion debe retornar un 
valor logico indicando si realizo o no la insercion.
*/

#include <iostream>
#include <vector>

using namespace std;

bool Repite(const vector<int> &V, int x) {
	for(int i:V)
		if(i == x)
		return true;
	return false;
}

bool insertar_ordenado_Menor_Mayor(vector<int> &V, int x) {
	if(!Repite(V,x)){
		unsigned pos=0;
		while(pos != V.size() and V[pos]<x) ++pos;
		V.resize(V.size()+1);
		for(size_t i = V.size()-1; pos<i; --i)
			V[i] = V[i-1];
		V[pos] = x;
		return true;
	}
	return false;
}

int main() {
	vector<int> V = {1,2,3,4,5,6,7,9};
	if(insertar_ordenado_Menor_Mayor(V,8)){
		cout<<"Insertado con exito! \nV = ";
		for(int i:V)
			cout<<i<<" ";
	}
	return 0;
}

