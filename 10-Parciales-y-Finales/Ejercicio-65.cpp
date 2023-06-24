/*
Ejercicio 1 [25 pts] Escriba un programa que permita ingresar al usuario 30 valores numéricos que deberán
almacenarse en un arreglo. Escriba una función que encuentre y devuelva los 2 valores mayores del arreglo y
utilice dicha función desde el programa principal.
*/

#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

tuple<int,int> Buscar_mayores(vector<int> Lista) {
	int may = Lista[0], seg = Lista[1];
	if(seg>may)swap(may,seg);
	for(size_t i=2;i<Lista.size();++i){
		if(Lista[i]>may){
			seg = may;
			may = Lista[i];
		}else{
			if(Lista[i]>seg){
				seg=Lista[i];
			}
		}
	}
	return make_tuple(may,seg);
}

int main() {
	cout<<"Cantidad de valores a ingresar: ";
	int N;
	cin>>N;
	vector<int>Lista(N);
	cout<<"Igrese: "<<endl;
	for(size_t i=0;i<Lista.size();++i){
		cout<<"["<<i<<"] = ";
		cin>>Lista[i];
	}
	int may,seg;
	tie(may,seg)=Buscar_mayores(Lista);
	cout<<"Los mayores son "<<may<<" y "<<seg;
	return 0;
}

