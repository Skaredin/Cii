#ifndef STROKA_H2
#define STROKA_H2

#include <iostream>

class Stroka4 {
private:
    char* str;  // ��������� �� ������������ ������
    int size;   // ������ ���������� ������

public:
    Stroka4(const char* string);  // ����������� � ����������
    Stroka4(int length);          // ����������� � ���������� ������
    Stroka4();                    // ����������� �� ���������
    Stroka4(const Stroka4& s);     // ����������� �����������
    ~Stroka4();                    // ����������

    Stroka4& operator=(const Stroka4& s); // �������� ������������
    Stroka4 operator+(const Stroka4& s) const; // �������� ��������
    int operator==(const Stroka4& s) const; // �������� ���������

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
