// WzorzecDekorator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "SkokJednostkowy.h"
#include "Sinusoida.h"
#include "Prostokat.h"
#include "Trojkat.h"
#include "Szum.h"


int main()
{
    int t_stop = 5;

    std::cout << "Skok Jednostkowy Amplituda 3.0, Czas Skoku 2, Aktywny od 0 do " << t_stop << std::endl;
    Sygnal* s1 = new SkokJednostkowy(3.0, 2, 0, t_stop);

    for (int t = 0; t <= t_stop; t++) {
        std::cout << t << " : " << s1->symuluj(t) << std::endl;
    }
    std::cout << std::string(80, '=') << std::endl;

    t_stop = 40;

    std::cout << "Sinusoida Amplituda 10.0, okres 20, aktywny od 0 do " << t_stop << std::endl;
    std::cout << "+ Skok Jednostkowy Amplituda 9.0, Czas Skoku 35, Aktywny od 30 do " << t_stop << std::endl;
    Sygnal* s2 = new Sinusoida(new SkokJednostkowy(9.0, 35, 30, t_stop), 10.0, 20, 0, t_stop);

    for (int t = 0; t < t_stop; t++) {
        std::cout << t << ": " << s2->symuluj(t) << std::endl;
    }
    std::cout << std::string(80, '=') << std::endl;

    std::cout << "Prostokat Amplituda 15.0, okres 10, wypelnienie 70%, aktywny od 0 do " << t_stop << std::endl;
    std::cout << "+ Skok Jednostkowy Amplituda -7.0, Czas Skoku 24, Aktywny od 0 do " << t_stop << std::endl;
    Sygnal* s3 = new Prostokat(new SkokJednostkowy(-7.0, 24, 0, t_stop), 15.0, 10, 0.7, 0, t_stop);

    for (int t = 0; t < t_stop; t++) {
        std::cout << t << ": " << s3->symuluj(t) << std::endl;
    }
    std::cout << std::string(80, '=') << std::endl;

    std::cout << "Trojkat Amplituda 1.0, okres 20, wypelnienie 75%, aktywny od 0 do " << t_stop << std::endl;
    std::cout << "+ Skok Jednostkowy Amplituda -0.2, Czas Skoku 0, Aktywny od 0 do " << t_stop << std::endl;
    Sygnal* s4 = new Trojkat(new SkokJednostkowy(-0.2, 0, 0, t_stop), 1.0, 20, 0.75, 0, t_stop);

    for (int t = 0; t < t_stop; t++) {
        std::cout << t << ": " << s4->symuluj(t) << std::endl;
    }
    std::cout << std::string(80, '=') << std::endl;

    std::cout << "Szum aktywny od 0 do " << t_stop << std::endl;
    std::cout << "+ Sinusoida Amplituda 10.0, okres 20, aktywny od 0 do " << t_stop << std::endl;
    std::cout << "+ Skok Jednostkowy Amplituda 9.0, Czas Skoku 35, Aktywny od 30 do " << t_stop << std::endl;
    Sygnal* s5 = new Szum(s2, 0, t_stop);

    for (int t = 0; t < t_stop; t++) {
        std::cout << t << ": " << s5->symuluj(t) << std::endl;
    }

    std::cout << std::string(80, '=') << std::endl;

    delete s1, s2, s3, s4, s5;
}

