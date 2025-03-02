#include <iostream>
#include <locale>// Библеотека русского языка !

// Функции обмена
void obmen1(int x, int y);
void obmen2(int* x, int* y);
void obmen3(int& x, int& y);

void main() {
    setlocale(LC_ALL, "Russian");// Библеотека русского языка !
    int a = 2, b = 5;

    std::cout << "До обмена: a = " << a << ", b = " << b << std::endl;

    obmen1(a, b);
    std::cout << "После обмена 1 (по значению): a = " << a << ", b = " << b << std::endl;

    obmen2(&a, &b);
    std::cout << "После обмена 2 (по указателю): a = " << a << ", b = " << b << std::endl;

    obmen3(a, b);
    std::cout << "После обмена 3 (по ссылке): a = " << a << ", b = " << b << std::endl;
}

// 1. Передача параметров по значению (копия переменных, изменения не сохраняются)
void obmen1(int x, int y) {
    int temp = x;
    x = y;
    y = temp;
    std::cout << "Внутри obmen1: x = " << x << ", y = " << y << std::endl;  // Только локальные изменения
}

// 2. Передача параметров по указателю (изменяются оригинальные переменные)
void obmen2(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// 3. Передача параметров по ссылке (изменяются оригинальные переменные)
void obmen3(int& x, int& y) {
    int temp = x;
    x = y;
    y = temp;
}
