/*
Ejercicio 3. (34 pts) scriba un programa que permita ingresar los datos de una maraton de 10Km.. 
Se ingresa inicialmente los datos de los de los 47 participantes inscriptos: nombre y nro asignado. 
Luego se leen el Nro y el tiempo (2 datos de tiempo: min y seg) logrado por los corredores que llegaron, 
estos datos terminan con Nro corredor 0 pues no todos llegaron a la meta. Escriba una funcion que obtenga el n�mero de corredor que gan�
la prueba y el numero de corredor que salió ultimo entre quienes finalizaron los 10km
*/

#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

struct participante{
	string nombre;
	int tiempo = -1;
};

tuple<int,int> Primero_y_ultimo(const vector<participante> &v) {
	int posGan=0, posUlt=0;
	int mejorT = 99999, peorT = 0;
	for(size_t i=0; i<v.size(); ++i){
		if(v[i].tiempo<mejorT and v[i].tiempo != -1){
			mejorT = v[i].tiempo;
			posGan = i;
		}
		if(peorT<v[i].tiempo){
			peorT = v[i].tiempo;
			posUlt = i;
		}
	}
	return make_tuple(posGan,posUlt);
}

int main() {
	vector<participante> v(47);
	cout<<"Carga de participantes\n";
	int contar = 0;
	while(contar<47){
		cout<<"\nNombre: "; string nomb; cin>>nomb;
		cout<<"Numero asignado(1-47): "; int num; cin>>num;
		v[num-1].nombre = nomb;
		contar++;
	}
	cout<<"\nLLegadas\n";
	cout<<"numero: ";int num; cin>>num;
	while(num != 0){
		cout<<"TIEMPO\n";
		cout<<"Min: ";int min; cin>>min;
		cout<<"Seg: "; int seg; cin>>seg;
		v[num].tiempo = min*60+seg;
		cout<<"numero: "; cin>>num;
	}
	int posGan = 0, posUlt = 0;
	tie(posGan,posUlt) = Primero_y_ultimo(v);
	cout<<"Primero: "<<v[posGan].nombre<<"\tTiempo: "<<v[posGan].tiempo/60<<"'"<<v[posGan].tiempo%60<<"''";
	cout<<"\nUltimo: "<<v[posUlt].nombre<<"\tTiempo: "<<v[posUlt].tiempo/60<<"'"<<v[posUlt].tiempo%60<<"''";
	return 0;
}

