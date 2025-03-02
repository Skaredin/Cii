#include <iostream>
#include <cstring> // ��� strcmp, strcpy
#include <locale> // ��� ��������� �������� �����

// ������� ����������� ������
void kopir(char* str1, const char* str2) {
    int i = 0;
    while (str2[i] != '\0') {
        str1[i] = str2[i]; // �������� �������
        i++;
    }
    str1[i] = '\0'; // ��������� ������
}

// ������� ��������� �����
void sravn(const char* str1, const char* str2) {
    if (strcmp(str1, str2) == 0) {
        std::cout << "������ ���������" << std::endl;
    }
    else {
        std::cout << "������ ������" << std::endl;
    }
}

// ������� ��������� �����
void konkat(char* str1, const char* str2) {
    int i = 0, j = 0;
    while (str1[i] != '\0') { // ���� ����� ������ ������
        i++;
    }
    while (str2[j] != '\0') { // ��������� ������� ������ ������
        str1[i] = str2[j];
        i++;
        j++;
    }
    str1[i] = '\0'; // ��������� ������
}

int main(void) {
   
    setlocale(LC_ALL, "Russian"); // ������������� ����������� ��� �������� �����
    
    std::cout << "\033[32m�������� �.�. ���-230916�\033[0m" << std::endl; // ������ ���� ��� ������
    // ������������� �����
    char str1[100] = "qwerty", str2[] = "1234567890";

    // ����� ��������� �������� �����
    std::cout << "��������� �������� str1= " << str1 << ", str2= " << str2 << std::endl << std::endl;;

    sravn(str1, str2);

    // ����������� str2 � str1
    kopir(str1, str2);
    std::cout << "��������� �����������: str1= " << str1 << ", str2=" << str2 << std::endl << std::endl;;

    // ��������� str1 � str2 ����� �����������
    sravn(str1, str2);

    // ������������ str1 ������ "qwerty"
    kopir(str1, "qwerty");

    std::cout << "��������� ���������: str1= " << str1 << ", str2=" << str2 << std::endl << std::endl;;

    // ��������� ����� ����� �������������� str1
    sravn(str1, str2);

    // ��������� str1 � str2
    konkat(str1, str2);
    std::cout << "��������� ���������: str1= " << str1 << ", str2=" << str2 << std::endl << std::endl;;

    return 0;
}
