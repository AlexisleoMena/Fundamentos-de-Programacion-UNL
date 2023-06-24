/*
Ejercicio 2 (30 pts) Escriba un programa C++ que lea los datos de N alumnos universitarios que
participan en la materia "Fundamentos de programacion" y los organize empleando un struct para
cada uno: struct alumno { string apellido, nombres, int DNI; char sexo; int edad; int nota_parcial1;
int nota_parcial2; bool recupero; }, las dos primeras cadenas almacenan el apellido y nombre del
alumno, la variable DNI registra el número de documento de la persona, sexo será 'M' o 'F', la
edad en años, la nota en ambos parciales y una bandera que indica si recupero o no (bool). Si el
alumno no rindio ese parcial se lee -1 en la nota correspondiente. El valor N es dato inicial del
programa.
Los datos se cargan de la siguiente manera:
- Se leen primero nombre y apellido, DNI, sexo y edad.
- Luego se lee la nota del parcial 1 (-1 en caso que no asistió), y si la nota es reprobado (o no
asistió), solicitar leer la nota del recuperatorio 1, que deberá SOBREESCRIBIR la nota del parcial
para ese alumno (en el struct). Si no asistió al recuperatorio se debe leer -1 y no reemplaza la nota
anterior del parcial. El campo "recupero” del struct debe completarse con verdadero si el alumno
recuperó un parcial.
- DE LA MISMA MANERA se solicita la nota para el parcial 2.
a) Escriba dos funciones, una que reciba la lista de alumnos y determine el % de alumnos del grupo
que aprobaron, y otra el número de alumnos que recuperaron algún parcial. Utilice las funciones
desde el main.
b) Escriba una función para determinar qué alumno obtuvo la mayor calificacion promedio (de
nota_parcial1 y nota_parcial2), y utilícela para mostrar sus datos: apellido, nombre, DNI y sexo, y
nota promedio.
*/
#include <iostream>
#include <vector>

using namespace std;

struct alumno{
	string apellido, nombre;
	int DNI, edad, nota_parcial1, nota_parcial2;
	char sexo;
	bool recupero;
};

int porcentaje_aprobados(const vector<alumno> &v){
	int aprobados = 0;
	for(size_t i=0; i<v.size(); ++i){
		if(v[i].nota_parcial1 >= 60 and v[i].nota_parcial2 >= 60){
			aprobados++;
		}
	}
	return aprobados*100/v.size();
}

int porcentaje_recuperatorios_hechos(const vector<alumno> &v){
	int recuperaron = 0;
	for(size_t i=0; i<v.size(); ++i){
		if(v[i].recupero == true){
			recuperaron++;
		}
	}
	return recuperaron*100/v.size();
}

int mejor_calificacion_promedio(const vector<alumno> &v){
	int mej_prom = (v[0].nota_parcial1 + v[0].nota_parcial2)/2;
	int num_alum = 0;
	for(size_t i=1; i<v.size(); ++i){
		if( ((v[i].nota_parcial1 + v[i].nota_parcial2)/2) > mej_prom){
			mej_prom = (v[i].nota_parcial1 + v[i].nota_parcial2)/2;
			num_alum = i;
		}
	}
	return num_alum;
}

void mostrar_alumno(alumno x){
	cout<<"\nNombre: "<<x.nombre<<" "<<x.apellido
		<<"\nDNI: "<<x.DNI
		<<"\nEdad: "<<x.edad
		<<"\nSexo: "<<x.sexo
		<<"\nNota promedio: "<<(x.nota_parcial1+x.nota_parcial2)/2;
}

int main() {
	cout<<"Cantidad de alumnos: "; int n; cin>>n;
	vector<alumno> v(n);

	for(size_t i=0; i<v.size(); ++i){
		cout<<"\nAlumno "<<i+1<<endl;
		cout<<"Nombre: ";cin>>v[i].nombre;
		cout<<"Apellido: "; cin>>v[i].apellido;
		cout<<"DNI: ";cin>>v[i].DNI;
		cout<<"Sexo (M/F): ";cin>>v[i].sexo;
		cout<<"Edad: "; cin>>v[i].edad;
		cout<<"Nota parcial 1 (-1 si no asistio): ";cin>>v[i].nota_parcial1;
		if(v[i].nota_parcial1 == -1 or v[i].nota_parcial1<60){
			cout<<"Nota del recuperatorio(-1 si no asistió): ";int nota_recup; cin>>nota_recup;
			if(nota_recup != -1){
				v[i].nota_parcial1 = nota_recup;
				v[i].recupero = true;
			}else{
				v[i].recupero = false;
			}
		}
		cout<<"Nota parcial 2 (-1 si no asistio): ";cin>>v[i].nota_parcial2;
		if(v[i].nota_parcial2 == -1 or v[i].nota_parcial2<60){
			cout<<"Nota del recuperatorio(-1 si no asistió): ";int nota_recup; cin>>nota_recup;
			if(nota_recup != -1){
				v[i].nota_parcial2 = nota_recup;
				v[i].recupero = true;
			}else{
				v[i].recupero = false;
			}
		}
	}
	
	cout<<"Porcentaje de aprobados: "<<porcentaje_aprobados(v)<<"%\n";
	cout<<"Porcentaje de recuperatorios: "<<porcentaje_recuperatorios_hechos(v)<<"%\n";
	int alumn_mejor_puntaje = mejor_calificacion_promedio(v);
	cout<<"\nAlumno con mejor calificación promedio";
	mostrar_alumno(v[alumn_mejor_puntaje]);
	return 0;
}

