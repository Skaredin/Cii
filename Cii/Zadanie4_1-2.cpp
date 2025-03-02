#include <iostream>
#include <cstring> // ��� strlen, strcmp, strcpy
#include <locale> // ��� ��������� �������� �����


// ������� 1: ����������� ����� ������ � �������������� strlen
 int dlina1(const char* str) {
    return strlen(str);
}

// ������� 2: ����������� ����� ������ � �������������� ����� while
int dlina2(const char* str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

// ������� 3: ����������� ����� ������ � �������������� ����������
int dlina3(const char* str) {
    const char* ptr = str;
    while (*ptr) {
        ptr++;
    }
    return ptr - str;
}


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

// ������� ����������� ����� ������
void dlina(const char* str) {
    std::cout << "����� ������ \"" << str << "\" = " << strlen(str) << std::endl;
}

int main11(void) {
    setlocale(LC_ALL, "Russian"); // ������������� ����������� ��� �������� �����

    std::cout << "\033[32m�������� �.�. ���-230916�\033[0m" << std::endl; // ������ ���� ��� ������

    // ������������� �����
    char str1[100] = "qwerty", str2[] = "1234567890";

    // ����� ��������� �������� �����
    std::cout << "��������� �������� str1= \033[32m" << str1 << "\033[0m, str2= \033[32m" << str2 << "\033[0m" << std::endl;


    std::cout << "����� str1 (\033[32m strlen \033[0m): \033[32m" << dlina1(str1) << "\033[0m" << std::endl;

    std::cout << "����� str2 (\033[32m while \033[0m): \033[32m" << dlina2(str2) << "\033[0m" << std::endl;
    std::cout << "����� str1 (\033[32m ��������� \033[0m): \033[32m" << dlina3(str1) << "\033[0m" << std::endl << std::endl;   

   
    dlina(str1);
    dlina(str2);
    std::cout << std::endl;

    sravn(str1, str2);

    // ����������� str2 � str1
    kopir(str1, str2);
    std::cout << "��������� �����������: \033[32mstr1= " << str1 << ", str2= " << str2 << "\033[0m" << std::endl;
    dlina(str1);
    dlina(str2);
    // ��������� str1 � str2 ����� �����������
    std::cout << "\033[32m";  // ������������� ������ ����
    sravn(str1, str2);        // �������� ������� ��������� (��� ���� �������� ���������)
    std::cout << "\033[0m";   // ���������� ����

    std::cout << std::endl;    

    // ������������ str1 ������ "qwerty"
    kopir(str1, "qwerty");
    std::cout << "��������� ���������: \033[32mstr1= " << str1 << ", str2= " << str2 << "\033[0m" << std::endl;
    dlina(str1);
    dlina(str2);
    std::cout << std::endl;

    // ��������� ����� ����� �������������� str1
    sravn(str1, str2);

    // ��������� str1 � str2
    konkat(str1, str2);
    std::cout << "��������� ���������: \033[32mstr1= " << str1 << ", str2= " << str2 << "\033[0m" << std::endl;
    dlina(str1);
    dlina(str2);
    std::cout << std::endl;

    return 0;
}
