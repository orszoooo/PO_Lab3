#pragma once

#include <random>

#include "SygnalDekorator.h"

class Szum : public SygnalDekorator
{
private:
	std::normal_distribution<double> s_generatorSzumu;
	int s_wariancjaSzumu = 0;
public:
	double symuluj(int t);
	Szum(Sygnal* s, int start, int koniec);
};

