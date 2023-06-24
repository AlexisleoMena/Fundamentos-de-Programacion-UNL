/*
Ej. 3. (20 ptos). Se lee en un arreglo lineal de 10 elementos nombres de personas ya ordenados alfabéticamente,
realice la lectura y programe lo siguiente: a). Permita ingresar un nombre a ser eliminado, para esto debe
desplazar los nombres pisando el nombre a eliminar. b). Inserte un nuevo nombre manteniendo el orden
alfabético del arreglo.
*/
#include <iostream>
#include <vector>

using namespace std;

void Mostrar(vector<string> Nombres){
	cout<<"-------LISTA-------"<<endl;
	for(size_t i=0;i<Nombres.size();i++){
		cout<<i+1<<". "<<Nombres[i]<<endl;
	}
	cout<<"-------------------"<<endl;
}

int main() {
	vector<string>Nombres(10);
	string x;
	cout<<"\tLISTA "<<endl;
	for(int i=0;i<10;i++){
		cout<<i+1<<". ";
		cin>>x;
		Nombres[i]=x;
	}
	cout<<"Nombre a eliminar: ";
	string reemp;
	cin>>reemp;
	unsigned pos = 0;
	while(pos<Nombres.size() and Nombres[pos]!=reemp){
		++pos;
	}
	if(pos==Nombres.size()){
		cout<<"No existe tal nombre"<<endl;
	}else{
		for(size_t i=pos;i+1<Nombres.size();++i){
			Nombres[i]=Nombres[i+1];
		}
		Nombres.resize(Nombres.size()-1);
		Mostrar(Nombres);
	}
	cout<<"Añadir nombre: ";
	string add;
	cin>>add;
	unsigned p=0;
	while(p<Nombres.size() and add>Nombres[p]){
		++p;
	}
	Nombres.resize(Nombres.size()+1);
	for(size_t i=Nombres.size()-1;i>p;--i){
		Nombres[i]=Nombres[i-1];
	}
	Nombres[p]=add;
	Mostrar(Nombres);
	
	return 0;
}

