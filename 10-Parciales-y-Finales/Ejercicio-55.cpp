/*
Ejercicio 3 (20 pts). Se ingresan como datos 100 nombres de personas que están ordenados alfabéticamente.
Realice un algoritmo que lea un nuevo nombre y lo inserte en la lista de tal manera que el orden se mantenga.
Luego muestre la nueva lista resultante.
*/

#include <iostream>
#include <vector>

using namespace std;

void Mostrar(vector<string>Lista){
	cout<<"--------Lista--------"<<endl;
	for(size_t i=0;i<Lista.size();++i){
		cout<<Lista[i]<<endl;
	}
	cout<<"---------------------"<<endl;
}

vector<string> Modificar(vector<string> Lista, string add) {
	unsigned pos = 0;
	while(pos<Lista.size() and Lista[pos]<add) ++pos;
	Lista.resize(Lista.size()+1);
	for(size_t i=Lista.size()-1 ; pos<i ;--i){
		Lista[i] = Lista[i-1];
	}
	Lista[pos] = add;
	return Lista;
}

int main() {
	cout<<"Cantidad de nombres: ";
	int N;
	cin>>N;
	vector<string> Lista(N);
	cout<<endl<<"Ingrese los "<<N<<" nombres: "<<endl;
	for(size_t i=0;i<Lista.size();++i){
		cin>>Lista[i];
	}
	string add;
	cout<<endl<<"Añadir nombre: ";
	cin>>add;
	Lista = Modificar(Lista,add);
	Mostrar(Lista);
	return 0;
}

