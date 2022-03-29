#include "headerlist.h"
using std::cout;
using std::cin;
using std::string;
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
		temp.median = (temp.vpaz[(a / 2) - 1] + temp.vpaz[a / 2]) / 2.0;
}
void isvestis(zmogus& temp, int vm) {
	cout << "|" << std::left << std::setw(20) << temp.vardas << "|" << std::left <<
		std::setw(20) << temp.pavarde << std::right;
	if (vm == 1) {
		cout << "|" << std::left << std::setw(20) << temp.median * 0.4 + temp.egz * 0.6 << "|" << std::endl;
	}
	else
		cout << "|" << std::left << std::setw(20) << (temp.rezult / (temp.ndskc)) * 0.4 + temp.egz * 0.6 << "|" << std::endl;
}
void fisvestis(std::list <zmogus> temp, int vm, string vardas) {
	std::ofstream open_f(vardas);
	open_f << std::endl << "|" << std::left << std::setw(20) << "Vardas" << "|" << std::left << std::setw(20) << "Pavarde" << "|";
	std::stringstream rasbufferis;
	if (vm == 1) {
		open_f << std::left << std::setw(20) << "Galutinis (med.)" << "|";
		open_f << std::endl << "----------------------------------------------------------------" << std::endl;
		for (auto i : temp) {
			rasbufferis << "|" << std::left << std::setw(20) << i.vardas << "|" << std::left <<
				std::setw(20) << i.pavarde << std::right << "|" << std::left << std::setw(20) << i.median * 0.4 + i.egz * 0.6 << "|" << std::endl;
		}
	}
	else {
		open_f << std::left << std::setw(20) << "Galutinis (vid.)" << "|";
		open_f << std::endl << "----------------------------------------------------------------" << std::endl;
		for (auto i : temp) {
			rasbufferis << "|" << std::left << std::setw(20) << i.vardas << "|" << std::left <<
				std::setw(20) << i.pavarde << std::right << "|" << std::left << std::setw(20) << (i.rezult / (i.ndskc)) * 0.4 + i.egz * 0.6 << "|" << std::endl;
		}
	}
	open_f << rasbufferis.str();
	rasbufferis.clear();
	open_f.close();
}
bool sortf(zmogus pirmas, zmogus antras) {
	if (pirmas.vardas != antras.vardas)
		return pirmas.vardas < antras.vardas;
}
void fgeneravimas(int ndskc, int dydis) {
	auto start = std::chrono::high_resolution_clock::now(); auto st = start;
	string pav = std::to_string(dydis) + ".txt";
	std::ofstream open_f(pav);
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> dist(1, 10);
	open_f << "Vardas " << "Pavarde ";
	for (int i = 1; i < ndskc + 1; i++) {
		open_f << "ND" << i << " ";
	}
	open_f << "Egz." << std::endl;
	for (int i = 1; i < dydis + 1; i++) {
		open_f << "Vardas" << i << " Pavarde" << i << " ";
		for (int y = 0; y < ndskc + 1; y++) {
			open_f << dist(mt) << " ";
		}
		open_f << std::endl;
	}
	open_f.close();
	std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;
	cout << "Uztruko " << diff.count() << "s" << std::endl;
	//baigt skaiciuot
}
void apskaiciavimas(std::list <zmogus>& amas, std::list <string>& ndskcc, int dydis) {
	//pradet skaiciuot
	std::stringstream bufferis;
	string sdydis = std::to_string(dydis) + ".txt";
	try {
		std::ifstream open_f(sdydis);
		if (open_f) {
			bufferis << open_f.rdbuf();
			open_f.close();
		}
		else
			throw 404;
	}
	catch (...) {
		cout << "Pasirinkto duomenu failo nera. Programa uzbaigta";
		return;
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
			bufferis >> amas.back().vardas;
			bufferis >> amas.back().pavarde;
			for (int i = 0; i < ndskcc.size(); i++) {
				bufferis >> itemp;
				amas.back().vpaz.push_back(itemp);
				amas.back().rezult += itemp;
			}
			bufferis >> amas.back().egz;
			amas.back().ndskc = ndskcc.size();

			std::sort(amas.back().vpaz.begin(), amas.back().vpaz.end());
			if (ndskcc.size() % 2 != 0)
				amas.back().median = amas.back().vpaz[(ndskcc.size() / 2)];
			else
				amas.back().median = (amas.back().vpaz[(ndskcc.size() / 2) - 1] + amas.back().vpaz[ndskcc.size() / 2]) / 2.0;
		}
		else break;
	}
	amas.pop_back();
	bufferis.str("");
	//baigt skaiciuot
}

std::list<zmogus> padalinimas(std::list <zmogus>& amas, int krit) {
	//pradet skaiciuot
	std::list<zmogus> temp;
	std::list<zmogus> nelaimingi;
	if (krit == 0) {
		for (auto i : amas) {
			if ((i.rezult / (i.ndskc)) * 0.4 + i.egz * 0.6 < 5.0)
				nelaimingi.push_back(i);
			else
				temp.push_back(i);
		}
	}
	else {
		for (auto i : amas) {
			if (i.median * 0.4 + i.egz * 0.6 < 5.0)
				nelaimingi.push_back(i);
			else
				temp.push_back(i);
		}
	}
	amas = temp;
	temp.clear();
	return nelaimingi;
	//baigt skaiciuot
}