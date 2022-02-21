#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <random>
using std::cout;
using std::cin;
using std::string;
#define N 100
#define M 3
struct zmogus {
	string vardas = "", pavarde = "";
	int paz[N] = { 0 }, egz = 0, ndskc =0;
	std::vector<int> vpaz;
	double rezult = 0;
	double median = 0;
};
void ivestis(zmogus& temp);
void isvestis(zmogus& temp, bool vm);
int main() {
	zmogus a;
	zmogus* amas = new zmogus[M];
	bool vm;
	for (int i = 0; i < M; i++) {
		ivestis(amas[i]);
	}
	cout << "Galutini pazymi skaiciuoti pagal vidurki(0) ar pagal mediana(1): ";
	cin >> vm;
	cout << std::endl<< "|" << std::left << std::setw(20) << "Pavarde" << "|" << std::left << std::setw(20) << "Vardas" << "|" << std::left << std::setw(20) << "Galutinis (vid.)/Galutinis (med.)";
	cout << std::endl << "---------------------------------------------------" << std::endl;
	for (int i = 0; i < M; i++) {
		isvestis(amas[i], vm);
	}
	delete[] amas;
	system("pause");
}
void ivestis(zmogus& temp) {
	int a = 0;
	int check = 1;
	bool rd;
	int temprando;
	temp.vpaz.reserve(100);
	cout << "Iveskite varda: ";
	cin >> temp.vardas;
	cout << "Iveskite pavarde: ";
	cin >> temp.pavarde;
	cout << "Ar norite automatiskai sugeneruoti pazymius(1 taip, 0 ne)? ";
	cin >> rd;
	if (rd) {
		std::random_device rd;
		std::mt19937 mt(rd());
		std::uniform_int_distribution<int> dist(0, 99);
		a = dist(mt);
		std::uniform_int_distribution<int> dist2(1, 10);
		for (int i = 0; i < a; i++) {
			temprando = dist2(mt);
			temp.vpaz.push_back(temprando);
			temp.rezult += temprando;
		}
		temprando = dist2(mt);
		temp.egz = temprando;
		temp.rezult += temp.egz;
		temp.vpaz.push_back(temp.egz);
	}
	else {
		while (true) {
			cout << "Iveskite " << temp.vpaz.size() + 1 << "-a(-i) pazymi(jei norite baigti, spauskite 0):";
			cin >> check;
			if (check == 0)
				break;
			else {
				temp.vpaz.push_back(check);
				temp.rezult += check;
			}
		}
		cout << "Iveskite egzamino ivertinima: ";
		cin >> temp.egz;
		temp.rezult += temp.egz;
		temp.vpaz.push_back(temp.egz);
	}
	
	a = temp.vpaz.size();
	temp.ndskc = a;

	std::sort (temp.vpaz.begin(), temp.vpaz.end());
	//for (auto it = vekpaz.begin(); it != vekpaz.end(); ++it)
	//	cout << " " << *it;
	if (a % 2 != 0)
		temp.median = temp.vpaz[(a / 2)];
	else
		temp.median = (temp.vpaz[(a / 2)-1] + temp.vpaz[a / 2]) / 2.0;
}
void isvestis(zmogus& temp, bool vm) {
	cout << "|" << std::left << std::setw(20) << temp.vardas << "|" << std::left <<
		std::setw(20) << temp.pavarde << std::right;
	if (vm) {
		cout << "|" << std::left << std::setw(20) << temp.median << "|" << std::endl;
	}
	else
		cout << "|" << std::left << std::setw(20) << temp.rezult/(temp.ndskc)<< std::endl;
}