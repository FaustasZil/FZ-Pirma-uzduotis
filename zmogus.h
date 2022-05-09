#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <random>
#include <fstream>
#include <sstream>
#include <chrono>
class zmogus {
private:
	std::string vardas_, pavarde_;
	int egz_;
	std::vector<int> vpaz_;
	double vidurkis_;
	double median_;
public:
	zmogus() : egz_(0), median_(0), vidurkis_(0) {}
	inline std::string vardas() const { return vardas_; }
	inline std::string pavarde() const { return pavarde_; }
	inline double vidurkis() const { return vidurkis_; }
	inline double median() const { return median_; }
	inline int egz() const { return egz_; }
	void skaiciuoti(std::stringstream &sstemp, int &ndskcc);
};
//void ivestis(zmogus& temp);
//void isvestis(zmogus& temp, int vm);
void fisvestis(std::vector <zmogus> temp, int vm, std::string vardas);
bool sortf(zmogus pirmas, zmogus antras);
void fgeneravimas(int ndskc, int dydis);
void apskaiciavimas(std::vector <zmogus>& amas, std::vector <std::string>& ndskcc, int dydis);
std::vector<zmogus> padalinimas(std::vector <zmogus>& amas, int krit);
