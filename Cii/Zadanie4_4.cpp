#include <iostream>
#include <cstring>  // ��� strlen, strcmp, strcpy_s, strcat_s
#include <locale>   // ��� ��������� �������� �����
#include <cstdlib>  // ��� malloc, calloc � free

// ������� ����������� ����� ������
int dlina6(const char* str) {
    return strlen(str);
}

// ������� ����������� ������ 
void kopir6(char* str1, const char* str2, size_t size) {
    strcpy_s(str1, size, str2);
}

// ������� ��������� �����
inline void sravn6(const char* str1, const char* str2) {
    if (strcmp(str1, str2) == 0) {
        std::cout << "������ ���������" << std::endl;
    }
    else {
        std::cout << "������ ������" << std::endl;
    }
}

// ������� ��������� ����� 
void konkat6(char* str1, const char* str2, size_t size) {
    strcat_s(str1, size, str2);
}

int main13() {
    setlocale(LC_ALL, "Russian"); // ������������� ����������� ��� �������� �����

    std::cout << "\033[32m�������� �.�. ���-230916�\033[0m" << std::endl; // ������ ���� ��� ������

    // ������������ ��������� ������ � �������������� calloc
    char* str1 = (char*)calloc(100, sizeof(char));  // ���������� calloc
    char* str2 = (char*)calloc(100, sizeof(char));  // ���������� calloc

    if (!str1 || !str2) {
        std::cerr << "������ ��������� ������!" << std::endl;
        return 1;
    }

    // ������������� �����
    kopir6(str1, "qwerty", 100);
    kopir6(str2, "1234567890", 100);

    // ����� ��������� �������� �����
    std::cout << "��������� �������� str1 = \033[32m" << str1
        << "\033[0m, str2 = \033[32m" << str2 << "\033[0m" << std::endl;

    std::cout << "����� str1: \033[32m" << dlina6(str1) << "\033[0m" << std::endl;
    std::cout << "����� str2: \033[32m" << dlina6(str2) << "\033[0m" << std::endl;

    sravn6(str1, str2);

    // ����������� str2 � str1
    kopir6(str1, str2, 100);
    std::cout << "��������� �����������: \033[32mstr1= " << str1
        << ", str2= " << str2 << "\033[0m" << std::endl;

    sravn6(str1, str2);

    // ������������ str1 ������ "qwerty"
    kopir6(str1, "qwerty", 100);
    std::cout << "��������� ���������: \033[32mstr1= " << str1
        << ", str2= " << str2 << "\033[0m" << std::endl;

    sravn6(str1, str2);

    // ��������� �����
    konkat6(str1, str2, 100);
    std::cout << "��������� ���������: \033[32mstr1= " << str1
        << ", str2= " << str2 << "\033[0m" << std::endl;

    // ������������ ������
    free(str1);
    free(str2);

    return 0;
}
