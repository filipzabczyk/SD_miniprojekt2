#ifndef TABLICA_HPP
#define TABLICA_HPP

#include <vector>
#include "Element.hpp"

class Tablica {
    std::vector<Element> dane;
public:
    void wstaw(const Element& el);
    Element wyjmijMax();
    Element znajdzMax();
    void zmienPriorytet(int wartosc, int nowyPriorytet);
    int rozmiarKolejki();
    void wyczysc();
    void wyswietl();
};

#endif
