#include <iostream>
#include <cmath> //Librerria almacena funciones matematicas
#include <windows.h>
#include <stdlib.h>
#include <fstream>
#include "Pelicula.h"//Agregar nuestro header Pelicula.h
#include <string>
#include <sstream> //Imprimir variables con fromato
#include <stdio.h>

using namespace std;
//Declarar arreglos de objetos
Actor arregloActores[20];
Pelicula arregloPeliculas[20];
Funcion arregloFunciones[20];

//Variable para llevar la cantidad de registros
int registrosActor, registrosPeliculas;


void cargarActores(){
    string cadena;//Cadena donde se va a guarda cada linea que se lea desde el archivo
	int idActor = 0, i = 0;//Variables para guardar valores
	string nombreActor;
	ifstream inFile;//Instanciar una entrada de datos desde archivo
	inFile.open("actores.txt");//Usar el archivo actores.txt
	while (getline(inFile, cadena))//Leer una cadena desde inFile y guardarla en cadena
	{
		string idActString = cadena.substr(0, cadena.find(' ')); //obtener el valor de la cadena  recortando desde la posicion 0 hasta la primera vez que se encuentra un espacio (' ') en cadena
		stringstream idActorCast(idActString);//Castear el valor en string para convertirlo a int
		idActorCast >> idActor;//Guardar el valor casteado (Pasado de String a int) en una variable de tipo int
		arregloActores[i].setId(idActor);//Settear (Asignar) el valor de idActor a la instancia de arregloActores[i]
		nombreActor = cadena.substr(cadena.find(' '), cadena.length() - 1);//guardar en nombreActor un substring de cadena (pedazo de cadena) que empieza donde encuentras el primer espacio (' ') hasta cadena.length() - 1, que es el total de longitud de cadena menos 1

		arregloActores[i].setNombre(nombreActor);//Settear (Asignar) el valor de nombreActor a la instancia de arregloActores[i]
		i++;//agregar 1 a i
	}
	inFile.close();
}

void cargarPeliculas(){
	//Declaracion de variables
    string cadena = "", genero, titulo, strCast;
	int  iterador = 0,  numPeli, anio, duracion, cantidad;
	bool adActorRespuesta;
	Actor busquedaDeActor;
	registrosPeliculas = 0;
	ifstream inFile;
	inFile.open("peliculas.txt");
	ifstream inFileActores;
	inFileActores.open("actores.txt");
	while(getline(inFile, cadena)){


		//Primero obtener una linea de inFile(Actores) y la guarda en la cadena
		//Numero de peli
		stringstream caster(cadena.substr(0, cadena.find(' ')));
		caster >> numPeli;//Se guarda en un int real
		arregloPeliculas[iterador].setNumPeli(numPeli); //Se Pasa numPeli a setNumPeli de arregloPeliculas
		cadena = cadena.substr(cadena.find(' ') + 1, cadena.length() - 1);//Se modifica la cadena original, ahora se corta la cadena desde donde encuentr el primer espacio hasta el final menos 1

		//Anio
		stringstream casterAnio(cadena.substr(0, cadena.find(' ')));
		casterAnio >> anio;
		arregloPeliculas[iterador].setAnio(anio);
		cadena = cadena.substr(cadena.find(' ') + 1, cadena.length() - 1);

		//Duracion
		stringstream casterDuracion(cadena.substr(0, cadena.find(' ')));
		casterDuracion >> duracion;
		arregloPeliculas[iterador].setDuracion(duracion);
		cadena = cadena.substr(cadena.find(' ') + 1, cadena.length() - 1);

		//Genero
		arregloPeliculas[iterador].setGenero(cadena.substr(0, cadena.find(' ')));
		cadena = cadena.substr(cadena.find(' ') + 1, cadena.length() - 1);


		//Cantidad de actores
		stringstream  casterCantidad(cadena.substr(0, cadena.find(' ')));
		casterCantidad >> cantidad;
		cadena = cadena.substr(cadena.find(' ') + 1, cadena.length() - 1);


		//Obtener id's en arreglo de int
		int id[cantidad];//Se crea un arreglo de int con el tamaño [cantidad]
		for(int x = 0; x < cantidad; x++){//Repetición para seguir recortando la cadena y guardar cada uno de los id en el archivo en un nuevo espacio del arreglo id
			stringstream casterId(cadena.substr(0, cadena.find(' ')));
			casterId >> id[x];
			cadena = cadena.substr(cadena.find(' ') + 1, cadena.length() - 1);
		}


		//Agregar titulo
		titulo = cadena;
		arregloPeliculas[iterador].setTitulo(titulo);


		//Enlaza actores
		//1.- Buscar actor por id de id[indice] en arregloActores
		for(int buscador = 0; buscador < cantidad; buscador++){

			for(int buscadorActor = 0; buscadorActor < sizeof(arregloActores)/sizeof(arregloActores[0]); buscadorActor++){
				if(arregloActores[buscadorActor].getId() == id[buscador]){
					//Actor encontrado por Id
					//2.- Al encontrarlo, crear objeto Actor, setear ID con id de arregloActores y Nombre con nombre de arregloActores
					busquedaDeActor.setId(id[buscador]);
					busquedaDeActor.setNombre(arregloActores[buscadorActor].getNombre());
					//3.- Pasar el objeto Actor creado anteriormente a arregloPeliculas[i].setActor
					adActorRespuesta = arregloPeliculas[iterador].setActor(busquedaDeActor);
                    if(adActorRespuesta == true){
						cout << "Actor agregado con exito!"<<endl;
					}
					else{
						cout <<"No se pudo agregar al actor..."<<endl;
					}

				}
			}
		}
		cadena = "";
		iterador++;
		registrosPeliculas++;
	}
	inFile.close();
	inFileActores.close();
}

