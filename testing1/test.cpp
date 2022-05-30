#include "pch.h"
#include "../studentas.h"

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(Vardas, CheckName) {
	Studentas a;
	a.setVardas("bro");
	EXPECT_EQ(a.vardas(), "bro");
	EXPECT_TRUE(true);
}

TEST(Egzas, CheckEgz) {
	Studentas a;
	a.setEgz(4);
	EXPECT_EQ(a.egz(), 4);
}

TEST(vidmed, isvidmed) {
	Studentas a;
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> dist(1, 10);
	std::vector<int> b;
	for (int i = 0; i < 6; i++) {
		b.push_back(dist(mt));
	}
	a.setPazymiai(b);
	a.setEgz(dist(mt));
	a.skcMedian();
	a.skcVidurki();
	ASSERT_NE(a.vidurkis(), a.median());
}