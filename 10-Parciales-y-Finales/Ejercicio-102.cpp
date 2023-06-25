/*
Para poder postularse a una determinada beca, los estudiantes deben cumplir los siguientes requisitos:
- tener al menos 15 materias aprobadas
- tener promedio igual o mayor a 7
- que su plan de trabajo sea calificada con al menos 6pts
Entre los que cumplan los requisitos, se calcula un puntaje para cada uno para establecer un orden de m�rito. 
El puntaje se obtiene sumando:
- 2 por cada materia aprobada
- 10 multiplicado por la diferencia entre su promedio y el minimo (7)
- 5 multiplicado por la diferencia entre el puntaje de su plan de trabajo y el m�nimo (6)
- 8 pts adiciones si sabe ingles
Escriba un programa que permita ingresar los datos de N estudiantes (N es dato inicial) e informe luego  los nombres de 
los 2 con mejores puntajes de entre los que cumplan los requisitos. 
Por cada estudiante se ingresa el nombre, la cantidad de materias aprobadas, su promedio, el puntaje que obtuvo su plan 
de trabajo, y su nota en el examen de ingles (que se aprueba con 7).
 La nota del examen de ingles solo debe pedirse cuando de acuerdo a los datos anteriores se determina que cumple con los
 requisitos minimos.
Diseñe, implemente y utilice en su programa, dos funciones: 
- una que determine si un alumno cumple o no con los requisitos minimos
- otra que calcule el puntaje total de un alumno
*/
#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

bool Evaluar(int MatAprob, int promedio, int PuntajePT){
	if(MatAprob >= 15 and promedio >= 7 and PuntajePT >= 6) return true;
	return false;
}
int Calcular_merito(int MatAprob, int Prom, int PuntajePlanT, int NotaIngles) {
	int Puntaje = MatAprob*2 + 10*(Prom-7) + 5*(PuntajePlanT-6);
	if(NotaIngles >= 7) Puntaje += 8;
	return Puntaje;
}

tuple<int,int> pos_mejores_puntajes(vector<int> Puntajes) {
	int mejor = Puntajes[0];
	int segundo = Puntajes[1];
	if(segundo>mejor){
		int aux = mejor;
		mejor = segundo;
		segundo = aux;
	}
	for(size_t i=2;i<Puntajes.size();i++){
		if(Puntajes[i]>mejor){
			segundo = mejor;
			mejor = Puntajes[i];
		}else{
			if(Puntajes[i]>segundo){
				segundo = Puntajes[i];
			}
		}
	}
	unsigned PosM = 0;
	while(PosM<Puntajes.size() and mejor!=Puntajes[PosM]) ++PosM;
	unsigned PosSM = 0;
	while(PosSM<Puntajes.size() and segundo!=Puntajes[PosSM]) ++PosSM;
	return make_tuple(PosM,PosSM);
}

int main() {
	cout<<"Cantidad de estudiantes a evaluar: ";
	int N;
	cin>>N;
	vector<int>Puntajes;
	vector<string>Nombres;
	string nom;
	int MatAprob,Prom,PuntajePlanT, NotaIngles;
	int puntaje;
	int c=0;
	for(int i=0;i<N;i++){
		cout<<"--------------------------------------"<<endl;
		cout<<"Nombre: ";cin>>nom;
		cout<<"Materias aprobadas: ";cin>>MatAprob;
		cout<<"Promedio: ";cin>>Prom;
		cout<<"Puntaje obtenido en el plan de trabajo: ";cin>>PuntajePlanT;
		cout<<"Nota de ingles: ";cin>>NotaIngles;
		if(Evaluar(MatAprob,Prom,PuntajePlanT)){
			puntaje = Calcular_merito(MatAprob,Prom,PuntajePlanT,NotaIngles);
			Puntajes.resize(Puntajes.size()+1);
			Nombres.resize(Nombres.size()+1);
			Puntajes[c] = puntaje;
			Nombres[c] = nom;
			c++;
		}
		cout<<"--------------------------------------"<<endl;
	}
	int mejor, segundo;
	tie(mejor,segundo) = pos_mejores_puntajes(Puntajes);
	cout<<"Mejor puntaje: "<<Nombres[mejor]<<endl;
	cout<<"Segundo mejor: "<<Nombres[segundo];
	return 0;
}

