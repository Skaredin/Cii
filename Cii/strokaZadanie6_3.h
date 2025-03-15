#ifndef STROKA_H2
#define STROKA_H2

#include <iostream>

class Stroka2 {
private:
    char str[80];

public:
    Stroka2(const char* string);  // �����������
    Stroka2();                    // ����������� �� ���������
    Stroka2(const Stroka2& s);     // ����������� �����������

    Stroka2& operator=(const Stroka2& s); // �������� ������������
    Stroka2 operator+(const Stroka2& s) const; // �������� ��������
    int operator==(const Stroka2& s) const; // �������� ���������

    int dlina() const;  // ����� ��� ��������� �����
    void vvod();        // ����� ����� ������
    void vyvod() const; // ����� ������ ������

    const char* getStr() const { return str; }  // ������ ��� ������� � ������

    // ����������� �������
    static void kopir(char* str1, const char* str2);
    static void konkat(char* str1, const char* str2);
    static int dlina1(const char* str);
    static int dlina2(const char* str);
    static int dlina3(const char* str);
    static void sravn(const char* str1, const char* str2);
};

#endif // STROKA_H2
