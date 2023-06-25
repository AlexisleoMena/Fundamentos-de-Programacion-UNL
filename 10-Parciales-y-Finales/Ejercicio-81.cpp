/*
Ejercicio Libre [20 pts] Escriba una función “buscar” recursiva para buscar un elemento en un vector desde una
posición que se recibe como argumento. Por ejemplo, si v es un vector de strings y se invoca como
buscar(v,5,”hola”), la función debe buscar un elemento del vector igual a “hola” desde la posición 5 hasta el
final del mismo. La función debe retornar la posición en donde se encuentra el elemento, o -1 en caso de que el
elemento no se encuentre.
*/
#include <iostream>
#include <vector>
using namespace std;
int buscar(vector<string> v, unsigned int n, string palabra){
	if(n == v.size()){
		return -1;
	}else{
		if(palabra == v[n]){
			return n;
		}else{
			return buscar(v,n+1,palabra);
		}
	}
}
int main() {
	vector<string> v = {"hoy", "no", "tengo", "ni", "un","que","decir","hola","igual"};
	cout<<buscar(v,5,"hola");
	return 0;
}

