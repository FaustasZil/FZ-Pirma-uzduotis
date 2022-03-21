#include "headeris.h"
using std::cout;
using std::cin;
using std::string;

int main() {
	string laikinas = "";
	int M, N;
	int vm;
	std::vector<string> ndskcc;
	std::vector<zmogus> amas;
	fgeneravimas(5, 10000);
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
		std::stringstream bufferis;
		try {
			std::ifstream open_f("kursiokai.txt");
			if (open_f) {
				bufferis << open_f.rdbuf();
				open_f.close();
			}
			else
				throw 404;
		}
		catch (...) {
			cout << "Pasirinkto duomenu failo nera. Programa uzbaigta";
			return 0;
		}
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
	std::sort(amas.begin(), amas.end(), sortf);
	if (N == 1) {
		fisvestis(amas, vm);
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
