#include <string>
#include <iostream>
#include "Hora.h"

using namespace std;

class Funcion{
    public:
    Funcion(){
        numPeli = 0;
        sala = 0;
        cveFuncion = "";
    }

    Funcion(int numPeli, int sala, string cveFuncion){
        numPeli = numPeli;
        sala = sala;
        cveFuncion = cveFuncion;
    }

    //Gettes, Metodos de acceso
    int getNumPeli(){
        return numPeli;
    }

    int getSala(){
        return sala;
    }

    string getCveFuncion(){
        return cveFuncion;
    }

    Hora getHora(){
        return hora;
    }

    //Settes, Metodos de modificacion
    void setNumPeli(int numPeliIn){
        numPeli = numPeliIn;
    }

    void setSala(int salaIn){
        sala = salaIn;
    }

    void setCveFuncion(string cveFuncionIn){
        cveFuncion = cveFuncionIn;
    }

    void setHora(Hora horaIn){
        hora.setHh(horaIn.getHh());
        hora.setMm(horaIn.getMm());
    }

    void muestra(){
        //Mostrar
        cout << "Clave: " + cveFuncion << endl;
		cout << "Numero de pelicula: " << numPeli << endl;
		cout << "Sala: " << sala << endl;
        hora.muestra();
    }

    private:
    int numPeli;
    int sala;
    string cveFuncion;
    Hora hora;
};
