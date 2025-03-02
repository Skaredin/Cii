#include <iostream>
#include <cstring>  // ��� strlen, strcmp, strcpy_s, strcat_s
#include <locale>   // ��� ��������� �������� �����
#include <cstdlib>  // ��� malloc � free

// ������� ����������� ����� ������
int dlina5(const char* str) {
    return strlen(str);
}

// ������� ����������� ������ 
void kopir5(char* str1, const char* str2, size_t size) {
    strcpy_s(str1, size, str2);
}

// ������� ��������� �����

inline void sravn5(const char* str1, const char* str2) {
        if (strcmp(str1, str2) == 0) {
            std::cout << "������ ���������" << std::endl;
        }
        else {
            std::cout << "������ ������" << std::endl;
        }
    }


// ������� ��������� ����� 
void konkat5(char* str1, const char* str2, size_t size) {
    strcat_s(str1, size, str2);
}

int main() {
    setlocale(LC_ALL, "Russian"); // ������������� ����������� ��� �������� �����

    std::cout << "\033[32m�������� �.�. ���-230916�\033[0m" << std::endl; // ������ ���� ��� ������

    // ������������ ��������� ������
    char* str1 = (char*)malloc(100 * sizeof(char));
    char* str2 = (char*)malloc(100 * sizeof(char));

    if (!str1 || !str2) {
        std::cerr << "������ ��������� ������!" << std::endl;
        return 1;
    }

    // ������������� �����
    kopir5(str1, "qwerty", 100);
    kopir5(str2, "1234567890", 100);

    // ����� ��������� �������� �����
    std::cout << "��������� �������� str1 = \033[32m" << str1
        << "\033[0m, str2 = \033[32m" << str2 << "\033[0m" << std::endl;

    std::cout << "����� str1: \033[32m" << dlina5(str1) << "\033[0m" << std::endl;
    std::cout << "����� str2: \033[32m" << dlina5(str2) << "\033[0m" << std::endl;

    sravn5(str1, str2);

    // ����������� str2 � str1
    kopir5(str1, str2, 100);
    std::cout << "��������� �����������: \033[32mstr1= " << str1
        << ", str2= " << str2 << "\033[0m" << std::endl;

    sravn5(str1, str2);

    // ������������ str1 ������ "qwerty"
    kopir5(str1, "qwerty", 100);
    std::cout << "��������� ���������: \033[32mstr1= " << str1
        << ", str2= " << str2 << "\033[0m" << std::endl;

    sravn5(str1, str2);

    // ��������� �����
    konkat5(str1, str2, 100);
    std::cout << "��������� ���������: \033[32mstr1= " << str1
        << ", str2= " << str2 << "\033[0m" << std::endl;

    // ������������ ������
    free(str1);
    free(str2);

    return 0;
}
