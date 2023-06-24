/*
Ej 1 (20pts) Considere el struct fecha{unsigned int anio, mes, dia;} y escriba el código de una función C++
llamada calcular_edad(…) que devuelva un entero con la edad de una persona en años y debe recibir 2
parámetros de tipo fecha: el 1ro con la fecha de nacimiento de una persona y el 2do parámetro con la fecha
actual. La edad debe corresponder a años cumplidos.
*/

#include <iostream>
using namespace std;

struct Fecha{
	int dia,mes,anio;
};

int operar_fecha(Fecha f){
	return f.anio*10000+f.mes*100+f.dia;
}

int calcular_edad(Fecha hoy, Fecha nac){
	int d_hoy = operar_fecha(hoy);     //4. enviar a calcular, restar a la fecha actual
	int d_nac = operar_fecha(nac);     //5. enviar a calcular, la fecha de nacimiento
	return (d_hoy-d_nac)/10000; //dividirlo por 10000 para tener los años
}

int main() {
	Fecha hoy; //1. struct fecha de hoy
	cout<<"\tFECHA DE HOY"<<endl;
	cout<<"Dia: ";
	cin>>hoy.dia;
	cout<<"Mes: ";
	cin>>hoy.mes;
	cout<<"Año: ";
	cin>>hoy.anio;
	Fecha nac; 
	cout<<"\tFECHA DE NACIMIENTO"<<endl;
	cout<<"Dia: ";
	cin>>nac.dia;
	cout<<"Mes: ";
	cin>>nac.mes;
	cout<<"Año: ";
	cin>>nac.anio; //2. struct con la fecha de nacimiento
	cout<<"Tiene "<<calcular_edad(hoy,nac)<<" años"; //3. enviar a calcular
	return 0;
}

