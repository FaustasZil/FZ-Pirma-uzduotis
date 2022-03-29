#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <deque>
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
void fisvestis(std::deque <zmogus> temp, int vm, std::string vardas);
bool sortf(zmogus pirmas, zmogus antras);
void fgeneravimas(int ndskc, int dydis);
void apskaiciavimas(std::deque <zmogus>& amas, std::deque <std::string>& ndskcc, int dydis);
std::deque<zmogus> padalinimas(std::deque <zmogus> & amas, int krit);
