#include<iostream>
#include<string>

using namespace std;

class Espressor {
public:
	const int id;
	static int nrEspressoare;
	string marca;
	int capacitateBoiler;
	bool esteElectric;
	int greutate;
	float* diferenteGreutate;

	Espressor() : id(++nrEspressoare) {
		this->marca = "Lelit";
		this->capacitateBoiler = 250;
		this->esteElectric = true;
		this->greutate = 5;
		this->diferenteGreutate = nullptr;
	}

	Espressor(string marca, int capacitateBoiler, bool esteElectric)
		: id(++nrEspressoare) {
		this->marca = marca;
		this->capacitateBoiler = capacitateBoiler;
		this->esteElectric = esteElectric;
		this->greutate = 18;
		this->diferenteGreutate = new float[1];
		this->diferenteGreutate[0] = 3.8;
	}

	Espressor(string marca, int capacitateBoiler, bool esteElectric, int greutate, float* diferenteGreutate)
		: id(++nrEspressoare) {
		this->marca = marca;
		this->capacitateBoiler = capacitateBoiler;
		this->esteElectric = esteElectric;
		this->greutate = greutate;
		this->diferenteGreutate = new float[greutate];
		for (int i = 0; i < greutate; i++) {
			this->diferenteGreutate[i] = diferenteGreutate[i];
		}
	}
};

class RasnitaCafea {
public:
	const int id;
	static int nrRasnite;
	string materialCutite;
	string tipCutite;
	bool esteElectric;
	int diametruCutite;
	float* diferenteDiametru;
	

	RasnitaCafea() : id(++nrRasnite) {
		this->materialCutite = "Lelit";
		this->tipCutite = "plate";
		this->esteElectric = true;
		this->diametruCutite = 78;
		this->diferenteDiametru = nullptr;
	}

	RasnitaCafea(string materialCutite, string tipCutite, bool esteElectric)
		: id(++nrRasnite) {
		this->materialCutite = materialCutite;
		this->tipCutite = tipCutite;
		this->esteElectric = esteElectric;
		this->diametruCutite = 78;
		this->diferenteDiametru = new float[1];
		this->diferenteDiametru[0] = 5.2;
	}
	RasnitaCafea(string materialCutite, string tipCutite, bool esteElectric, int diametruCutite, float* diferenteDiametru)
		: id(++nrRasnite) {
		this->materialCutite = materialCutite;
		this->tipCutite = tipCutite;
		this->esteElectric = esteElectric;
		this->diametruCutite = diametruCutite;
		this->diferenteDiametru = new float[diametruCutite];
		for (int i = 0; i < diametruCutite; i++) {
			this->diferenteDiametru[i] = diferenteDiametru[i];
		}
	}
};

class DistribuitorCafea {
public:
	const int id;
	static int nrDistribuioare;
	string material;
	int greutate;
	bool esteElectric;
	int diametru;
	float* diferentaDiametru;
	

	DistribuitorCafea() :id(++nrDistribuioare) {
		this->material = "Inox";
		this->greutate = 100;
		this->esteElectric = false;
		this->diametru = 57;
		this->diferentaDiametru = nullptr;
	}

	DistribuitorCafea(string material, int greutate, bool esteElectric) :id(++nrDistribuioare) {
		this->material = material;
		this->greutate = greutate;
		this->esteElectric = esteElectric;
		this->diametru = 57;
		this->diferentaDiametru = new float[1];
		this->diferentaDiametru[0] = 5;
	}

	DistribuitorCafea(string material, int greutate, bool esteElectric, int diametru, float* diferentaDiametru) :id(++nrDistribuioare) {
		this->material = material;
		this->greutate = greutate;
		this->esteElectric = esteElectric;
		this->diametru = diametru;
		this->diferentaDiametru = new float[diametru];
		for (int i = 0; i < diametru; i++) {
			this->diferentaDiametru[i] = diferentaDiametru[i];
		}
	}
};

void main() {
};