#include <iostream>
#include <conio.h>
#include "Actor.h"
#include <string>
#include "Funcion.h"

using namespace std;

class Pelicula{
    public:
    Pelicula(){
        numPeli = 0;
        anio = 0;
        duracion = 0;
        cantActores = 0;
        titulo = "";
        genero = "";
    }

    Pelicula(int numPeli, int anio, int duracion, string titulo, string genero){
        numPeli = 0;
        anio = 0;
        duracion = 0;
        titulo = "";
        genero = "";
        cantActores = sizeof(listaActores)/sizeof(listaActores[0]);
    }

    //Gettes, metodos de acceso
    int getNumPeli(){
        return numPeli;
    }

    int getAnio(){
        return anio;
    }

    int getDuracion(){
        return duracion;
    }

    int getCantActores(){
        return cantActores;
    }

    string getTitulo(){
        return titulo;
    }

    string getGenero(){
        return genero;
    }

    Actor getListaActores(int indexIn){
        return listaActores[indexIn];
    }
    //Settes, metodos de modificacion
    void setNumPeli(int numPeliIn){
        numPeli = numPeliIn;
    }

    void setAnio(int anioIn){
        anio = anioIn;
    }

    void setDuracion(int duracionIn){
        duracion = duracionIn;
    }

    void setTitulo(string tituloIn){
        titulo = tituloIn;
    }

    void setGenero(string generoIn){
        genero = generoIn;
    }

    bool setActor(Actor actor){
        bool existe;
        if(cantActores >= 10){
            //No se puede agregar
            return false;
        }
        else{
            //Buscar si actor esta duplicado
            for(int x = 0; x < sizeof(listaActores)/sizeof(listaActores[0]); x++){
                if(listaActores[x].getId() == actor.getId()){
                    //Si existe registrado
                    existe = true;
                }
            }
            if(existe == true){
                return false;
            }
            else{
                listaActores[cantActores] = actor;
                cantActores++;
                return true;
            }
        }
        
    }

    void muestra(){
        cout << "Numero de pelicula: " << numPeli <<endl;
		cout << "Titulo: " + titulo << endl;
		cout << "Anho de estreno: " << anio << endl;
		cout << "Duracion total: " << duracion << endl;
		cout << "Genero: " + genero << endl;
        cout << "Actores:" << endl;
		for(int x = 0; x < cantActores; x++){
            cout << listaActores[x].getNombre() << endl;
        }
        cout <<"\n"<<endl;
    }

    private:
    int numPeli;
    int anio;
    int duracion;
    int cantActores;
    string titulo;
    string genero;
    Actor listaActores[10];
};
