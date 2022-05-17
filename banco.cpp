#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

using namespace std;

struct Cliente{
	char nombre[30];
	char clave[10];
	int edad;
};

struct Nodo{
	Cliente c;
	Nodo *siguiente;	
};

//Prototipos de Funciones
void cargar_cliente(Cliente &c);
void insertarCola(Nodo *&frente,Nodo *&fin,Cliente c);
bool cola_vacia(Nodo * frente);
void suprimirCola(Nodo *&,Nodo *&,Cliente &);
void mostrarClientes(Nodo*frente);
void menucliente();
void buscarCliente(Nodo*&frente,Nodo*&fin,Cliente &c);
void modificarClave(Nodo*&frente,Nodo*&fin, Cliente &c);
	Nodo *frente = NULL;
	Nodo *fin = NULL;

int main(){
menucliente();
getch();
return 0;	
}
void menucliente(){
	int opcion=0;
	do
	{
		cout << endl << "                   BANCO                   ";
		cout << endl << " 1. Insertar Cliente     2. Eliminar cliente         ";
		cout << endl << " 3. Mostrar clientes     4. Buscar un cliente   ";
		cout << endl << " 5. Cambiar Clave        6. Salir  ";
		cout << endl << endl << " Escoja una Opcion: ";
		cin >> opcion;
		switch(opcion){
			case 1:
				cout << endl << endl << " INSERTA UN CLIENTE " << endl << endl;
				Cliente c;
                cargar_cliente(c);
                insertarCola(frente,fin, c);
			break;
			case 2:
				cout << endl << endl << " ELIMINAR UN NODO EN LA COLA " << endl << endl;
				Cliente n;
		        suprimirCola(frente,fin,n);
			break;
			case 3:
				cout << endl << endl << " MOSTAR COLA " << endl << endl;
				mostrarClientes(frente);
			break;	
			case 4:
				cout << endl << endl << " BUSCAR CLIENTE " << endl << endl;
				buscarCliente(frente,fin,c);
			break;	
			case 5:
				cout << endl << endl << " BUSCAR  UN CLIENTE POR SU NOMBRE " << endl << endl;
                modificarClave(frente,fin,c);
			break;
			}
	} while (opcion != 6);
}
void cargar_cliente(Cliente &c){
	fflush(stdin);
	cout<<"\tAgregando un Nuevo Cliente"<<endl;
	cout<<"Nombre: "; cin.getline(c.nombre,30,'\n');
	cout<<"Clave: "; cin.getline(c.clave,10,'\n');
	cout<<"Edad: "; cin>>c.edad;
	cout<<"\n";
} 
void insertarCola(Nodo *&frente,Nodo *&fin,Cliente c){
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo->c = c;
	nuevo_nodo->siguiente = NULL;
	if(cola_vacia(frente)){
		frente = nuevo_nodo;
	}
	else{
		fin->siguiente = nuevo_nodo;
	}
	fin = nuevo_nodo;
}
bool cola_vacia(Nodo *frente){
	return (frente == NULL)? true : false;
}
void suprimirCola(Nodo *&frente,Nodo *&fin,Cliente &c){
	frente->c=c ;
	Nodo *aux = frente;
	if(frente == fin){
		frente = NULL;
		fin = NULL;
	}
	else{
		frente = frente->siguiente;
	}
	delete aux;
}
void mostrarClientes(Nodo*frente){
	while(cola_vacia(frente)!=true){
		cout<<"Nombre: "<< frente->c.nombre<<endl;
		cout<<"Clave: "<<frente->c.clave<<endl;
		cout<<"Edad: "<<frente->c.edad<<endl;
		cout<<"\n";
		frente=frente->siguiente;
	}
}
void modificarClave(Nodo*&frente,Nodo*&fin,Cliente &c){
	Nodo *aux = frente;
	char buscarPorNombre[30];
	bool encontrado= false;
	cout<<"Ingrese el dato del nombre a buscar para modificar\n";
	cin>> buscarPorNombre;
	if(cola_vacia(frente)!= true)
	while(aux!=NULL && encontrado != true){
		if(strcmp(aux->c.nombre, buscarPorNombre)== 0){
		cout<<"\n nodo con le dato ( "<<buscarPorNombre<<" ) Encontrado";
		cout<<"Ingrese el nuevo dato para modificar\n";
		cin>> aux->c.clave;
		cout<<"\n dato modificado correctamente\n\n";
		encontrado=true;
		}aux=aux->siguiente;
	}
	if(encontrado==true){
		cout<<"El elemento --> "<<buscarPorNombre<<" ha sido encontrado exitosamente y fue modificado ";
	}else{
		cout<<"No se encontro el elemento";
	}
}
void buscarCliente(Nodo*&frente,Nodo*&fin,Cliente &c){
	bool encontrado= false;
	char nombrecliente[30];

	cin>> nombrecliente;
	while(cola_vacia(frente)!= true){
		if(strcmp(frente->c.nombre, nombrecliente)== 0){
			encontrado =true;
		}frente=frente->siguiente;
	}
	if(encontrado==true){
		cout<<"El elemento --> "<< nombrecliente<<" ha sido encontrado exitosamente ";
	}else{
		cout<<"No se encontro el elemento";
	}
}


