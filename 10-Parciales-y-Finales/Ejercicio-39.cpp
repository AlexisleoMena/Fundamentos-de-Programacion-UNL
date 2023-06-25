/*
Ejercicio 1 (25pts) Escriba un programa en C++ que simule un sistema de control de acceso por contraseña de
la siguiente manera: a) En una primer etapa debe permitir cargar los datos de los usuarios válidos (pares de
datos: nombre y contraseña). No se conoce la cantidad de usuarios válidos y los datos terminan con el usuario
“ZZZ”. En esta carga inicial, debe verificar mediante un función validar_contraseña que la contraseña no sea
"1234", "asdf", "pass" ni la cadena vacía; mostrando un mensaje de error y solicitando el reingreso de la misma
en estos casos. (nota: proponga usted el prototipo de la función e impleméntela). b) Luego, simular el verdadero
intento de acceso al sistema. El programa debe mostrar el mensaje "Por favor, identifíquese:" y solicitar nombre
y contraseña. Si se ingresa un par nombre+contraseña existente (que coincida con los cargados en el apartado a)
se debe mostrar el mensaje "Bienvenido al sistema sr X" (reemplazando X por el nombre del usuario); sino,
luego de 5 intentos fallidos debe mostrar el mensaje "Fuera bicho!"
*/


#include <iostream>
#include <vector>

using namespace std;

struct Datos{
	string Nombre,Pass;
};

bool Validar(string Pass){
	return Pass=="1234" or Pass=="asdf" || Pass=="pass" or Pass.size()==0;
}

unsigned Buscar(string usuario, vector <Datos> v) {
	unsigned pos=0;
	while(pos != v.size() and v[pos].Nombre != usuario) ++pos;
	return pos;
}
	
int main(int argc, char *argv[]) {
	Datos p;
	vector <Datos> v;
	cout<<"Nombre: "; cin>>p.Nombre;
	while(p.Nombre!="ZZZ"){
		cout<<"Pass: "; cin.ignore();getline(cin,p.Pass);
		while(Validar(p.Pass)){
			cout<<"Pass Invalido\nReintente: ";getline(cin,p.Pass) ;
		}
		v.push_back(p);
		cout<<"Nombre: "; cin>>p.Nombre;
	};
	cout<<"Por favor, identifiquese: ";
	string usuario, contra;
	cout<<"\nNombre: ";cin>>usuario;
	cout<<"Pass: ";cin>>contra;
	unsigned posicion = Buscar(usuario,v);
	if(posicion != v.size()){
		if(contra == v[posicion].Pass){
			cout<<"Bienvenido al sistema sr "<<v[posicion].Nombre;
		}else{
			cout<<"Contraseña incorrecta, reintente: ";
			cin>>contra;
			int c=1;
			while(contra != v[posicion].Pass and c<=4){
				cout<<"Contraseña incorrecta, reintente: ";
				cin>>contra;
				c++;
			}
			if(contra != v[posicion].Pass and c>4){
				cout<<"FUERAAAA BICHO!!!!";
			}else{
				cout<<"Bienvenido al sistema sr "<<v[posicion].Nombre;
			}
		}
	}else{
		cout<<"No existe usuario con ese nombre!.";
	}
	
	return 0;
}
