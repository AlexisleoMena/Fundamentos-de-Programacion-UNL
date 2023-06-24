/*
En una determinada competencia de programación las reglas son las siguientes:
- cada equipo debe resolver 3 problemas... cada vez que intenta resolver un problema, envía su
solución al servidor y el servidor inmediatamente responde si es o no correcta.
- gana el que más problemas resuelve correctamente
- pero en caso de empate, se calcula un tiempo total para cada equipo y gana el que menos
tiempo total suma:
- por cada problema resuelto se suma el tiempo que tardó en resolverlo, y además más 15
minutos adicionales por cada intento fallido.
- para los problemas no resueltos correctamente, no se suma tiempo (tampoco los intentos
fallidos)
Escriba un programa que permita cargar los datos de N equipos (N es dato inicial) e indique al
final el nombre del ganador y del segundo. Por cada equipo se debe permitir ingresar: nombre, y
tiempo y cantidad de intentos fallidos para cada problema. Si un equipo no logra resolver un
problema, se ingresa -1 en lugar del tiempo del ejercicio, y el programa no debe solicitar la
cantidad de intentos fallidos para ese problema.
Diseñe, implemente y utilice en su programa, dos funciones:
- una que reciba los tres tiempos (de cada ejercicio) y retorne la cantidad de problemas resueltos
(cuantos son distintos de -1);
- otra que calcule el tiempo total de un equipo a partir de los tres tiempos de cada ejercicio y las 3
cantidades de intentos fallidos (sume los tiempos de los resueltos y los 15 min adicionales por
cada intento fallido).
Ejemplo: si un equipo llamado "FooBar" resolvió solo el 1er y 3er problema, al 1ero lo resolvió
correctamente en 25min en el 1er intento, pero el 3ro le llevó 40min y 3 intentos (2 fallidos, el 3ro
fue correcto), para ese equipo se ingresarán los datos: "FooBar", 25, 0, -1, 40, 2. "FooBar" es el
nombre, 25 y 0 corresponden al 1er problema (resuelto en 25min, con 0 intentos fallidos). -1 al
segundo (no resuelto), 40 y 2 al 3ro (resuelto e 40 min luego de 2 intentos fallidos). Para ese
equipo la 1er función deberá retornar 2 (cant. de problemas resueltos), y la 2da deberá retornar 95
(tiempo total: 25m + 40m + 2*15m)
*/

#include <iostream>
#include <vector>

using namespace std;

struct equipo{
	string nombre;
	vector<int> tiempo, fallidos;
};

int ejercicios_resueltos(equipo x){
	int resueltos = 0;
	for(size_t i=0; i<x.tiempo.size(); ++i){
		if(x.tiempo[i] != -1){
			resueltos++;
		}
	}
	return resueltos;
}

int Tiempo_total_del_equipo_x(const vector<equipo> &v, int x) {
	int tiempo = 15*(v[x].tiempo.size() - ejercicios_resueltos(v[x]));
	for(size_t i=0; i<v[x].tiempo.size();++i){
		if(v[x].tiempo[i] != -1){
			tiempo += v[x].tiempo[i];
		}
	}
	return tiempo;
}

int main() {
	cout<<"Cantidad de equipos: "; int n; cin>>n;
	vector<equipo> v(n);
	for(size_t i=0; i<v.size(); ++i){
		cout<<"Nombre: "; cin>>v[i].nombre;
		for(int j=1; j<= 3; ++j){
			int times = 0, fail = 0;
			cout<<"\nEJERCICIO "<<j+1<<endl;
			cout<<"Tiempo (min, -1 si no logro resolver el ejercicio): "; cin>>times;
			v[i].tiempo.push_back(times);
			cout<<"Intentos fallidos: "; cin>>fail;
			v[i].fallidos.push_back(fail);
		}		
	}
	cout<<"Tiempo total del equipo 1: "<<Tiempo_total_del_equipo_x(v, 0)<<endl;
	return 0;
}

