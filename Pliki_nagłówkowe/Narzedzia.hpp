#ifndef NARZEDZIA_HPP
#define NARZEDZIA_HPP

#include <vector>
#include <string>
#include "Element.hpp"

std::vector<Element> generujDane(int n, int maxPriorytet);
void zapiszCSV(const std::string& nazwa, int rozmiar, const std::string& operacja, long long czasKopiec, long long czasTablica);
long long testujOperacje(int rozmiar, const std::string& operacja, std::vector<Element> daneWejsciowe, bool dlaKopca);

#endif
