/*
Ejercicio Libres (20 pts) Escriba una función que reciba un arreglo v de enteros ordenados de mayor a menor, y
un entero adicional x. La función debe insertar el elemento x en el arreglo v, solamente si el elemento no estaba
en el mismo (si ya estaba no debe hacer nada), y en la posición adecuada para que el arreglo se mantenga
ordenado de mayor a menor luego de la inserción. La función debe retornar un bool indicando si realizó o no la
inserción.
*/

#include <iostream>
#include <vector>

using namespace std;

bool ValorRepetido(vector<int> v, int valor){
	for(size_t i=0;i<v.size();i++){
		if(v[i]==valor){
			return true;
		}
	}
	return false;
}
vector<int> ModificarSi(vector<int> &v,int valor){
	if(ValorRepetido(v,valor)){
		return v;
	}else{
		unsigned p = 0;
		while(valor<v[p])++p;
		v.resize(v.size()+1);
		for(size_t i=v.size()-1;i>p;--i){
			v[i]=v[i-1];
		}
		v[p] = valor;
	}
	return v;
}
void Mostrar(vector<int>v){
	cout<<"-------LISTA-------"<<endl;
	for(size_t i=0;i<v.size();i++){
		cout<<"["<<i<<"] = "<<v[i]<<endl;
	}
	cout<<"-------------------"<<endl;
}
int main() {
	cout<<"Tamaño del vector: ";
	int n;
	cin>>n;
	vector<int> Enteros(n);
	int x;
	for(size_t i=0;i<Enteros.size();i++){
		cout<<"["<<i<<"] = ";
		cin>>x;
		Enteros[i]=x;
	}
	cout<<"Agregar valor: ";
	int valor;
	cin>>valor;
	if(ValorRepetido(Enteros,valor)){
		cout<<"No se pudo realizar la operacion (valor repetido)."<<endl;
	}else{
		cout<<"Operacion realizada con Exito!"<<endl;
	}
	Enteros = ModificarSi(Enteros,valor); 
	Mostrar(Enteros);
	return 0;
}

