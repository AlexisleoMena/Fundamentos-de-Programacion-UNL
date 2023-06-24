/*
Ejercicio 3 (20 pts). Se ingresan como datos N valores numéricos ordenados en forma descendente (el valor de
N se lee por teclado). Realice un algoritmo que lea un nuevo valor y lo inserte en la lista de tal manera que el
orden se mantenga. Luego muestre la nueva lista resultante.
*/

#include <iostream>
#include <vector>

using namespace std;

void Mostrar(vector<int>V){
	cout<<"--------LISTA--------"<<endl;
	for(size_t i=0;i<V.size();++i){
		cout<<"["<<i<<"] = "<<V[i]<<endl;
	}
	cout<<"---------------------"<<endl;
}

vector<int>Modificar(int add,vector<int>&V){
	unsigned pos = 0;
	while(pos<V.size() and V[pos]>add){
		++pos;
	}
	V.resize(V.size()+1);
	if(pos == V.size()){
		V[pos] = add;
		return V;
	}else{
		for(size_t i=V.size()-1;i>pos;--i){
			V[i] = V[i-1];
		}
		V[pos] = add;
	}
	return V;
}

int main() {
	cout<<"Cantidad de valores: ";
	int N;
	cin>>N;
	vector<int>V(N);
	int valor;
	cout<<"Inserte valores de manera descendente"<<endl;
	for(size_t i=0;i<V.size();++i){
		cout<<"["<<i<<"] = ";
		cin>>valor;
		V[i] = valor;
	}
	Mostrar(V);
	int add;
	cout<<"Insetar nuevo valor: ";cin>>add;
	Modificar(add,V);
	Mostrar(V);
	return 0;
}
