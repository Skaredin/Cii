#ifndef STROKA_H
#define STROKA_H

#include <iostream>
#include <cstring>
#include <iostream>  // ����������� ���������� ��� ������ � ������/�������
#include <locale>    // ����������� ���������� ��� ��������� ������� �����������

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

Stroka::Stroka(const char* string) {
    strcpy_s(str, sizeof(str), string);  // ���������� strcpy_s
}

Stroka::Stroka() {
    str[0] = '\0';
}

Stroka::Stroka(const Stroka& s) {
    strcpy_s(str, sizeof(str), s.str);  // ���������� strcpy_s
}

Stroka& Stroka::operator=(const Stroka& s) {
    if (this != &s) {
        strcpy_s(str, sizeof(str), s.str);  // ���������� strcpy_s
    }
    return *this;
}

Stroka Stroka::operator+(const Stroka& s) const {
    Stroka temp;
    strcpy_s(temp.str, sizeof(temp.str), str);  // ���������� strcpy_s
    strcat_s(temp.str, sizeof(temp.str), s.str);  // ���������� strcat_s
    return temp;
}

int Stroka::operator==(const Stroka& s) const {
    return strcmp(str, s.str) == 0;
}

int Stroka::dlina() const {
    return strlen(str);
}

void Stroka::vvod() {
    std::cin >> str;
}

void Stroka::vyvod() const {
    std::cout << str << std::endl;
}


int main22() {
    setlocale(LC_ALL, "Russian"); // ������������� ������� ������ ��� ��������� ��������� � �������
    std::cout << "\033[32m�������� �.�. ���-230916�\033[0m" << std::endl; // ������ ���� ��� ������

    Stroka s1("qwert"), s3, s4(s1), s5;

    std::cout << "������� ������ ��� s3: ";
    s3.vvod();

    s3 = "asdfg";
    std::cout << "s3: ";
    s3.vyvod();

    s5 = s1 + s3 + s4;
    std::cout << "����� s5 = " << s5.dlina() << std::endl;

    std::cout << "s5: ";
    s5.vyvod();

    if (s1 == s5) {
        std::cout << "������ s1 � s5 �����" << std::endl;
    }
    else if (s1 == s4) {
        std::cout << "������ s1 � s4 �����" << std::endl;
    }

    return 0;
}
