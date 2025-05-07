#include "Tablica.hpp"
#include <iostream>
using namespace std;

// Wstawia element na koniec
void Tablica::wstaw(const Element& el) {
    dane.push_back(el);
}

// Usuwa i zwraca element o najwyższym priorytecie
Element Tablica::wyjmijMax() {
    if (dane.empty()) return Element();
    int idx = 0;
    for (int i = 1; i < dane.size(); ++i) {
        if (dane[i].priorytet > dane[idx].priorytet ||
            (dane[i].priorytet == dane[idx].priorytet && dane[i].timestamp < dane[idx].timestamp))
            idx = i;
    }
    Element wynik = dane[idx];
    dane.erase(dane.begin() + idx);
    return wynik;
}

// Zwraca element o najwyższym priorytecie
Element Tablica::znajdzMax() {
    if (dane.empty()) return Element();
    int idx = 0;
    for (int i = 1; i < dane.size(); ++i) {
        if (dane[i].priorytet > dane[idx].priorytet ||
            (dane[i].priorytet == dane[idx].priorytet && dane[i].timestamp < dane[idx].timestamp))
            idx = i;
    }
    return dane[idx];
}

// Zmienia priorytet pierwszego znalezionego elementu
void Tablica::zmienPriorytet(int wartosc, int nowyPriorytet) {
    for (auto& e : dane) {
        if (e.wartosc == wartosc) {
            e.priorytet = nowyPriorytet;
            return;
        }
    }
}

int Tablica::rozmiarKolejki() { return dane.size(); }

void Tablica::wyczysc() { dane.clear(); }

void Tablica::wyswietl() {
    for (auto& e : dane) {
        cout << "(" << e.wartosc << ", " << e.priorytet << ") ";
    }
    cout << endl;
}
