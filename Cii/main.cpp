#include "stroka.h"
#include <cstring> // ��� strlen, strcmp, strcpy
#include <locale> // ��� ��������� �������� �����

int main22() {
    setlocale(LC_ALL, "Russian"); // ������������� ����������� ��� �������� �����

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
    