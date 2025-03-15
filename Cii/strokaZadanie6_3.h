#ifndef STROKA_H2
#define STROKA_H2

#include <iostream>

class Stroka2 {
private:
    char str[80];

public:
    Stroka2(const char* string);  // Конструктор
    Stroka2();                    // Конструктор по умолчанию
    Stroka2(const Stroka2& s);     // Конструктор копирования

    Stroka2& operator=(const Stroka2& s); // Оператор присваивания
    Stroka2 operator+(const Stroka2& s) const; // Оператор сложения
    int operator==(const Stroka2& s) const; // Оператор сравнения

    int dlina() const;  // Метод для получения длины
    void vvod();        // Метод ввода строки
    void vyvod() const; // Метод вывода строки

    const char* getStr() const { return str; }  // Геттер для доступа к строке

    // Статические функции
    static void kopir(char* str1, const char* str2);
    static void konkat(char* str1, const char* str2);
    static int dlina1(const char* str);
    static int dlina2(const char* str);
    static int dlina3(const char* str);
    static void sravn(const char* str1, const char* str2);
};

#endif // STROKA_H2
