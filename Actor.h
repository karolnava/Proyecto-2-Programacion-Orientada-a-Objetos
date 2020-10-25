#include <iostream>
#include <string>

using namespace std;

class Actor{
    public:
    Actor(){
        id=0;
        nombre = "";
    }

    Actor(int idIn, string nombreIn){
        id = idIn;
        nombre = nombreIn;
    }

    //Gettes, Metodos de acceso
    int getId(){
		return id;
	}

	string getNombre(){
		return nombre;
	}

	//Settes, Metodos de modificacion
	void setId(int idIn){
    	id = idIn;
	}

	void setNombre(string nombreIn){
        nombre = nombreIn;
	}

    void muestra(){
        cout << "Id. de actor: " << id << endl;
        cout << "Nombre del actor: " + nombre << "\n" << endl;
    }

    private:
    int id;
    string nombre;
};
