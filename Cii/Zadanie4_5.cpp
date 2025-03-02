#include <iostream>
#include <cstring>  // ��� strlen, strcmp, strcpy_s, strcat_s
#include <locale>   // ��� ��������� �������� �����
#include <cstdlib>  // ��� malloc, calloc � free

// ������� ����������� ����� ������
int dlina7(const char* str) {
    return strlen(str);
}

// ������� ����������� ������ 
void kopir7(char* str1, const char* str2, size_t size) {
    strcpy_s(str1, size, str2);
}

// ������� ��������� �����
inline void sravn7(const char* str1, const char* str2) {
    if (strcmp(str1, str2) == 0) {
        std::cout << "������ ���������" << std::endl;
    }
    else {
        std::cout << "������ ������" << std::endl;
    }
}

// ������� ��������� ����� 
void konkat7(char* str1, const char* str2, size_t size) {
    strcat_s(str1, size, str2);
}

int main14() {
    setlocale(LC_ALL, "Russian"); // ������������� ����������� ��� �������� �����

    std::cout << "\033[32m�������� �.�. ���-230916�\033[0m" << std::endl; // ������ ���� ��� ������

    // ������������ ��������� ������ � �������������� calloc ��� ������� �����
    const int numStrings = 3; // ���������� ����� � �������
    char* strArray[numStrings]; // ������ ���������� �� ������

    // ��������� ������ ��� ������ ������
    for (int i = 0; i < numStrings; ++i) {
        strArray[i] = (char*)calloc(100, sizeof(char));
        if (!strArray[i]) {
            std::cerr << "������ ��������� ������!" << std::endl;
            return 1;
        }
    }

    std::cout << "\n\033[34m������ �� ����������� strArray[0]: \033[33m ������:" << strArray[0] << " \033[32m �����:" << dlina7(strArray[0]) << "\033[0m";
    std::cout << "\n\033[34m������ �� ����������� strArray[1]: \033[33m ������:" << strArray[1] << " \033[32m �����:" << dlina7(strArray[1]) << "\033[0m";
    std::cout << "\n\033[34m������ �� ����������� strArray[2]: \033[33m ������:" << strArray[2] << " \033[32m �����:" << dlina7(strArray[2]) << "\033[0m" << std::endl;


    // ������������� ����� � �������
    kopir7(strArray[0], "qwerty", 100);
    kopir7(strArray[1], "1234567890", 100);
    kopir7(strArray[2], "hello world", 100);

    // ����� ����� �����
    std::cout << "\n\033[35m������ ����� ����������� strArray[0]: \033[33m ������:" << strArray[0] <<" \033[32m �����:" << dlina7(strArray[0]) << "\033[0m";
    std::cout << "\n\033[35m������ ����� ����������� strArray[1]: \033[33m ������:" << strArray[1] << " \033[32m �����:" << dlina7(strArray[1]) << "\033[0m";
    std::cout << "\n\033[35m������ ����� ����������� strArray[2]: \033[33m ������:" << strArray[2] << " \033[32m �����:" << dlina7(strArray[2]) << "\033[0m" << std::endl << std::endl;

         
    std::cout << "\n\033[31m������ strArray[0] � strArray[0]: \033[33m" << strArray[0] << "  �  " << strArray[0] << " \033[31m ";
    // ��������� ����� strArray[0], strArray[0]
    sravn7(strArray[0], strArray[0]);
    std::cout << "\033[0m";

    std::cout << "\n\033[36m������ strArray[0] � strArray[1]: \033[33m" << strArray[0] << "  �  " << strArray[1] << " \033[32m";
    // ��������� ����� strArray[0], strArray[1]
    sravn7(strArray[0], strArray[1]);
    std::cout << "\033[0m";

    std::cout << "\n\033[36m������ strArray[1] � strArray[2]: \033[33m" << strArray[1] << "  �  " << strArray[2] << " \033[32m";
    // ��������� ����� strArray[1], strArray[2]
    sravn7(strArray[1], strArray[2]);
    std::cout << "\033[0m";
     

    std::cout << "\n\033[31m" << "strArray[0] �� ��������� ��� �� ���������� � strArray[0] ������ ���� � �� ��������� ��������� !" << "\033[0m" << std::endl;

    // ��������� �����
    konkat7(strArray[0], "", 100);
    std::cout << "��������� ��������� 1 (strArray[0] � \"\"): \033[32m" << strArray[0] << "\033[0m";

    // ��������� �����
    konkat7(strArray[0], strArray[2], 100);
    std::cout << "\n��������� ��������� 2 (strArray[0] � strArray[2]): \033[32m" << strArray[0] << "\033[0m" ;

    // ��������� �����
    konkat7(strArray[0], strArray[1], 100);
    std::cout << "\n��������� ��������� 3 (strArray[0] � strArray[1]): \033[32m" << strArray[0] << "\033[0m" << std::endl;

    // ��������� �����
    konkat7(strArray[0], strArray[2], 100);
    std::cout << "\n��������� ��������� 4 (strArray[0] � strArray[2]): \033[32m" << strArray[0] << "\033[0m" << std::endl;


    // ������������ ������
    for (int i = 0; i < numStrings; ++i) {
        free(strArray[i]);
    }

    return 0;
}
