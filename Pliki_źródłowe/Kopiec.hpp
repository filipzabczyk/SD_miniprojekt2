#ifndef KOPIEC_HPP
#define KOPIEC_HPP

#include <vector>
#include "Element.hpp"

class Kopiec {
    std::vector<Element> dane; // Wektor przechowujący elementy kopca

    void przesiewanieWGore(int i); 
    void przesiewanieWDol(int i);
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
