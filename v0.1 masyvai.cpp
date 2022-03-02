#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <random>
using std::cout;
using std::cin;
using std::string;
struct zmogus {
	string vardas = "", pavarde = "";
	int* paz = new int[100], egz = 0, ndskc = 0;
	double rezult = 0;
	double median = 0;
};
void ivestis(zmogus& temp);
void isvestis(zmogus& temp, int vm);
int main() {
	string laikinas = "";
	int M;
	while (true) {
		cout << "Iveskite zmoniu kieki: ";
		try {
			std::getline(cin, laikinas);
			M = stoi(laikinas);
			break;
		}
		catch (...) {
			cout << "Neteisingas kiekis" << std::endl;
		}
	}
	zmogus* amas = new zmogus[M];
	int vm;
	for (int i = 0; i < M; i++) {
		ivestis(amas[i]);
	}
	while (true) {
		cout << "Galutini pazymi skaiciuoti pagal vidurki(0) ar pagal mediana(1): ";
		std::getline(cin, laikinas);
		try {
			vm = stoi(laikinas);
			if (vm != 0 && vm != 1) {
				cout << "Ivestas ne tas pasirinkimas" << std::endl;
				continue;
			}
			break;
		}
		catch (...) {
			cout << "Ivestas ne tas pasirinkimas" << std::endl;
		}
	}
	cout << std::endl << "|" << std::left << std::setw(20) << "Pavarde" << "|" << std::left << std::setw(20) << "Vardas" << "|" << std::left << std::setw(20) << "Galutinis (vid.)/Galutinis (med.)";
	cout << std::endl << "---------------------------------------------------" << std::endl;
	for (int i = 0; i < M; i++) {
		isvestis(amas[i], vm);
	}
	delete[] amas;
	system("pause");
}
void ivestis(zmogus& temp) {
	int a = 0;
	string laikinas;
	int check = 1;
	int rd;
	int temprando;
	cout << "Iveskite varda: ";
	cin >> temp.vardas;
	cout << "Iveskite pavarde: ";
	cin >> temp.pavarde;
	std::getline(cin, laikinas);
	while (true) {
		cout << "Ar norite automatiskai sugeneruoti pazymius(1 taip, 0 ne)? ";
		std::getline(cin, laikinas);
		try {
			rd = stoi(laikinas);
			if (rd != 0 && rd != 1) {
				cout << "Ivestas ne tas pasirinkimas" << std::endl;
				continue;
			}
			break;
		}
		catch (...) {
			cout << "Ivestas ne tas pasirinkimas" << std::endl;
		}
	}
	if (rd == 1) {
		std::random_device rd;
		std::mt19937 mt(rd());
		while (true) {
			cout << "Kiek pazymiu sugeneruoti? ";
			try {
				std::getline(cin, laikinas);
				a = stoi(laikinas);
				break;
			}
			catch (...) {
				cout << "Neteisingas kiekis" << std::endl;
			}
		}
		std::uniform_int_distribution<int> dist(1, 10);
		for (int i = 0; i < a; i++) {
			temprando = dist(mt);
			temp.paz[i] = temprando;
			temp.rezult += temprando;
		}
		temprando = dist(mt);
		temp.egz = temprando;
	}
	else {
		while (true) {
			cout << "Iveskite " << a + 1 << "-a(-i) pazymi(jei norite baigti, spauskite 0):";
			try {
				std::getline(cin, laikinas);
				check = stoi(laikinas);
			}
			catch (...) {
				cout << "Ivestas ne tas pasirinkimas" << std::endl;
				continue;
			}
			if (check == 0)
				break;
			else if (check < 0 || check >10) {
				cout << "Ivestas ne tas pasirinkimas" << std::endl;
				continue;
			}
			else {
				temp.paz[a] = check;
				temp.rezult += check;
				a++;
			}
		}
		while (true) {
			cout << "Iveskite egzamino ivertinima: ";
			try {
				std::getline(cin, laikinas);
				temp.egz = stoi(laikinas);
				if (temp.egz <= 0 || temp.egz > 10) {
					cout << "Ivestas ne tas pasirinkimas" << std::endl;
					continue;
				}
				break;
			}
			catch (...) {
				cout << "Ivestas ne tas pasirinkimas" << std::endl;
			}
		}
	}

	temp.ndskc = a;

	std::vector<int> tempvek(temp.paz, temp.paz + a);
	std::sort(tempvek.begin(), tempvek.end());
	if (a % 2 != 0)
		temp.median = tempvek[(a / 2)];
	else
		temp.median = (tempvek[(a / 2) - 1] + tempvek[a / 2]) / 2.0;
}
void isvestis(zmogus& temp, int vm) {
	cout << "|" << std::left << std::setw(20) << temp.vardas << "|" << std::left <<
		std::setw(20) << temp.pavarde << std::right;
	if (vm == 1) {
		cout << "|" << std::left << std::setw(20) << temp.median * 0.4 + temp.egz * 0.6 << "|" << std::endl;
	}
	else
		cout << "|" << std::left << std::setw(20) << (temp.rezult / (temp.ndskc)) * 0.4 + temp.egz * 0.6 << std::endl;
}