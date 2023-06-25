/*
Ej. 3 (20pts) a) Proponga 2 ejemplos de funciones recursivas. b) Proponga solo el prototipo de la función
min_max(..) , que reciba un arreglo de enteros como parámetros y devuelva el mayor y el menor del arreglo sin
emplear el operador &.
*/
#include <iostream>
#include <vector>

using namespace std;

int factorial(int n){
	if(n==0)
		return 1;
	else
		return n*factorial(n-1);
}
int potencia(int b, int e){
	if(e==0)
		return 1;
	else
		return b*potencia(b,e-1);
}

int Suma_Comp(vector<int> v, int n){
	if(n==0)
		return v[0];
	else
		return v[n]+Suma_Comp(v,n-1);
}
int main() {
	cout<<"4! : "<<factorial(4);
	cout<<"\n2^3 "<<potencia(20,45);
	vector<int> v={1,2,3,4,5};
	cout<<"\nSuma de componentes del vector v: "<<Suma_Comp(v,v.size());
	return 0;
}

