/*Ejercicio 2 (30 pts)
Una empresa de software, a lo largo de sus 10 años de vida (desde 2010 hasta 2019), ha desarrollado y vendido
licencias de 8 sistemas diferentes.
a) Escriba un programa C++ que permita ingresar primero los 8 nombres de los 8 sistemas, y luego los datos de las
ventas de licencias de la siguiente manera: por cada licencia vendida se ingresa una terna compuesta por la fecha de la
venta (como un sólo número DDMMAAAA), código del sistema vendido (de 1 a 8) y precio de esa licencia en dólares.
Los datos finalizan cuando se ingresa fecha 0. Luego el programa debe calcular usando al menos una función en cada
item y mostrar:
b) El producto (software) que más dinero produjo por sus ventas en los 10 años (sumados).
c) En qué año se vendió por primera vez cada uno de los productos.
primeros 5 años.
d) Cuáles sistemas (informe sus códigos) tuvieron ventas en el 4to año inferiores a 20.000 USD.
*/
#include <iostream>
#include <vector>
#include "lib/matrix.h"
using namespace std;

int Soft_mas_vendido(matrix<int> &m) {
	for(size_t j=0; j<m.size(1); ++j){
		int suma = 0;
		for(size_t i=0; i<m.size(0)-1; ++i){
			suma += m[i][j];
		}
		m[3][j] = suma;
	}
	int mayor = m[3][0];
	int pos = 0;
	for(size_t j=1; j<m.size(1); ++j){
		if(m[3][j]>mayor){
			mayor = m[3][j];
			pos = j;
		}
	}
	return pos;
}

void primera_venta(const matrix<int> &m, int anio_ini) {
	for(size_t j=0; j<m.size(1); ++j){
		unsigned i = 0;
		while(m[i][j] == 0) ++i;
		if(i<m.size(0)-1){
			cout<<"Primer venta del software "<<j+1<<": año "<<anio_ini+i<<endl;
		}
	}
}
void vectas_inferiores_a_20000_anio_x(const matrix<int> &m, int x) {
	for(size_t j=0; j<m.size(1); ++j){
		if(m[x][j]<20000)
			cout<<"Software "<<j+1<<endl;
	}
}

int main() {
	cout<<"Cantidad de softwares: "; int soft;cin>>soft;
	cout<<"\nPERIODO DE TIEMPO\nPrimer año: "; int anio_ini; cin>>anio_ini;
	cout<<"Ultimo año: ";int anio_fin; cin>>anio_fin;
	vector<string> v(soft);
	for(size_t i=0; i<v.size(); ++i){
		cout<<"Nombre del sistema "<<i+1<<" :";
		cin>>v[i];
	}
	matrix<int> m(anio_fin-anio_ini+2,soft,0);
	cout<<"\nFecha ddmmaaaa ("<<anio_ini<<"-"<<anio_fin<<"): "; int fecha; cin>>fecha;
	while(fecha != 0){
		cout<<"Cod licencia (1-"<<soft<<"): "; int CodLic; cin>>CodLic;
		cout<<"Precio USD: "; int precio; cin>>precio;
		m[(fecha%10000)-anio_ini][CodLic-1] += precio;
		cout<<"\nFecha ddmmaaaa ("<<anio_ini<<"-"<<anio_fin<<"): "; cin>>fecha;
	}
	
	int masventas = Soft_mas_vendido(m);
	cout<<"\nSoftware que más dinero hizo: "<<v[masventas]<<endl;
	
	primera_venta(m,anio_ini);
	
	cout<<"\nSoftwares con ventas inferiores a 20000USD en el año: "; int w; cin>>w;
	w = w-anio_ini;
	vectas_inferiores_a_20000_anio_x(m,w);
	return 0;
}

