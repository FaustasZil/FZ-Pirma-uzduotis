#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <random>
#include <fstream>
#include <sstream>
struct zmogus {
	std::string vardas = "", pavarde = "";
	int egz = 0, ndskc = 0;
	std::vector<int> vpaz;
	double rezult = 0;
	double median = 0;
};
void ivestis(zmogus& temp);
void isvestis(zmogus& temp, int vm);
void fisvestis(std::vector <zmogus> temp, int vm);
bool sortf(zmogus pirmas, zmogus antras);
void fgeneravimas(int ndskc, int dydis);