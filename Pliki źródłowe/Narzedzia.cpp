#include "Narzedzia.hpp"
#include <random>
#include <chrono>
#include <fstream>
#include "Kopiec.hpp"
#include "Tablica.hpp"
#include "Timer.hpp"

// Funkcja generująca losowe dane do testów
std::vector<Element> generujDane(int n, int maxPriorytet) {
    std::vector<Element> dane;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, maxPriorytet);

    for (int i = 0; i < n; ++i) {
        dane.emplace_back(i, dis(gen), std::chrono::high_resolution_clock::now().time_since_epoch().count());
    }
    return dane;
}

// Zapisuje wynik jednej operacji do pliku CSV
void zapiszCSV(const std::string& nazwa, int rozmiar, const std::string& operacja, long long czasKopiec, long long czasTablica) {
    std::ofstream plik(nazwa, std::ios::app);
    plik << rozmiar << ";" << operacja << ";" << czasKopiec << ";" << czasTablica << "\n";
    plik.close();
}

// Wykonuje operację 1000 razy, by uśrednić wynik i zmniejszyć wpływ szumów sprzętowych
long long testujOperacje(int rozmiar, const std::string& operacja, std::vector<Element> daneWejsciowe, bool dlaKopca) {
    Timer t;
    long long suma = 0;
    for (int i = 0; i < 10000; ++i) {
        int losowyIndeks = rand() % daneWejsciowe.size();
        int istniejacyElement = daneWejsciowe[losowyIndeks].wartosc;
        if (dlaKopca) {
            Kopiec k;
            for (auto& el : daneWejsciowe) k.wstaw(el);
            t.rozpocznij();
            if (operacja == "insert") {
                int sredniPriorytet = (rozmiar * 10) / 2;
                auto ts = std::chrono::high_resolution_clock::now().time_since_epoch().count();
                k.wstaw(Element(9999, sredniPriorytet, ts));
            }
            else if (operacja == "extract-max") k.wyjmijMax();
            else if (operacja == "find-max") k.znajdzMax();
            else if (operacja == "modify-key") k.zmienPriorytet(istniejacyElement, 99999);
            else if (operacja == "return-size") k.rozmiarKolejki();
            suma += t.zakoncz();
        }
        else {
            Tablica tA;
            for (auto& el : daneWejsciowe) tA.wstaw(el);
            t.rozpocznij();
            if (operacja == "insert") {
                int sredniPriorytet = (rozmiar * 10) / 2;
                auto ts = std::chrono::high_resolution_clock::now().time_since_epoch().count();
                tA.wstaw(Element(9999, sredniPriorytet, ts));
            }
            else if (operacja == "extract-max") tA.wyjmijMax();
            else if (operacja == "find-max") tA.znajdzMax();
            else if (operacja == "modify-key") tA.zmienPriorytet(istniejacyElement, 99999);
            else if (operacja == "return-size") tA.rozmiarKolejki();
            suma += t.zakoncz();
        }
    }
    return suma / 10000;
}