void ingresarFunciones(){
	system("CLS");
	string cveFuncion, hhmm;
	int numPeli, hh, mm;
	int sala, i = 0;
	Hora hora;
	bool success = false, ocupada = false;
	while(i < 20){
		system("CLS");
		cout << "...Antes de empezar registra las funciones...\n"<<endl;
		do{
			cout << "Ingresa el numero de funcion: "<<flush;
			cin >> cveFuncion;
			for(int x = 0; x < sizeof(arregloFunciones)/sizeof(arregloFunciones[0]); x++){
				if(arregloFunciones[x].getCveFuncion() == cveFuncion){
					success = false;
					break;
				}
				else{
					success = true;
				}

			}
		}while(success == false);
		success = false;
		ocupada = false;
		do{
			cout << "Ingresa el numero de pelicula:";
			cin >> numPeli;
			for(int x = 0; x < registrosPeliculas; x++){
				//Buscar numero de peli para ver si existe
				if(arregloPeliculas[x].getNumPeli() == numPeli){
					success = true;
					break;
				}
			}
		}while(success == false);
		success =  !success;
		do{
			cout << "Ingresa la hora de la funcion (Formato: hh:mm):  ";
			cin >> hhmm;
			if(hhmm.length() == 5){

				stringstream horaCast(hhmm.substr(0, 2));
				horaCast >> hh;
				stringstream minuCast(hhmm.substr(3, 2));
				minuCast >> mm;
				if(hh < 0 || hh > 23){
					//La hora esta fuera de rango
					success = false;
				}else{

					stringstream hora2Cast(hhmm.substr(3, 2));
					hora2Cast >> hh;
					stringstream minu2Cast(hhmm.substr(3, 2));
					minu2Cast >> mm;

					if( mm < 0 || mm > 59 ){
						//Los minutos estan fuera de rango
						success = false;
					}
					else{
						stringstream horaCast(hhmm.substr(0, 2));
						horaCast >> hh;
						stringstream minuCast(hhmm.substr(3, 2));
						minuCast >> mm;
						success = !success;
					}
				}

			}
		}while(success == false);
		success = false;
		do{
			cout << "Ingresa el numero de sala: ";
			cin >> sala;
			if(arregloFunciones[0].getCveFuncion().empty()){
				arregloFunciones[i].setCveFuncion(cveFuncion);
						arregloFunciones[i].setCveFuncion(cveFuncion);
						arregloFunciones[i].setNumPeli(numPeli);
						hora.setHh(hh);
						hora.setMm(mm);
						arregloFunciones[i].setHora(hora);
						arregloFunciones[i].setSala(sala);
						i++;
						success = true;
			}
			else{
				for(int x = 0; x < i; x++){
				if(arregloFunciones[x].getSala() == sala){
					if(arregloFunciones[x].getHora().getHh() == hh && arregloFunciones[x].getHora().getMm() == mm){
						//Esa sala ya tiene una funcion a esa hora
						cout <<"Esa sala ya esta ocupada a esa hora!"<<endl;
						system("pause");
						ocupada = true;
						break;
					}
					else{
						arregloFunciones[i].setCveFuncion(cveFuncion);
						arregloFunciones[i].setNumPeli(numPeli);
						hora.setHh(hh);
						hora.setMm(mm);
						arregloFunciones[i].setHora(hora);
						arregloFunciones[i].setSala(sala);
						i++;
						success = true;
						break;
						}
					}
					else{
						arregloFunciones[i].setCveFuncion(cveFuncion);
						arregloFunciones[i].setNumPeli(numPeli);
						hora.setHh(hh);
						hora.setMm(mm);
						arregloFunciones[i].setHora(hora);
						arregloFunciones[i].setSala(sala);
						i++;
						success = true;
						break;
					}
				}
				if(ocupada == true){
					break;
				}
			}

		}while(success == false);
	}
}

