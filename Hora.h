#include <iostream>

using namespace std;

class Hora{
	private:
		int hh;
		int mm;

	public:
		Hora(){
			hh = 0;
			mm = 0;
		}

		Hora(int h, int m){
			hh = h;
			mm = m;
		}

        //Gettes, Metodos de acceso
		int getHh(){
			return hh;
		}

		int getMm(){
			return mm;
		}

		//Settes, Metodos de modificacion
		void setHh(int h){
			hh = h;
		}

		void setMm(int m){
			mm = m;
		}

		//Muestra
		void muestra(){
			cout << hh << ":" << mm <<endl;
		}
};
