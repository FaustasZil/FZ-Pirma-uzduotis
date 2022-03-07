#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <random>
#include <fstream>
#include <sstream>
using std::cout;
using std::cin;
using std::string;
struct zmogus {
	string vardas = "", pavarde = "";
	int egz = 0, ndskc =0;
	std::vector<int> vpaz;
	double rezult = 0;
	double median = 0;
};
void ivestis(zmogus& temp);
void isvestis(zmogus& temp, int vm);
void fisvestis(std::vector <zmogus> temp, int vm);
int main() {
	string laikinas = "";
	int M, N;
	int vm;
	std::vector<string> ndskcc;
	std::vector<zmogus> amas;
	while (true) {
		cout << "Ar norite pazymius ivesti is failo?(1 taip, 0 ne)? ";
		std::getline(cin, laikinas);
		try {
			N = stoi(laikinas);
			if (N != 0 && N != 1) {
				cout << "Ivestas ne tas pasirinkimas" << std::endl;
				continue;
			}
			break;
		}
		catch (...) {
			cout << "Ivestas ne tas pasirinkimas" << std::endl;
		}
	}
	if (N == 1) {
		//std::vector<string> eilutes;
		//string eil = "";
		std::stringstream bufferis;
		std::ifstream open_f("kursiokai.txt");
		bufferis << open_f.rdbuf();
		open_f.close();
		string temp;
		zmogus ztemp;
		int itemp;
		bufferis >> temp;
		bufferis >> temp;
		while (true) {
			bufferis >> temp;
			if (temp == "Egz.") 
				break;
			ndskcc.push_back(temp);
		}
		while (bufferis) {
			if (!bufferis.eof()) {
				amas.push_back(ztemp);
				//std::getline(bufferis, eil);
				//eilutes.push_back(eil);
				bufferis >> amas[amas.size() - 1].vardas;
				bufferis >> amas[amas.size() - 1].pavarde;
				for (int i = 0; i < ndskcc.size(); i++) {
					bufferis >> itemp;
					amas[amas.size() - 1].vpaz.push_back(itemp);
					amas[amas.size() - 1].rezult += itemp;
				}
				bufferis >> amas[amas.size() - 1].egz;
				amas[amas.size() - 1].ndskc = ndskcc.size();

				std::sort(amas[amas.size() - 1].vpaz.begin(), amas[amas.size() - 1].vpaz.end());
				if (ndskcc.size() % 2 != 0)
					amas[amas.size() - 1].median = amas[amas.size() - 1].vpaz[(ndskcc.size() / 2)];
				else
					amas[amas.size() - 1].median = (amas[amas.size() - 1].vpaz[(ndskcc.size() / 2) - 1] + amas[amas.size() - 1].vpaz[ndskcc.size() / 2]) / 2.0;
			}
			else break;
		}
		//amas.resize(eilutes.size());
		//std::vector<string> ndskc;
		//for (int i = 0; i < eilutes.size(); i++) {
		//	bufferis >> amas[i].vardas;
		//	bufferis >> amas[i].pavarde;
		//
		//}
	}
	else {
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
		amas.resize(M);
		for (int i = 0; i < M; i++) {
			ivestis(amas[i]);
		}
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
	cout << std::endl<< "|" << std::left << std::setw(20) << "Pavarde" << "|" << std::left << std::setw(20) << "Vardas" << "|" << std::left << std::setw(20) << "Galutinis (vid.)/Galutinis (med.)";
	cout << std::endl << "---------------------------------------------------" << std::endl;
	if (N == 1) {
		fisvestis(amas, vm);
	}
	else {
		for (int i = 0; i < M; i++) {
			isvestis(amas[i], vm);
		}
	}
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
	if (rd==1) {
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
			temp.vpaz.push_back(temprando);
			temp.rezult += temprando;
		}
		temprando = dist(mt);
		temp.egz = temprando;
	}
	else {
		while (true) {
			cout << "Iveskite " << temp.vpaz.size() + 1 << "-a(-i) pazymi(jei norite baigti, spauskite 0):";
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
				temp.vpaz.push_back(check);
				temp.rezult += check;
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
	
	a = temp.vpaz.size();
	temp.ndskc = a;

	std::sort(temp.vpaz.begin(), temp.vpaz.end());
	if (a % 2 != 0)
		temp.median = temp.vpaz[(a / 2)];
	else
		temp.median = (temp.vpaz[(a / 2)-1] + temp.vpaz[a / 2]) / 2.0;
}
void isvestis(zmogus& temp, int vm) {
	cout << "|" << std::left << std::setw(20) << temp.vardas << "|" << std::left <<
		std::setw(20) << temp.pavarde << std::right;
	if (vm==1) {
		cout << "|" << std::left << std::setw(20) << temp.median*0.4+temp.egz*0.6 << "|" << std::endl;
	}
	else
		cout << "|" << std::left << std::setw(20) << (temp.rezult/(temp.ndskc))*0.4+temp.egz*0.6<< std::endl;
}
void fisvestis(std::vector <zmogus> temp, int vm) {
	std::stringstream rasbufferis;
	if (vm == 1) {
		for (int i = 0; i < temp.size(); i++) {
			rasbufferis << "|" << std::left << std::setw(20) << temp[i].vardas << "|" << std::left <<
				std::setw(20) << temp[i].pavarde << std::right << "|" << std::left << std::setw(20) << temp[i].median * 0.4 + temp[i].egz * 0.6 << "|" << std::endl;
		}
	}
	else {
		for (int i = 0; i < temp.size(); i++) {
			rasbufferis << "|" << std::left << std::setw(20) << temp[i].vardas << "|" << std::left <<
				std::setw(20) << temp[i].pavarde << std::right << "|" << std::left << std::setw(20) << (temp[i].rezult / (temp[i].ndskc)) * 0.4 + temp[i].egz * 0.6 << "|" << std::endl;
		}
	}
	cout << rasbufferis.str();
	rasbufferis.clear();
}