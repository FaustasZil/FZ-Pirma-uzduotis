#pragma once
#ifndef _DLL_H_
#define _DLL_H_

#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <random>
#include <fstream>
#include <sstream>
#include <chrono>
#include <stdio.h>
#include <Windows.h>

#ifdef STUDENTASDLL_EXPORTS
#define STUDENTASDLL_API __declspec(dllexport)
#else
#define STUDENTASDLL_API __declspec(dllimport)
#endif

extern "C"
class STUDENTASDLL_API zmogus {
protected:
	std::string vardas_;
	std::string pavarde_;
public:
	virtual inline std::string vardas() = 0;
	virtual inline std::string pavarde() = 0;
};
extern "C"
class STUDENTASDLL_API Studentas : public zmogus {
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
	void skaiciuoti(std::stringstream& sstemp, int& ndskcc);
	inline std::string vardas() override { return vardas_; }
	inline std::string pavarde() override { return pavarde_; }
	Studentas(const Studentas& z);
	Studentas& operator=(const Studentas& z);
	~Studentas() { vpaz_.clear(); }
};
extern "C"
STUDENTASDLL_API void fisvestis(std::vector <Studentas>, int, std::string);

extern "C"
STUDENTASDLL_API bool sortf(Studentas, Studentas);

extern "C"
STUDENTASDLL_API void fgeneravimas(int, int);

extern "C"
STUDENTASDLL_API void apskaiciavimas(std::vector <Studentas>&, std::vector <std::string>&, int);

extern "C"
STUDENTASDLL_API void padalinimas(std::vector <Studentas>&, std::vector <Studentas>&, int);

#endif

