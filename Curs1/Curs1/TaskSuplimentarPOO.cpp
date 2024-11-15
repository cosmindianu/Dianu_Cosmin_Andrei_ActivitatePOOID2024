#include <iostream>
#include <string>
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

    static int calculeazaConsumApa(int capacitateBoiler, int numarCafele) {
        return (capacitateBoiler * numarCafele) / 1000; 
    }
};

int Espressor::nrEspressoare = 0;

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

    static float calculeazaTimpMacinare(int diametruCutite, int gramaj) {
        return (gramaj * 0.1f) / diametruCutite;
    }
};

int RasnitaCafea::nrRasnite = 0;

class DistribuitorCafea {
public:
    const int id;
    static int nrDistribuioare;
    string material;
    int greutate;
    bool esteElectric;
    int diametru;
    float* diferentaDiametru;

    DistribuitorCafea() : id(++nrDistribuioare) {
        this->material = "Inox";
        this->greutate = 100;
        this->esteElectric = false;
        this->diametru = 57;
        this->diferentaDiametru = nullptr;
    }

    DistribuitorCafea(string material, int greutate, bool esteElectric)
        : id(++nrDistribuioare) {
        this->material = material;
        this->greutate = greutate;
        this->esteElectric = esteElectric;
        this->diametru = 57;
        this->diferentaDiametru = new float[1];
        this->diferentaDiametru[0] = 5;
    }

    DistribuitorCafea(string material, int greutate, bool esteElectric, int diametru, float* diferentaDiametru)
        : id(++nrDistribuioare) {
        this->material = material;
        this->greutate = greutate;
        this->esteElectric = esteElectric;
        this->diametru = diametru;
        this->diferentaDiametru = new float[diametru];
        for (int i = 0; i < diametru; i++) {
            this->diferentaDiametru[i] = diferentaDiametru[i];
        }
    }

    static float calculeazaVolumDistribuit(int diametru, int greutate) {
        return (3.1415f * diametru * diametru * greutate) / 4000;
    }
};

int DistribuitorCafea::nrDistribuioare = 0;

int main() {

    int apaConsumata = Espressor::calculeazaConsumApa(250, 10);
    cout << "Apa consumata pentru 10 cafele: " << apaConsumata << " litri" << endl;
    
    float timpMacinare = RasnitaCafea::calculeazaTimpMacinare(78, 30);
    cout << "Timp macinare pentru 30g cafea: " << timpMacinare << " secunde" << endl;
    
    float volumDistribuit = DistribuitorCafea::calculeazaVolumDistribuit(57, 100);
    cout << "Volum distribuit: " << volumDistribuit << " cm^3" << endl; 

    Espressor e1;
    Espressor e2("Breville", 500, true);
    float greutatiEspressor[] = { 1.5f, 2.0f, 2.5f };
    Espressor e3("Delonghi", 300, false, 3, greutatiEspressor);

    cout << "Espressor 1: Marca = " << e1.marca << ", Capacitate = " << e1.capacitateBoiler << "ml, Electric = " << (e1.esteElectric ? "Da" : "Nu") << endl;
    cout << "Espressor 2: Marca = " << e2.marca << ", Capacitate = " << e2.capacitateBoiler << "ml, Electric = " << (e2.esteElectric ? "Da" : "Nu") << endl;
    cout << "Espressor 3: Marca = " << e3.marca << ", Capacitate = " << e3.capacitateBoiler << "ml, Electric = " << (e3.esteElectric ? "Da" : "Nu") << endl;

    RasnitaCafea r1;
    RasnitaCafea r2("Ceramic", "conic", true);
    float diametreRasnita[] = { 4.5f, 5.0f, 6.0f };
    RasnitaCafea r3("Metal", "flat", false, 3, diametreRasnita);

    cout << "Rasnita 1: Material = " << r1.materialCutite << ", Tip = " << r1.tipCutite << ", Electric = " << (r1.esteElectric ? "Da" : "Nu") << endl;
    cout << "Rasnita 2: Material = " << r2.materialCutite << ", Tip = " << r2.tipCutite << ", Electric = " << (r2.esteElectric ? "Da" : "Nu") << endl;
    cout << "Rasnita 3: Material = " << r3.materialCutite << ", Tip = " << r3.tipCutite << ", Electric = " << (r3.esteElectric ? "Da" : "Nu") << endl;

    DistribuitorCafea d1;
    DistribuitorCafea d2("Aluminiu", 120, false);
    float diametreDistribuitor[] = { 2.5f, 3.0f, 3.5f };
    DistribuitorCafea d3("Plastic", 90, true, 3, diametreDistribuitor);

    cout << "Distribuitor 1: Material = " << d1.material << ", Greutate = " << d1.greutate << "g, Electric = " << (d1.esteElectric ? "Da" : "Nu") << endl;
    cout << "Distribuitor 2: Material = " << d2.material << ", Greutate = " << d2.greutate << "g, Electric = " << (d2.esteElectric ? "Da" : "Nu") << endl;
    cout << "Distribuitor 3: Material = " << d3.material << ", Greutate = " << d3.greutate << "g, Electric = " << (d3.esteElectric ? "Da" : "Nu") << endl;

    return 0;
}
