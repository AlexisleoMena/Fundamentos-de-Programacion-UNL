/*
Ejercicio 2 [25 pts] Escriba un programa que lea los datos de 30 alumnos que asistieron a una evaluación de
programación, por cada uno de ellos se ingresa: cod. alumno, dni, nombre y nota. Los datos llegan sin orden
alguno. Una vez terminada la lectura, el usuario deberá ingresar el código correspondiente uno de los alumnos
ingresados y el programa deberá mostrar todos sus datos. Utilizar al menos 2 funciones.
*/

#include <iostream>
#include <vector>
using namespace std;
struct Datos{
	int CodAlumn,dni,nota;
	string nombre;
};
int Buscar_Alumno(vector<Datos> Alumno, int BuscCod) {
	int resultado = 0;
	for(size_t i=0;i<Alumno.size();++i){
		if(BuscCod == Alumno[i].CodAlumn) {
			resultado=i;
			return resultado;
		}
	}
	return resultado;
}

void Mostrar(vector<Datos>Alumno,int Cod) {
	cout<<"Mostrando datos..."<<endl;
	cout<<"Nombre: "<<Alumno[Cod].nombre<<endl;
	cout<<"DNI: "<<Alumno[Cod].dni<<endl;
	cout<<"Nota: "<<Alumno[Cod].nota<<endl;
}

int main() {
	cout<<"Numero de alumnos: ";
	int N;
	cin>>N;
	vector<Datos>Alumno(N);
	for(size_t i=0;i<Alumno.size();++i){
		cout<<"---------------"<<endl;
		cout<<"Código de alumno: ";
		cin>>Alumno[i].CodAlumn;
		cout<<"DNI: ";
		cin>>Alumno[i].dni;
		cout<<"Nombre: ";
		cin>>Alumno[i].nombre;
		cout<<"Nota: ";
		cin>>Alumno[i].nota;
		cout<<"---------------"<<endl;
	}
	cout<<"BUSCAR"<<endl;
	cout<<"Codigo de alumno: ";
	int BuscCod;
	cin>>BuscCod;
	int Cod = Buscar_Alumno(Alumno,BuscCod);
	Mostrar(Alumno,Cod);
	return 0;
}

