/*
Ejercicio 3 [30 pts] Se desea seleccionar dos alumnos de una lista de 30 candidatos para una pasantía. Escriba
un programa que permita ingresar los datos de los 30 alumnos, los guarde en un vector de structs, y obtenga
mediante una función los los apellidos y nombres de los dos mejores. Por cada alumno se ingresa apellido y
nombre, promedio, cantidad de materias aprobadas, y cantidad de aplazos. Defina un struct para agrupar estos
datos. Para esta pasantía se considera a un alumno mejor que otro si tiene mayor cantidad de materias aprobadas.
En caso de empate, se considera mejor a quien tenga menor cantidad de aplazos. Si nuevamente hay empate
(igual cantidad de materias aprobadas y de aplazos), a quien tenga mejor promedio.
*/
#include <iostream>
#include <vector>

using namespace std;

struct Datos{
	string nom,ape;
	int aprob,prom,aplazos;
};

int Obtuvo_pasantia(vector<Datos> Alumno) {
	int posGan = 0;
	int MasAprobadas=Alumno[0].aprob,MenosAplazos=Alumno[0].aplazos,MejorProm=Alumno[0].prom;
	for(size_t i=1;i<Alumno.size();++i){
		if(MasAprobadas<Alumno[i].aprob){
			MasAprobadas=Alumno[i].aprob;
			posGan = i;
		}else{
			if(MasAprobadas==Alumno[i].aprob){
				if(MenosAplazos>Alumno[i].aplazos){
					MenosAplazos=Alumno[i].aplazos;
					posGan = i;
				}else{
					if(MenosAplazos==Alumno[i].aplazos){
						if(MejorProm<Alumno[i].prom){
							MejorProm=Alumno[i].prom;
							posGan = i;
						}
					}
				}
			}
		}
	}
	return posGan;
}

void Mostrar_Ganador(vector<Datos> Alumno, int i) {
	cout<<"ALUMNO QUE OBTIENE LA PASANTIA"<<endl;
	cout<<Alumno[i].nom<<" "<<Alumno[i].ape;
}

int main() {
	cout<<"CANTIDAD DE ALUMNOS: ";
	int N;
	cin>>N;
	vector<Datos>Alumno(N);
	cout<<endl<<"--------------------"<<endl;
	for(size_t i=0;i<Alumno.size();++i){
		cout<<"Nombre: ";
		cin>>Alumno[i].nom;
		cout<<"Apellido: ";
		cin>>Alumno[i].ape;
		cout<<"Cantidad de materias aprobadas: ";
		cin>>Alumno[i].aprob;
		cout<<"Cantidad de aplazos: ";
		cin>>Alumno[i].aplazos;
		cout<<"Promedio: ";
		cin>>Alumno[i].prom;
		cout<<"--------------------"<<endl;
	}
	int PosGan = Obtuvo_pasantia(Alumno);
	Mostrar_Ganador(Alumno,PosGan);
	return 0;
}

