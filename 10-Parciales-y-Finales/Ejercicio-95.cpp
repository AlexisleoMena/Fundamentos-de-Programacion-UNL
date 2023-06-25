/*
Ejercicio 1 (35pts) Se dispone de un archivo binario "Pacientes.dat". 
El archivo fue creado por un programa C++ usando la expresion: archi.write(reinterpret_cast<char*>(&x),sizeof(x)); 
donde x es de tipo Ficha, siendo Ficha un struct que contiene los datos de cada 
paciente: DNI, nombre, apellido, direccion, telefono, obra social. 
Proponga una posible definicion del struct Ficha e implemente una funcion verificarDatos(...) que reciba como 
parametros el DNI de un paciente, un nombre y un apellido. La funcion debe buscarlo en el archivo (por su DNI) y 
verificar si el nombre y el apellido coinciden. Si encuentra al paciente en el archivo y los datos no coinciden, 
debe corregirlos (modificar nombre y apellido). Ademos debe retornar un entero con su posicion en la lista de pacientes
(si es el 1ro de la lista, el 2do, 3ro, etc). Si el dni no estaba en la lista, debe retornar -1. Para implementar la
funcion, no debe usar ningun contenedor (list, vector, etc) ni arreglo en memoria para cargar todos los datos, sino 
que debe operar directamente sobre el archivo.
*/
#include <iostream>
#include <fstream>

using namespace std;

struct Ficha{
	int DNI;
	char nombre[20];
	char apellido[20];
	char direccion[25];
	int telefono;
	char obrasocial[5];
};

int verificardatos(int dni, string nombre, string apellido) {
	fstream f("Pacientes.dat", ios::binary|ios::in|ios::out|ios::ate);
	int n = f.tellg()/sizeof(Ficha);
	f.seekg(0);
	int pos = -1;
	for(int i=0; i<n; ++i){
		Ficha a;
		f.read(reinterpret_cast<char*>(&a),sizeof(a));
		if(a.DNI == dni){
			pos = i;
			string Nom = a.nombre;
			string Ape = a.apellido;
			if(Ape != apellido or Nom != nombre){
				cout<<"Se encontró el dni, pero los datos no coinciden\n";
				cout<<"Diga su nombre: ";cin>>a.nombre;
				cout<<"Diga su apellido: ";cin>>a.apellido;
				f.write(reinterpret_cast<char*>(&a),sizeof(a));
				break;
			}
		}
	}
	return pos;
}

int main(int argc, char *argv[]) {
	int n = verificardatos(1111111,"alexis","mena");
	if(n == -1)
		cout<<"No hay paciente con tal DNI";
	else
		cout<<"Esta en la posicion: "<<n;
	return 0;
}

