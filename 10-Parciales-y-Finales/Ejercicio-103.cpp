/*
Ejercicio 3) (34 pts)  a) Escriba una funciÓn que reciba como parAmetros un vector V de flotantes ordenado en forma decreciente  y un float f. 
La funciÓn debe insertar f  en V manteniendo el orden y devolver el vector modificado. 
b) Escriba un programa C++ que ingrese un vector A  de N elementos flotantes ordenado en forma decreciente. 
Luego lea un segundo vector B de M elementos flotantes no ordenados. 
El programa debe insertar cada elemento de B en A manteniendo el orden de menor a mayor. Muestre el vector A modificado.
*/
#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

void insertar_ordenado_Mayor_Menor(vector<float> &V, float f) {
	unsigned pos=0;
	while(pos != V.size() and V[pos]>f) ++pos;
	V.resize(V.size()+1);
	for(size_t i = V.size()-1; pos<i; --i)
		V[i] = V[i-1];
	V[pos] = f;
}

void mostrar(const vector<float> &v){
	cout<<"Vector = ";
	for(float i:v){
		cout<<i<<" ";
	}
}

vector<float> Nuevo_Vector_decreciente(vector<float> &ordenado, vector<float> &desordenado){
	for(size_t i=0; i<desordenado.size(); ++i){
		insertar_ordenado_Mayor_Menor(ordenado,desordenado[i]);
	}
	return ordenado;
}

int main() {
	vector<float> v = {9.8, 9.4, 8.3, 7.2, 6.2, 5.1, 1.2};
	insertar_ordenado_Mayor_Menor(v, 6.1f);
	mostrar(v);
	vector<float> A = v;
	cout<<"\nCantidad de elementos del vector B: "; int n; cin>>n;
	vector<float> B(n);
	for(size_t i=0; i<B.size(); ++i){
		B[i] = (rand()%50)+1.4f;
	}
	Nuevo_Vector_decreciente(A,B);
	mostrar(A);
	return 0;
}

