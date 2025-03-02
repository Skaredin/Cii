#include <iostream> 
#include <cstdlib>
#include <locale> // ���������� �������� ����� !

// ������� ��� ���������� ��������� ������� �� ����������� �� ��������� [N1, N2]
void rangeSort2(int mas[], int n, int N1, int N2) {
    // ������� ���� ��� ������� �� �������� �� N1 �� N2
    for (int i = N1; i < N2 - 1; i++) {
        // ���������� ���� ��� ��������� ��������� � ��������� [N1, N2]
        for (int j = i + 1; j < N2; j++) {
            // ���� ������� ������� ������ ����������, ������ �� �������
            if (mas[i] > mas[j]) {
                std::swap(mas[i], mas[j]);
            }
        }
    }
}

// ������� ��� ������ ������� �� �����
void printArray2(int mas[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << mas[i] << " ";
    }
    std::cout << std::endl;
}

int main9() {
    setlocale(LC_ALL, "Russian"); // ������������� ����������� ��� �������� �����
    int mas[] = { 2, 5, -8, 1, -4, 6, 3, -5, -9, 13, 0, 4, 9 };
    int n = sizeof(mas) / sizeof(int); // ������ �������

    // ������� �������� ������
    std::cout << "�� ����������: ";
    printArray2(mas, n);

    // �������� ���������� �� N1 �� N2
    int N1 = 2, N2 = 7;

    // ���������� ��������� ������� �� ����������� �� ��������� [N1, N2]
    rangeSort2(mas, n, N1, N2);

    // ������� ��������� ����� ����������
    std::cout << "����� ���������� �� ��������� �� N1=" << N1 << " �� N2=" << N2 << ": ";
    printArray2(mas, n);

    return 0;
}
