#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <vector>
using std::cout;
using std::cin;
using std::string;
#define N 100
#define M 3
struct zmogus {
	string vardas = "", pavarde = "";
	int paz[N] = { 0 }, egz = 0, ndskc =0;
	double rezult = 0;
	double median = 0;
};
void ivestis(zmogus& temp);
void isvestis(zmogus& temp);
int main() {
	zmogus a;
	zmogus* amas = new zmogus[M];
	for (int i = 0; i < M; i++) {
		ivestis(amas[i]);
	}
	cout << "|" << std::left << std::setw(20) << "Pavarde" << "|" << std::left << std::setw(20) << "Vardas" << "|" << std::left << std::setw(20) << "Galutinis (vid.)" << "|" << std::left << std::setw(20) << "Galutinis (med.)";
	cout << std::endl << "---------------------------------------------------" << std::endl;
	for (int i = 0; i < M; i++) {
		isvestis(amas[i]);
	}
	delete[] amas;
	system("pause");
}
void ivestis(zmogus& temp) {
	int a = 0;
	int check = 1;
	cout << "Iveskite varda: ";
	cin >> temp.vardas;
	cout << "Iveskite pavarde: ";
	cin >> temp.pavarde;
	while (true) {
		cout << "Iveskite " << a+1 << "-a(-i) pazymi(jei norite baigti, spauskite 0):";
		cin >> check;
		if (check == 0)
			break;
		else {
			temp.paz[a] = check;
			temp.rezult += temp.paz[a];
			a++;
		}
	}
	cout << "Iveskite egzamino ivertinima: ";
	cin >> temp.egz;
	temp.rezult += temp.egz;
	temp.paz[a] = temp.egz;
	a++;
	temp.ndskc = a;

	std::vector<int> vekpaz(temp.paz, temp.paz + a);
	std::sort (vekpaz.begin(), vekpaz.end());
	for (auto it = vekpaz.begin(); it != vekpaz.end(); ++it)
		cout << " " << *it;
	if (a % 2 != 0)
		temp.median = vekpaz[(a / 2)];
	else
		temp.median = (vekpaz[(a / 2)-1] + vekpaz[a / 2]) / 2.0;
}
void isvestis(zmogus& temp) {
	cout << "|" << std::left << std::setw(20) << temp.vardas << "|" << std::left <<
		std::setw(20) << temp.pavarde << std::right;
	//for (int i = 0; i < 3; i++)
	//	cout << "|" << std::setw(5) << temp.paz[i];
	cout << "|" << std::left << std::setw(20) << temp.rezult/(temp.ndskc);
	cout << "|" << std::left << std::setw(20) << temp.median << "|" << std::endl;
}