char menu(){
	system ("CLS");//Sirve para limpiar la pantalla de la consola
	char opcion;
    cout << "<----------------- Menu ----------------->"<<endl;
    cout << "A) Mostrar todos los actores registrados"<<endl;
    cout << "B) Mostrar todas las peliculas registradas"<<endl;
    cout << "C) Mostrar todas las funciones disponibles"<<endl;
    cout << "D) Consultar funciones por Hora"<<endl;
    cout << "E) Consultar funcion por clave"<<endl;
    cout << "F) Consultar peliculas por actor"<<endl;
    cout << "G) Salir"<<endl;
    cout << "Seleccion: ";
    cin >> opcion;

	if(opcion == '\0'){//Si la entrada de datos esta completamente vacia
   		menu();//vuelve a llamar al metodo menu
	}
	else{//En caso de que no este vacia
		return opcion;//Regresa la letra que el usuario ingreso
	}
}

void actores(){
	//Mostrar actores en el arregloActores con el metodo de muestra;
    for(int i = 0; i < sizeof(arregloActores)/sizeof(arregloActores[0]); i++){
		arregloActores[i].muestra();
	}
}

void peliculas(){
	//mostrar las peliculas en arregloPeliculas utilizando el metodo de muestra
    for(int i = 0; i < registrosPeliculas; i++){
        arregloPeliculas[i].muestra();
    }
}

void funciones(){

	if(arregloFunciones[0].getCveFuncion().empty()){//Revisar si el arreglo de funciones esta vacio
		ingresarFunciones();//Si esta vacio entra aqui a pedir ingresar las funciones
	}
	else{
		int i=0, numPeli, sala, hh, mm;
		string cveFuncion, nombrePeli;

		while(i < 20){//Iterar de i = 0 hasta que sea 19 o menor a 20
			cveFuncion = arregloFunciones[i].getCveFuncion();//Obtener clave de funcion
			numPeli = arregloFunciones[i].getNumPeli();//Obtener el numero de pelicula
			for(int x=0; x < 20; x++){
				if(arregloPeliculas[x].getNumPeli() == arregloFunciones[i].getNumPeli()){
					//Si el codigo numPeli se parece al codigo de pelicula
					nombrePeli = arregloPeliculas[x].getTitulo();
				}
			}
			sala = arregloFunciones[i].getSala();
			//Imprimir valores
			cout << "Funcion: " + cveFuncion << endl;
			cout << "Nombre de Pelicula: " + nombrePeli << endl;
			cout << "Sala: " << sala << endl;
			arregloFunciones[i].getHora().muestra();
			i++;
		}
	}
}

