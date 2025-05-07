#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Narzedzia.hpp"
using namespace std;

int main() {
    vector<string> operacje = { "insert", "extract-max", "find-max", "modify-key", "return-size" };
    ofstream czysc("wyniki.csv");
    czysc << "Rozmiar;Operacja;Czas Kopiec [ns];Czas Tablica [ns]\n";
    czysc.close();

    for (int rozmiar = 10000; rozmiar <= 100000; rozmiar += 10000) {
        vector<Element> dane = generujDane(rozmiar, rozmiar * 10);
        for (string& op : operacje) {
            long long czasKopiec = testujOperacje(rozmiar, op, dane, true);
            long long czasTablica = testujOperacje(rozmiar, op, dane, false);
            zapiszCSV("wyniki.csv", rozmiar, op, czasKopiec, czasTablica);
            cout << "Zakonczono: " << op << " dla " << rozmiar << " elementow\n";
        }
    }

    cout << "Badanie zakonczone. Wyniki zapisano do pliku wyniki.csv\n";
    return 0;
}
