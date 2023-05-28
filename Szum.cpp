#include "Szum.h"

double Szum::symuluj(int t)
{
    std::random_device rd;
    std::mt19937 generator(rd());
    return (czyAktywny(t) ? s_generatorSzumu(generator) : 0.0) + SygnalDekorator::symuluj(t);
}

Szum::Szum(Sygnal* s, int start, int koniec)
    : SygnalDekorator(s, start, koniec)
{
}
