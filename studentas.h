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
protected:
	std::string vardas_; 
	std::string pavarde_;
public:
	virtual inline std::string vardas() = 0;
	virtual inline std::string pavarde() = 0;
};
class Studentas : public zmogus {
protected:
	int egz_;
	std::vector<int> vpaz_;
	double vidurkis_;
	double median_;
public:
	inline double vidurkis() const { return vidurkis_; }
	inline double median() const { return median_; }
	inline int egz() const { return egz_; }
	Studentas() : egz_(0), median_(0), vidurkis_(0) {}
	//Studentas(std::string vard, std::string pavard, int egza, int mediana, int vidurk);
	void skaiciuoti(std::stringstream& sstemp, int& ndskcc);
	inline std::string vardas() override { return vardas_; }
	inline std::string pavarde() override { return pavarde_; }

	void setVidurkis(double i) { vidurkis_ = i; }
	void skcVidurki() {
		double temp = 0;  for (int i = 0; i < vpaz_.size(); i++) temp += vpaz_[i]; vidurkis_ = temp / vpaz_.size();
		vidurkis_ = vidurkis_ * 0.4 + egz_ * 0.6;
	}
	void setMedian(double i) { median_ = i; }
	void skcMedian() {
		std::sort(vpaz_.begin(), vpaz_.end());
		if (vpaz_.size() % 2 != 0)
			median_ = vpaz_[vpaz_.size() / 2];
		else
			median_ = (vpaz_[(vpaz_.size() / 2) - 1] + vpaz_[vpaz_.size() / 2]) / 2.0;
		median_ = median_ * 0.4 + egz_ * 0.6;
	}
	void setEgz(int i) { egz_ = i; }
	void setVardas(std::string i) { vardas_ = i; }
	void setPavarde(std::string i) { pavarde_ = i; }
	void setPazymiai(std::vector<int> i) { vpaz_ = i; }

	Studentas(const Studentas& z);
	Studentas& operator=(const Studentas& z);
	~Studentas() { vpaz_.clear(); }
};
//void ivestis(zmogus& temp);
//void isvestis(zmogus& temp, int vm);
void fisvestis(std::vector <Studentas> temp, int vm, std::string vardas);
bool sortf(Studentas pirmas, Studentas antras);
void fgeneravimas(int ndskc, int dydis);
void apskaiciavimas(std::vector <Studentas>& amas, std::vector <std::string>& ndskcc, int dydis);
std::vector<Studentas> padalinimas(std::vector <Studentas>& amas, int krit);


