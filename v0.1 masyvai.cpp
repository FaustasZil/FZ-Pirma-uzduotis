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
void isvestis(zmogus& temp, bool vm);
int main() {
	int M;
	cout << "Iveskite zmoniu kieksi: ";
	cin >> M;
	zmogus* amas = new zmogus[M];
	bool vm;
	for (int i = 0; i < M; i++) {
		ivestis(amas[i]);
	}
	cout << "Galutini pazymi skaiciuoti pagal vidurki(0) ar pagal mediana(1): ";
	cin >> vm;
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
	int check = 1;
	bool rd;
	int temprando;
	cout << "Iveskite varda: ";
	cin >> temp.vardas;
	cout << "Iveskite pavarde: ";
	cin >> temp.pavarde;
	cout << "Ar norite automatiskai sugeneruoti pazymius(1 taip, 0 ne)? ";
	cin >> rd;
	if (rd) {
		std::random_device rd;
		std::mt19937 mt(rd());
		cout << "Kiek pazymiu sugeneruoti? ";
		cin >> a;
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
			cin >> check;
			if (check == 0)
				break;
			else {
				temp.paz[a] = check;
				temp.rezult += check;
				a++;
			}
		}
		cout << "Iveskite egzamino ivertinima: ";
		cin >> temp.egz;
	}

	temp.ndskc = a;

	std::vector<int> tempvek(temp.paz, temp.paz + a);
	std::sort(tempvek.begin(), tempvek.end());
	if (a % 2 != 0)
		temp.median = tempvek[(a / 2)];
	else
		temp.median = (tempvek[(a / 2) - 1] + tempvek[a / 2]) / 2.0;
}
void isvestis(zmogus& temp, bool vm) {
	cout << "|" << std::left << std::setw(20) << temp.vardas << "|" << std::left <<
		std::setw(20) << temp.pavarde << std::right;
	if (vm) {
		cout << "|" << std::left << std::setw(20) << temp.median << "|" << std::endl;
	}
	else
		cout << "|" << std::left << std::setw(20) << (temp.rezult / (temp.ndskc)) * 0.4 + temp.egz * 0.6 << std::endl;
}
