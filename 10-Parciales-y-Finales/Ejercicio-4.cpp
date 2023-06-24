/*
Ej 2) (25 pts) Escriba un algoritmo que permita leer N (dato inicial) valores correspondientes a
caudales medidos (caudal) en un curso de agua durante un período. a) Debe determinar e
informar el mayor caudal (caudalMayor) de la lista. b) En caso de que ese caudal se hubiera
presentado más de una vez, informar la frecuencia de aparición (cuantas veces aparece).
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	cout<<"Cantidad de lecturas: "; int n; cin>>n;
	vector<int> lecturas(n);
	for(size_t i=0; i<lecturas.size(); ++i){
		cout<<"Lectura "<<i+1<<": ";
		cin>>lecturas[i];
	}
	auto it = max_element(lecturas.begin(),lecturas.end());
	int frecuencia = count(lecturas.begin(), lecturas.end(), *it);
	cout<<"\nMayor caudal: "<<*it<<"\nFrecuencia: "<<frecuencia;
	return 0;
}
