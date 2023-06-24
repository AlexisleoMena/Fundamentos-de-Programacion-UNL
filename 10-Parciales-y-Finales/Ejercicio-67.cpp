/*
Ejercicio 3 [25 pts] Escriba un programa que lea los datos de 20 atletas que asistieron a una maratón, por cada
uno de ellos se ingresa: cod. participante, dni, nombre y tiempo que tardó en cruzar la meta. Los datos llegan sin
orden alguno. Una vez terminada la lectura, el usuario deberá ingresar el dni correspondiente uno de los
participantes ingresados y el programa deberá mostrar todos sus datos. Utilizar al menos 2 funciones.
*/
#include <iostream>
#include <vector>

using namespace std;

struct Participante{
	int CodPart;
	float dni;
	string nombre;
	int tiempo;
};

int Buscar_por_dni(vector<Participante> Lista,float buscardni) {
	int PosAtleta=0;
	for(size_t i=0;i<Lista.size();i++){
		if(Lista[i].dni==buscardni) PosAtleta=i;
	}
	return PosAtleta;
}

void Mostrar_Atleta(vector<Participante>Lista,int i) {
	cout<<"Numero del participante: "<<Lista[i].CodPart<<endl;
	cout<<"Nombre: "<<Lista[i].nombre<<endl;
	cout<<"Tiempo: "<<Lista[i].tiempo<<"m"<<endl;
}

int main() {
	cout<<"Cantidad de atletas: ";
	int N;
	cin>>N;
	vector<Participante>Lista(N);
	for(size_t i=0;i<Lista.size();++i){
		cout<<"Nombre: ";
		cin>>Lista[i].nombre;
		cout<<"Numero del participante: ";
		cin>>Lista[i].CodPart;
		cout<<"DNI: ";
		cin>>Lista[i].dni;
		cout<<"Tiempo (min): ";
		cin>>Lista[i].tiempo;
		cout<<"-------------"<<endl;
	}
	cout<<"Buscar por DNI: ";
	float buscardni;
	cin>>buscardni;
	int PosAtleta = Buscar_por_dni(Lista,buscardni);
	Mostrar_Atleta(Lista,PosAtleta);
	return 0;
}

