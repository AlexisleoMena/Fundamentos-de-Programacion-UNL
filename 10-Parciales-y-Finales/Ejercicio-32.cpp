/*
Para poder postularse a una determinada beca, los estudiantes deben cumplir los siguientes
requisitos:
- tener al menos 15 materias aprobadas
- tener promedio igual o mayor a 7
- que su plan de trabajo sea calificada con al menos 6pts
Entre los que cumplan los requisitos, se calcula un puntaje para cada uno para establecer un
orden de mérito. El puntaje se obtiene sumando:
- 2 por cada materia aprobada
- 10 multiplicado por la diferencia entre su promedio y el mínimo (7)
- 5 multiplicado por la diferencia entre el puntaje de su plan de trabajo y el mínimo (6)
- 8 pts adiciones si sabe inglés
Escriba un programa que permita ingresar los datos de N estudiantes (N es dato inicial) e informe
luego los nombres de los 2 con mejores puntajes de entre los que cumplan los requisitos. Por
cada estudiante se ingresa el nombre, la cantidad de materias aprobadas, su promedio, el puntaje
que obtuvo su plan de trabajo, y su nota en el examen de inglés (que se aprueba con 7). La nota
del examen de inglés solo debe pedirse cuando de acuerdo a los datos anteriores se determina
que cumple con los requisitos mínimos.
Diseñe, implemente y utilice en su programa, dos funciones:
- una que determine si un alumno cumple o no con los requisitos mínimos
- otra que calcule el puntaje total de un alumno
Por ejemplo, si alumno "Juan Perez” tiene 22 materias aprobadas, promedio 8.5, obtuvo un 9 en
su plan de trabajo, y un 7 en inglés: la 1er función debe indicar que cumple con los requisitos, y la
segunda que su puntaje es 82pts (22x2=44 por las materias, 10x(8.5-7)=15 por el promedio, 5x(9-
6)=15 por el plan de trabajo, y 8 por saber inglés).
*/

#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

struct postulante{
	string nombre;
	int aprobadas, promedio, puntajePT, NotaIng = -1, merito = 0;
};

bool Cumple_requisitos(postulante x){
	if(x.NotaIng != -1){
		return true;
	}
	return false;
}

void Alumnos_que_cumplen_requisitos(const vector<postulante> &v){
	cout<<"\nAlumnos que cumplen los requisitos minimos: \n";
	for(size_t i=0; i<v.size(); ++i){
		if(Cumple_requisitos(v[i])){
			cout<<v[i].nombre<<endl;
		}
	}
}

void calcular_merito(postulante &x){
	if(x.NotaIng >= 7){
		x.merito = 2*x.aprobadas + (x.promedio - 7)*10 + (x.puntajePT - 6) + 8;
	}else{
		x.merito = 2*x.aprobadas + (x.promedio - 7)*10 + (x.puntajePT - 6);
	}
}

tuple<int,int> Mejores_puntajes(vector<postulante> &v){
	for(size_t i=0; i<v.size(); ++i){
		if(Cumple_requisitos(v[i])){
			calcular_merito(v[i]);
		}
	}
	int MejorP = v[0].merito;
	int SegundoM = v[1].merito;
	if(SegundoM > MejorP){swap(SegundoM, MejorP);}
	for(size_t i=2; i<v.size(); ++i){
		if(v[i].merito > MejorP){
			SegundoM = MejorP;
			MejorP = v[i].merito;
		}
		if(v[i].merito > SegundoM){
			SegundoM = v[i].merito;
		}
	}
	int posMejor = 0, posSegundo = 0;
	while(MejorP != v[posMejor].merito)	++posMejor;
	while(SegundoM != v[posSegundo].merito) ++posSegundo;
	
	return make_tuple(posMejor, posSegundo);
}

int main() {
	cout<<"Cantidad de postulantes: "; int n; cin>>n;
	vector<postulante> v(n);
	for(size_t i=0; i<v.size(); ++i){
		cout<<"Postulante "<<i+1<<endl;
		cout<<"Nombre: ";cin>>v[i].nombre;
		cout<<"Materias aprobadas: ";cin>>v[i].aprobadas;
		cout<<"Promedio: ";cin>>v[i].promedio;
		cout<<"Puntaje plan de trabajo: "; cin>>v[i].puntajePT;
		if((v[i].aprobadas >= 15 and v[i].promedio >= 7) && v[i].puntajePT >= 6){
			cout<<"Nota de ingles: "; cin>>v[i].NotaIng;
		}
	}
	Alumnos_que_cumplen_requisitos(v);
	int MejorP,SegundoM;
	tie(MejorP, SegundoM) = Mejores_puntajes(v);
	cout<<"\nMejor Puntaje: "<<v[MejorP].nombre<<endl;
	cout<<"Segundo mejor: "<<v[SegundoM].nombre;
	return 0;
}