void cFuncionH(){
	if(arregloFunciones[0].getCveFuncion().empty()){//Revisar si el arreglo de Funciones tiene dato
		ingresarFunciones();//Si no tiene datos pedira que se ingresen primero las funciones y sus datos
	}
	else{
		//Declaracion de variables
		bool encontrado = false;
		int hh = 0, mm = 0;
		do{//Hara lo siguiente
			system("CLS");//Limpiar pantalla
			cout << "Hora de busqueda(hh): ";
			cin >> hh;//Leer la hora
		}while(hh < 0 || hh >23);//Hasta que se cumpla la condicion

		do{
			system("CLS");
			cout << "Minutos de busqueda(mm): ";
			cin >> mm;
		}while(mm < 0 || mm > 59);

		int numPeli;

		for(int i=0; i < sizeof(arregloFunciones)/sizeof(arregloFunciones[0]); i++){//Iterar entre arregloFunciones
			if(arregloFunciones[i].getHora().getHh() == hh && arregloFunciones[i].getHora().getMm() == mm){//Si encuentras una funcion con la hora igual a hh y los minutos iguales a mm
				numPeli = arregloFunciones[i].getNumPeli();//Obtienes el numero de pelicula
				for(int x=0; x < sizeof(arregloPeliculas)/sizeof(arregloPeliculas[0]); x++){//Iteras en arreglodePeliculas
					if(arregloPeliculas[x].getNumPeli() == numPeli){					//Si encuentras el numero de pelicula igual a el numero de pelicula de arregloPeliculas en cuestion
						cout << "Titulo: " + arregloPeliculas[x].getTitulo() << "\n";//Imprimes el titulo
						break;//Terminas iteraciones
					}
				}
				cout << "En sala #" << arregloFunciones[i].getSala() << "\n";
				encontrado = true;
			}
		}

		if(encontrado = false){//Si no se encontro se mostrara que no hay resultados
			system("CLS");
			cout << "...No se enontraron resultados..."<< endl;
		}
	}
}

void cFuncionC(){
	if(arregloFunciones[0].getCveFuncion().empty()){
		ingresarFunciones();
	}
	else{
		string cveFuncion;
		system("CLS");
		bool encontrado = false;
		while(encontrado == false){
			cout <<"Ingresa la clave de funcion a buscar:";
				cin >> cveFuncion;
			for(int x=0; x < sizeof(arregloFunciones)/sizeof(arregloFunciones[0]); x++){
				if(arregloFunciones[x].getCveFuncion() == cveFuncion){
					encontrado = true;
					//Sala, titulo, hora en la que se presenta,
					//duracion, genero y nombres de los actores
					cout << "Sala: " << arregloFunciones[x].getSala() << "\n";

					for(int u = 0; u < sizeof(arregloPeliculas)/sizeof(arregloPeliculas[0]); u++){//Iterar para buscar el titulo
						if(arregloPeliculas[u].getNumPeli() == arregloFunciones[u].getNumPeli()){//Si el numero de pelicula en arreglopeliculas se parece a el numero de pelicula del arregloFunciones
							cout << "Titulo: " + arregloPeliculas[u].getTitulo() << "\n";//Entonces imprimira el titulo desde arregloPeliculas[u]
							break;//Terminas la iteracion
						}
					}
					cout << "Hora de proyeccion: " << arregloFunciones[x].getHora().getHh() << ":" << arregloFunciones[x].getHora().getMm() << "\n";//Imprimir la hora de proyeccion
					for(int y = 0; y < sizeof(arregloPeliculas)/sizeof(arregloPeliculas[0]); y++){//Iterar para encontrar la pelicula y de ahi sacar duracion y genero
						if(arregloPeliculas[y].getNumPeli() == arregloFunciones[y].getNumPeli()){//Si numpeli de peliculas es igual a numpeli de arregloFunciones
							cout << "Duracion: " << arregloPeliculas[y].getDuracion() << " minutos.\n";//Imprimir duracion desde arregloPeliculas[y].getDuracion()
							cout << "Genero: " + arregloPeliculas[y].getGenero() << "\n";//Imprimir genero desde arregloPeliculas[y].getGenero()
							break;
						}
					}
					//Nombres de los actores
					cout << "Actores:" <<endl;
					for(int u = 0; u < sizeof(arregloPeliculas)/sizeof(arregloPeliculas[0]); u++){
						if(arregloPeliculas[u].getNumPeli() == arregloFunciones[u].getNumPeli()){
							for(int o = 0; o < arregloPeliculas[u].getCantActores(); o++){
								cout << arregloPeliculas[u].getListaActores(o).getNombre() << "\n";
							}
							break;
						}
					}

					break;
				}
			}
		}
	}
}

