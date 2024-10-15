#include<iostream>
using namespace std;

class Robot {
public:
	string nume;
	int versiuneSoft;
	float memorie;
	bool esteBiped;
	char* culoare;

	//destructor nu are parametri, are acelasi nume ca si clasa, nu returneaza nimic
	//destructorul dezaloca memoria alocata pentru pointeri in constructori (char*)

	~Robot() {
		if (this->culoare != NULL) {
			delete[]this->culoare;
		}
	}

	//constructor fara parametri
	//constructorul are intotdeauna numele clasei
	Robot() {
		this->nume = "Tesla";
		this->memorie = 78.9;
		this->versiuneSoft = 2;
		this->esteBiped = true;
		this->culoare = new char[strlen("Alb") + 1];
		strcpy_s(this->culoare, strlen("Alb") + 1, "Alb");
	}

	//constructor cu un parametru
	Robot(string nume) {
		this->nume = nume;
		this->memorie = 78.9;
		this->versiuneSoft = 2;
		this->esteBiped = true;
		this->culoare = new char[strlen("Alb") + 1];
		strcpy_s(this->culoare, strlen("Alb") + 1, "Alb");
	}

	//constructor cu un parametru
	Robot(int versSoft) {
		this->nume = "Tesla";
		this->memorie = 78.9;
		this->versiuneSoft = versSoft;
		this->esteBiped = true;
		this->culoare = new char[strlen("Alb") + 1];
		strcpy_s(this->culoare, strlen("Alb") + 1, "Alb");
	}

	//constructor cu mai multi parametri
	Robot(string nume, int versiuneSoft, float memorie, bool esteBiped, const char* culoare) {
		this->nume = nume;
		this->memorie = memorie;
		this->versiuneSoft = versiuneSoft;
		this->esteBiped = esteBiped;
		this->culoare = new char[strlen(culoare) + 1];
		strcpy_s(this->culoare, strlen(culoare) + 1, culoare);
	}
	//metoda
	void afisare() { //un robot;
		cout << "Nume:" << this->nume << endl; // -> = dereferentiere + aacesare (* + .)
		cout << "Soft:" << this->versiuneSoft << endl;
		cout << "Memorie:" << this->memorie << endl;
		cout << "Culoare:" << this->culoare << endl;
		cout << "Este biped:" << (this->esteBiped ? "DA" : "NU") << endl;

	}
};

void main() {
	//obiect
	Robot robot1;
	robot1.afisare();

	Robot robot2("Marcel");
	robot2.afisare();

	Robot robot3(4);
	robot3.afisare();

	Robot robot4("Cornel", 5, 56, false, "Verde");
	robot4.afisare();

	Robot* pointer;
	pointer = new Robot("Tembel");
	delete pointer;
}