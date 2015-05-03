#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class frtria{
	private: 										/************************************************/
		int cantp; 									/*Cantidad de productos.						*/
		char *nombfrtria;							/*Nombre de la ferreteria.						*/
		char *codp;									/*Codigo del producto.							*/
		char **nom_prod;							/*Nombre del producto.							*/
		string f_entrega;							/*Fecha de entrega.								*/
	public:											/*----------------------------------------------*/
		frtria(int);								/*Constructor de la clase Ferreteria.			*/
		~frtria();									/*Destructor de la clase Ferreteria.			*/
		frtria(const frtria &);						/*Constructor copia de esta misma clase.		*/
		frtria &operator=(const frtria &);			/*Sobrecarga del operador de asignacion			*/
		void establecer();							/*Metodo establecer que pide los datos			*/
		void print();								/*Metodo print que imprime los datos almacenados*/
};													/************************************************/

frtria::frtria (int cp){							/*Iniciando los datos con el constructor. 		*/				
	cout << "\n<< Ejecutando constructor >>\n";		/*----------------------------------------------*/
	cantp = cp;
	nombfrtria = new char[50];
	codp = new char;
	nom_prod = new char *[cantp];
	
	for(int i=0; i<cantp; i++){
		nom_prod[i] = new char[50];
		strcpy(nom_prod[i], " ");
	}
}

frtria::~frtria(){									/*Destruyendo los datos.						*/
	for(int i=0; i<cantp; i++)						/*----------------------------------------------*/
		delete nom_prod[i];

	delete [] nom_prod;
	delete [] codp;
	delete [] nombfrtria;
	cout << "\n<< Destruyendo... >>\n";
}

frtria::frtria(const frtria &fer){					/* Constructor copia. 							*/
	cout << "\n<< Ejecutando constructor copia >>\n";/*---------------------------------------------*/
	cantp = fer.cantp;
	nombfrtria = fer.nombfrtria;
	codp = fer.codp;
	nom_prod = new char *[cantp];
	
	for(int i=0; i<cantp; i++){
		nom_prod[i] = new char [strlen(fer.nom_prod[i])+1];
		strcpy(nom_prod[i], fer.nom_prod[i]);
	}

	f_entrega = fer.f_entrega;
}

frtria &frtria::operator=(const frtria &fer){		/*Sobrecargando el operador de asignacion.		*/
	cout<<"\n<< Sobrecargando el operador de asignacion >>\n";/*------------------------------------*/
	for(int i=0; i<cantp; i++)
		delete [] nom_prod[i];
	
	delete [] nom_prod;
	delete [] codp;
	delete [] nombfrtria;

	cantp = fer.cantp;
	codp = fer.codp;
	nombfrtria = new char [strlen(fer.nombfrtria)+1];
	strcpy(nombfrtria, fer.nombfrtria);
	nom_prod = new char *[cantp];

	for(int i=0; i<cantp; i++){
		nom_prod[i] = new char [strlen(fer.nom_prod[i])+1];
		strcpy(nom_prod[i], fer.nom_prod[i]);
	}

	f_entrega = fer.f_entrega;
	return *this;
}

void frtria::establecer(){						/*Metodo establecer o insercion de los datos.		*/
	cout << "\nNombre de la Ferreteria: ";		/*--------------------------------------------------*/
	fflush(stdin); cin >> nombfrtria; fflush(stdin);
	cout << "-------------------------------------------------\n";

	for(int i=0; i<cantp; i++){
		cout << "\nNombre del producto #" << (i+1) << ": ";
		fflush(stdin); cin >> nom_prod[i];
		cout << "--------------------------------------\n";
	}

	cout << "\nCodigo del producto de la Ferreteria: ";
	fflush(stdin); cin >> codp;
	cout << "-------------------------------------------------\n";

	cout << "\nFecha de entrega de los productos: ";
	fflush(stdin); cin >> f_entrega;
	cout << "-------------------------------------------------\n";
}

void frtria::print(){							/*Metodo para imprimir los datos almacenados.		*/
	cout << "\nFerreteria: " << nombfrtria;		/*--------------------------------------------------*/
	cout << "\n------------------------------------------------------------------";
	cout << "\n<< Nombre de los productos con su codigo de pedido >> " << endl;
	cout << "------------------------------------------------------------------\n";
	
	for(int i=0; i<cantp; i++)
		cout << " -> Producto #" << (i+1) << ": " << nom_prod[i] << "| Codigo de pedido #" << (i+1) << ": " << codp << endl;
	cout << "\n<< Fecha de entrega de todos los productos: " << f_entrega << "\n\n";
}

int main(int argc, char *argv[]) {
	int npf;

	cout << "<< Cantidad de productos de la Ferreteria: ";
	cin >> npf; fflush(stdin);
	
	frtria fer1(npf);							/*Creando objeto y pasandole valores al constructor.*/
	fer1.establecer();							/*Escribiendo los datos en la clase.				*/
	system("CLS");								/*--------------------------------------------------*/
	
	fer1.print();								/*Imprimiendo los datos extraidos por el objeto.	*/
	cout << "\n\n";								/*Generando un segundo objeto y pasandole valores. 	*/
	frtria fer2(fer1);							/*--------------------------------------------------*/
	cout << "\n\n";
	
	fer2.print();								/*Imprimiendo los datos extraidos por el objeto 2.	*/
	frtria fer3(npf);							/*Generando un tercer objeto y pasandole valores. 	*/
	fer3 = fer1;								/*Copiando el primer objeto al tercero.				*/
	cout << "\n\n";								/*--------------------------------------------------*/
	
	fer3.print();								/*Imprimiendo los datos del objeto 3.				*/
												/*--------------------------------------------------*/
	system("PAUSE>NULL");
	return 0;
}