void cFuncionA(){
	system("CLS");//Se limpiara la pantalla
	int idBusqueda;
	bool encontrado = false;
	while(encontrado == false){
		cout <<"Ingresa el ID. del actor: ";
		cin >> idBusqueda;//Obtener el id del actor a buscar
		for(int x = 0; x < sizeof(arregloActores)/sizeof(arregloActores[0]); x++){//Iterar desde x = 0 hasta que x sea menor que el tamaño del arregloActores y luego sumar 1 a equis
			if(arregloActores[x].getId() == idBusqueda){ //Si el id que ingreso el usuario es igual al id del actor en cuestion durante la iteracion entonces entra a ejecutar el codigo dentro del if
				//Id encontrado
				cout << arregloActores[x].getNombre() <<endl;//Imprime le nombre del actor con el id especificado
				cout <<"\n";//salto de linea para dejar espacio
				for(int y = 0; y < sizeof(arregloPeliculas)/sizeof(arregloPeliculas[0]); y++){//Otra iteracion pero ahora en el arreglo de las peliculas para buscar en que peliculas actua el actor en cuestion
					for(int x = 0; x < arregloPeliculas[y].getCantActores(); x++){
						if(arregloPeliculas[y].getListaActores(x).getId() == idBusqueda){//Obtener el id de cada uno de los actores para compararlo con el id ingresado y si lo encuentra
							cout <<"Actua en " + arregloPeliculas[y].getTitulo() <<endl;//imprimir la pelicula
							cout <<"Se estreno en " << arregloPeliculas[y].getAnio() << "\n" <<endl;//Imprimir el año de estreno de la pelicula
						}
					}
				}
				encontrado = true;//Cambiar encontrado a verdadero
				break;//Terminar la iteracion
			}
		}
		if(encontrado == false){
			cout << "Actor no encontrado!"<<endl;//Si el actor no ha sido encontrao
			encontrado = true;
		}
	}

}

int main(){
	system("color 1f");//Establecer el color del fondo y de la letra del sistema color xx, en este caso es color 1f, el uno es para background y el f es para letra blanca
    cargarActores(); //Llamar metodo de carga de actores dentro del arreglo
    cargarPeliculas(); //Llamar metodo de carga de peliculas dentro del arreglo que se declaro al inicio arregloPeliculas[20]
    char opcion;
    //Menu, se mostrara hasta recibir la opcion G o si lo que se ingresa es una letra o caracter
    while(opcion != 'G'){//El menu se mostrara hasta que el usuario ingrese G
		//Recibir la opcion del menu en la variable opcion
    	opcion = menu();
    	switch(opcion){//Switch a la letra de la opcion
    		case 'A'://En cada caso la variable opcion debe ser igual a la letra entre apostrofes
    			system("CLS");
    			actores();//Llama la clase que esta en el case
    			system("pause");//Pausa la ejecucion del programa esperando que opriman una letra
    			break;//Termina el bloque de codigo
    		case 'B':
    			system("CLS");
    			peliculas();
    			system("pause");
    			break;
    		case 'C':
    		    system("CLS");
    			funciones();
				system("pause");
    			break;
    		case 'D':
    		    system("CLS");
    			cFuncionH();
				system("pause");
    			break;
    		case 'E':
    		    system("CLS");
    			cFuncionC();
				system("CLS");
    			break;
    		case 'F':
    		    system("CLS");
    			cFuncionA();
				system("pause");
    			break;
		}
	}
	return 0;
}
