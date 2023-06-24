/*
Ej. 3 (25pts) En una prueba de maratón compiten 35 atletas. Organice un struct con los datos de cada atleta:
apellido, nombres, número asignado, h1,m1,s1; donde número asignado es un entero entre 1 y 35; y h1,m1,s1
son 3 enteros para el tiempo empleado (hora, minutos, segundos) en completar la prueba. Si tiempo empleado es
0,0,0 significa que el atleta abandonó la prueba. Escriba un programa C++ que ingrese -una vez terminada la
competencia- los datos, sin orden, de cada uno de los 35 atletas. a) Escribir una función que determine el atleta
ganador y mostrar sus datos desde el programa cliente. b) Luego, mostrar los apellidos y nombres de todos los
atletas que terminaron la competencia (sin contar los que abandonaron).
*/
#include <iostream>
#include <vector>

using namespace std;

struct Datos{
	string apellido, nombre;
	int h,m,s;
	int tiempototal;
};

int El_Ganador(vector<Datos> Atleta) {
	float mejorTiempo=9999999;
	int posAtleta=0;
	for(size_t i=0;i<Atleta.size();++i){
		if(Atleta[i].tiempototal<mejorTiempo and Atleta[i].tiempototal>0){
			mejorTiempo=Atleta[i].tiempototal;
			posAtleta=i;
		}
	}
	return posAtleta;
}

void Completados(vector<Datos> Atleta) {
	cout<<endl<<"--------Terminaron la prueba-------"<<endl;
	for(size_t i=0;i<Atleta.size();++i){
		if(Atleta[i].tiempototal>0){
			cout<<Atleta[i].nombre<<" "<<Atleta[i].apellido<<" |Tiempo: "<<Atleta[i].h<<"h "<<Atleta[i].m<<"m "<<Atleta[i].s<<"s "<<endl;
		}
	}
	cout<<"-----------------------------------";
}

int main() {
	cout<<"Cantidad de copetidores: ";
	int N;
	cin>>N;
	vector<Datos>Atleta(N);
	cout<<endl<<"-------------------------"<<endl;
	int num;
	for(size_t i=0;i<Atleta.size();++i){
		cout<<"Numero del atleta (1-"<<N<<"): ";
		cin>>num;
		cout<<"Apellido: ";
		cin>>Atleta[num-1].apellido;
		cout<<"Nombre: ";
		cin>>Atleta[num-1].nombre;
		cout<<"TIEMPO (0,0,0 si abandonó) "<<endl;
		cout<<"Horas: ";
		cin>>Atleta[num-1].h;
		cout<<"Minutos: ";
		cin>>Atleta[num-1].m;
		cout<<"Segundos: ";
		cin>>Atleta[num-1].s;
		Atleta[num-1].tiempototal=Atleta[num-1].h*3600+Atleta[num-1].m*60+Atleta[num-1].s;
		cout<<"-------------------------"<<endl;
	}
	int PosGanador = El_Ganador(Atleta);
	cout<<"GANADOR: "<<Atleta[PosGanador].nombre<<" "<<Atleta[PosGanador].apellido<<" |Tiempo: "<<Atleta[PosGanador].h<<"h "<<Atleta[PosGanador].m<<"m "<<Atleta[PosGanador].s<<"s "<<endl;
	Completados(Atleta);
	return 0;
}

