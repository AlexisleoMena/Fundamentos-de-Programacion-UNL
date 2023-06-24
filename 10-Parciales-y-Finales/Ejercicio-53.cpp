/*
Ejercicio 1 (25 pts). En una carrera de 200 metros participaron N atletas, donde N es un valor que se lee al
comienzo (se sabe que hay menos de 50 atletas). Por cada atleta se ingresa el nombre y tiempo registrado (en
seg). a) Muestre los nombres de los 2 ganadores y sus tiempos. b) Determine cuántos atletas estuvieron a 5
segundos o menos de obtener el segundo lugar. 
*/

#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

struct Datos{
	int tiempo;
	string nombre;
};

tuple<int,int> Mejores_Tiempos(vector<Datos> Atletas);

tuple<string,string> Nombres_Ganadores(vector<Datos>Atletas,int MejorTiempo, int SegundoMejorTiempo);

int A_5_del_podio(vector<Datos> Atletas, int SegundoMejorTiempo);

int main() {
	cout<<"Cantidad de atletas: ";
	int N;
	cin>>N;
	vector<Datos> Atletas(N);
	for(size_t i=0;i<Atletas.size();++i){
		cout<<"Nombre: ";
		cin>>Atletas[i].nombre;
		cout<<"Tiempo(seg): ";
		cin>>Atletas[i].tiempo;
	}
	int MejorTiempo,SegundoMejorTiempo;
	tie(MejorTiempo,SegundoMejorTiempo) = Mejores_Tiempos(Atletas);
	string NombreMejor,NombreSegundoMejor;
	tie(NombreMejor,NombreSegundoMejor) = Nombres_Ganadores(Atletas,MejorTiempo,SegundoMejorTiempo);
	cout<<"Primer puesto: "<<NombreMejor<<" | Tiempo: "<<MejorTiempo<<"s"<<endl;
	cout<<"Segundo puesto: "<<NombreSegundoMejor<<" | Tiempo: "<<SegundoMejorTiempo<<"s"<<endl;
	int podio = A_5_del_podio(Atletas,SegundoMejorTiempo);
	cout<<"Atletas a 5 segundos o menos del podio: "<<podio;
	return 0;
}

tuple<int,int> Mejores_Tiempos(vector<Datos> Atletas) {
	int tiempoG1 = 9999;
	int tiempoG2 = 9999;
	for(size_t i=0;i<Atletas.size();++i){
		if(tiempoG1>Atletas[i].tiempo){
			tiempoG2 = tiempoG1;
			tiempoG1 = Atletas[i].tiempo;
		}else{
			if(tiempoG2>Atletas[i].tiempo){
				tiempoG2 = Atletas[i].tiempo;
			}
		}
	}
	return make_tuple(tiempoG1,tiempoG2);
}

tuple<string,string> Nombres_Ganadores(vector<Datos>Atletas,int MejorTiempo, int SegundoMejorTiempo) {
	unsigned posG1 = 0;
	while(posG1 <= Atletas.size() and MejorTiempo!=Atletas[posG1].tiempo) ++posG1;
	unsigned posG2 = 0;
	while(posG2 <= Atletas.size() and SegundoMejorTiempo!=Atletas[posG2].tiempo) ++posG2;
	return make_tuple(Atletas[posG1].nombre,Atletas[posG2].nombre);
}

int A_5_del_podio(vector<Datos> Atletas, int SegundoMejorTiempo) {
	int podio = -2;
	for(size_t i=0;i<Atletas.size();++i){
		if(Atletas[i].tiempo-5 <= SegundoMejorTiempo){
			podio += 1; 
		}
	}
	return podio;
}
