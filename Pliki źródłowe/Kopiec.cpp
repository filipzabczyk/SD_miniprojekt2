#include "Kopiec.hpp"
#include <iostream>
using namespace std;

// Przesiewanie w górę po wstawieniu elementu, dopóki nie jesteśmy na korzeniu i własność kopca jest naruszona, porównujemy z rodzicem i zamieniamy, jeśli trzeba (priorytet większy lub starszy timestamp)
void Kopiec::przesiewanieWGore(int i) {
    while (i > 0) {
        int rodzic = (i - 1) / 2;
        if (dane[i].priorytet > dane[rodzic].priorytet ||
            (dane[i].priorytet == dane[rodzic].priorytet && dane[i].timestamp < dane[rodzic].timestamp)) {
            swap(dane[i], dane[rodzic]);
            i = rodzic;
        }
        else break;
    }
}
// Przesiewanie w dół po usunięciu korzenia, wybierz większe dziecko (uwzględniając FIFO przy równych priorytetach), jeśli dziecko większe od rodzica — zamień i kontynuuj w dół
void Kopiec::przesiewanieWDol(int i) {
    int n = dane.size();
    while (2 * i + 1 < n) {
        int lewy = 2 * i + 1;
        int prawy = 2 * i + 2;
        int maxIdx = i;

        if (lewy < n && (dane[lewy].priorytet > dane[maxIdx].priorytet ||
            (dane[lewy].priorytet == dane[maxIdx].priorytet && dane[lewy].timestamp < dane[maxIdx].timestamp)))
            maxIdx = lewy;

        if (prawy < n && (dane[prawy].priorytet > dane[maxIdx].priorytet ||
            (dane[prawy].priorytet == dane[maxIdx].priorytet && dane[prawy].timestamp < dane[maxIdx].timestamp)))
            maxIdx = prawy;

        if (maxIdx != i) {
            swap(dane[i], dane[maxIdx]);
            i = maxIdx;
        }
        else break;
    }
}

// Wstawianie elementu do kopca
void Kopiec::wstaw(const Element& el) {
    dane.push_back(el);
    przesiewanieWGore(dane.size() - 1);
}

// Usunięcie elementu o największym priorytecie
Element Kopiec::wyjmijMax() {
    if (dane.empty()) return Element();
    Element maxEl = dane[0];
    dane[0] = dane.back();
    dane.pop_back();
    przesiewanieWDol(0);
    return maxEl;
}

// Zwraca element o największym priorytecie bez usuwania
Element Kopiec::znajdzMax() {
    return dane.empty() ? Element() : dane[0];
}

// Modyfikuje priorytet istniejącego elementu, przeszukuje liniowo kopiec w celu znalezienia elementu o danej wartości
// Jeśli nowy priorytet jest większy — przesiej w górę, w przeciwnym razie w dół, zakłada się unikalność wartości (brak powtórzeń)
void Kopiec::zmienPriorytet(int wartosc, int nowyPriorytet) {
    for (int i = 0; i < dane.size(); ++i) {
        if (dane[i].wartosc == wartosc) {
            int stary = dane[i].priorytet;
            dane[i].priorytet = nowyPriorytet;
            if (nowyPriorytet > stary) przesiewanieWGore(i);
            else przesiewanieWDol(i);
            return;
        }
    }
}

int Kopiec::rozmiarKolejki() { return dane.size(); }

void Kopiec::wyczysc() { dane.clear(); }

// Wyświetla elementy kopca
void Kopiec::wyswietl() {
    for (auto& e : dane) {
        cout << "(" << e.wartosc << ", " << e.priorytet << ") ";
    }
    cout << endl;
}
