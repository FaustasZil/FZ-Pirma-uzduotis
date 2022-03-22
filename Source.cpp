#include "headeris.h"
using std::cout;
using std::cin;
using std::string;

int main() {
	string laikinas = "";
	int M, N;
	int vm =1;
	std::vector<string> ndskcc;
	std::vector<zmogus> amas;
	std::vector<int> dydziai = { 1000, 10000, 100000, 1000000, 10000000};
	while (true) {
		cout << "Ar norite sugeneruoti failus(1000, 10000, 100000, 1000000, 10000000)?(1 taip, 0 ne)? ";
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
	if (N==1) {
		for (auto i : dydziai) {
			cout << "Generuojama " << i << std::endl;
			fgeneravimas(5, i);
		}	
	}
	while (true) {
		cout << "Ar norite praeiti situos failus(1000, 10000, 100000, 1000000, 10000000)?(1 taip, 0 ne)? ";
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
	if (N == 1) {
		std::vector<zmogus> nelaimingi;
		for (auto i : dydziai) {
			cout << "Skaiciuojama " << i << std::endl;
			nelaimingi.clear();
			amas.clear();
			ndskcc.clear();
			apskaiciavimas(amas, ndskcc, i);
			nelaimingi = padalinimas(amas, vm);
			cout << amas.size() << " " << nelaimingi.size() << std::endl;
			std::sort(amas.begin(), amas.end(), sortf);
			std::sort(nelaimingi.begin(), nelaimingi.end(), sortf);
			fisvestis(amas, vm, "laimingi.txt");
			fisvestis(nelaimingi, vm, "nelaimingi.txt");
			system("pause");
		}
		return 0;
	}
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
	//kuri faila pravesti
	if (N == 1) {
		apskaiciavimas(amas, ndskcc, dydziai[0]);
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
	std::sort(amas.begin(), amas.end(), sortf);
	string output = "output.txt";
	if (N == 1) {
		fisvestis(amas, vm, output);
	}
	else {
		if (vm == 1) {
			cout << std::endl << "|" << std::left << std::setw(20) << "Vardas" << "|" << std::left << std::setw(20) << "Pavarde" << "|" << std::left << std::setw(20) << "Galutinis (med.)" << "|";
			cout << std::endl << "----------------------------------------------------------------" << std::endl;
		}
		else {
			cout << std::endl << "|" << std::left << std::setw(20) << "Vardas" << "|" << std::left << std::setw(20) << "Pavarde" << "|" << std::left << std::setw(20) << "Galutinis (vid.)" << "|";
			cout << std::endl << "----------------------------------------------------------------" << std::endl;
		}
		for (int i = 0; i < M; i++) {
			isvestis(amas[i], vm);
		}
	}
	system("pause");
}
