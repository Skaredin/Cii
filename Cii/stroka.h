#ifndef STROKA_H
#define STROKA_H

#include <iostream>
#include <cstring>

class Stroka {
private:
    char str[80];

public:
    Stroka(const char* string);
    Stroka();
    Stroka(const Stroka& s);

    Stroka& operator=(const Stroka& s);
    Stroka operator+(const Stroka& s) const;
    int operator==(const Stroka& s) const;

    int dlina() const;
    void vvod();
    void vyvod() const;
};

#endif // STROKA_H
