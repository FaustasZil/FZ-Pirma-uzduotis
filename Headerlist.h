#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <list>
#include <vector>
#include <random>
#include <fstream>
#include <sstream>
#include <chrono>
struct zmogus {
	std::string vardas = "", pavarde = "";
	int egz = 0, ndskc = 0;
	std::vector<int> vpaz;
	double rezult = 0;
	double median = 0;
};
void ivestis(zmogus& temp);
void isvestis(zmogus& temp, int vm);
void fisvestis(std::list <zmogus> temp, int vm, std::string vardas);
bool sortf(zmogus pirmas, zmogus antras);
void fgeneravimas(int ndskc, int dydis);
void apskaiciavimas(std::list <zmogus>& amas, std::list <std::string>& ndskcc, int dydis);
std::list<zmogus> padalinimas(std::list <zmogus>& amas, int krit);

