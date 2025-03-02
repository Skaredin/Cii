#include <iostream>
#include <locale>// ���������� �������� ����� !

// ������� ������
void obmen1(int x, int y);
void obmen2(int* x, int* y);
void obmen3(int& x, int& y);

void main() {
    setlocale(LC_ALL, "Russian");// ���������� �������� ����� !
    int a = 2, b = 5;

    std::cout << "�� ������: a = " << a << ", b = " << b << std::endl;

    obmen1(a, b);
    std::cout << "����� ������ 1 (�� ��������): a = " << a << ", b = " << b << std::endl;

    obmen2(&a, &b);
    std::cout << "����� ������ 2 (�� ���������): a = " << a << ", b = " << b << std::endl;

    obmen3(a, b);
    std::cout << "����� ������ 3 (�� ������): a = " << a << ", b = " << b << std::endl;
}

// 1. �������� ���������� �� �������� (����� ����������, ��������� �� �����������)
void obmen1(int x, int y) {
    int temp = x;
    x = y;
    y = temp;
    std::cout << "������ obmen1: x = " << x << ", y = " << y << std::endl;  // ������ ��������� ���������
}

// 2. �������� ���������� �� ��������� (���������� ������������ ����������)
void obmen2(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// 3. �������� ���������� �� ������ (���������� ������������ ����������)
void obmen3(int& x, int& y) {
    int temp = x;
    x = y;
    y = temp;
}
