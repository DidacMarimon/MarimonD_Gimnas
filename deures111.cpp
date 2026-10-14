#include <iostream>
#include <string>
using namespace std;

class tarifa {
public:

	string nomt;
	double preu; 
};

class soci {
public:

	string noms; 
	int IDsosi; 
	tarifa tarifa; 

	virtual double calcularCuota() {

		return tarifa.preu;
	}
};

class sosiVIP : public soci {
public: 

	double descompte; 

	double calcularCuota() override {

		return soci::calcularCuota() * (1 - descompte / 100); 
	}
};

int main() {

	soci soci1; 

	soci1.noms = "Didac";
	soci1.IDsosi = 13556; 
	soci1.tarifa.nomt = "Premium"; 
	soci1.tarifa.preu = 50;

	sosiVIP vip1; 

	vip1.noms = "Erika"; 
	vip1.IDsosi = 4354; 
	vip1.tarifa.nomt = "VIP";
	vip1.tarifa.preu = 50; 
	vip1.descompte = 10; 

	cout << "SOCI NORMAL" << endl; 
	cout << "Nom: " << soci1.noms << endl;
	cout << "Cuota: " << soci1.calcularCuota() << endl << endl;

	cout << "SOCI VIP" << endl;
	cout << "Nom: " << vip1.noms << endl;
	cout << "Cuota: " << vip1.calcularCuota() << endl;
}



	



