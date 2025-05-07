#ifndef ELEMENT_HPP
#define ELEMENT_HPP

struct Element {
    int wartosc;
    int priorytet;
    long long timestamp;
    Element(int w = 0, int p = 0, long long t = 0)
        : wartosc(w), priorytet(p), timestamp(t) {
    }
};

#endif
