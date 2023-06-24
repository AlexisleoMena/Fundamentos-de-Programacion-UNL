/*
Ejercicio 1 (35 pts)
a) Diseñe un struct Libro para almacenar los datos de un libro en una librería: título, autor, editorial, año de edición, isbn
(string), género y cantidad de copias disponibles. Escriba un programa cliente que permita cargar los datos de un
conjunto de N libros (N también es dato).
b) Implemente una función C++ llamada agregar_copia(..) que reciba la lista de libros, el isbn de uno, y lo busque en la
lista e incremente en 1 su cantidad de copias. La función debe retornar verdadero si logra incrementar la cantidad, falso
si el libro no estaba en la lista.
c) Diseñe una función libros_por_genero() que reciba el vector de libros original y un género, y retorne un nuevo vector
de libros que contenga solo aquellos que corresponden a ese género.
d) Defina una función stock_libro() que reciba el título y el autor de un libro y retorne la cantidad de ejemplares. Notar
que el libro puede estar varias veces en la lista por tener distintas ediciones, la función debe contarlas todas.
Utilice las funciones desde el programa cliente y en cada caso informe los resultados.
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct libro{
	string titulo, autor, editorial, genero, isbn;
	int anio_ed, copias_disp;
};

bool agregar_copia(vector <libro> &v, string add_for_isbn){
	for(size_t i=0; i<v.size(); ++i){
		if(v[i].isbn == add_for_isbn){
			v[i].copias_disp++;
			return true;
		}
	}
	return false;
}

vector<libro> libros_por_genero(const vector<libro> &v, string search_genero){
	vector<libro> w;
	for(size_t i=0; i<v.size(); ++i){
		if(v[i].genero == search_genero){
			w.push_back(v[i]);
		}
	}
	return w;
}

int stock_libro(const vector<libro> &v, string search_titulo, string search_autor){
	int stocks = 0;
	for(size_t i=0; i<v.size(); ++i){
		if(v[i].titulo == search_titulo and v[i].autor == search_autor){
			stocks += v[i].copias_disp;
		}
	}
	return stocks;
}

void mostrar(const vector<libro> &v){
	cout<<"\nMostrando biblioteca...\n";
	for(size_t i=0; i<v.size(); ++i){
		cout<<"\nTitulo: "<<v[i].titulo<<endl;
		cout<<"Autor: "<<v[i].autor<<endl;
		cout<<"Editorial: "<<v[i].editorial<<endl;
		cout<<"Genero: "<<v[i].genero<<endl;
		cout<<"ISBN: "<<v[i].isbn<<endl;
		cout<<"Año edicion: "<<v[i].anio_ed<<endl;
		cout<<"Copias disponibles: "<<v[i].copias_disp<<endl;
	}
}

int main() {
	cout<<"Cantidad de libros: "; int n; cin>>n;

	vector<libro> v(n);

	cin.ignore();
	for(size_t i=0; i<v.size(); ++i){
		cout<<"\nLIBRO "<<i+1<<endl;
		cout<<"Titulo: "; getline(cin,v[i].titulo);
		cout<<"Autor: "; getline(cin,v[i].autor);
		cout<<"Editorial: "; getline(cin,v[i].editorial);
		cout<<"Genero: ";getline(cin,v[i].genero);
		cout<<"isbn: "; getline(cin,v[i].isbn);
		cout<<"Año de edicion: "; cin>>v[i].anio_ed;
		cout<<"Copias disponibles: "; cin>>v[i].copias_disp;
		cin.ignore();
	}

	mostrar(v);
	cout<<endl;
	cout<<"Añadir copia de libro, diga su isbn: "; string add_for_isbn; getline(cin,add_for_isbn);
	if(agregar_copia(v, add_for_isbn)){
		cout<<"Se añadio copia\n";
	}else{
		cout<<"El libro no esta en la lista\n";
	}
	cout<<endl;
	cout<<"Lista por genero, diga genero: "; string search_genero; getline(cin,search_genero);
	vector<libro> w;
	w = libros_por_genero(v,search_genero);
	mostrar(w);
	cout<<"\nStock disponibles\nDiga titulo: "; string search_titulo; getline(cin,search_titulo);
	cout<<"Diga autor: "; string search_autor; getline(cin,search_autor);
	cout<<"Stocks: "<<stock_libro(v,search_titulo, search_autor);
	return 0;
}

