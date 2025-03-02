#include <iostream>   // ��� ������������� ����������� ������� �����/������
#include <cstdlib>    // ��� ������������� ������� swap() (������ ������� ��������)
#include <locale>// ���������� �������� ����� !
using namespace std;

// ������� ����������� ����������
void bubbleSort(int mas[], int n) {
    for (int i = 0; i < n - 1; i++) {  // ������� ���� ��� ������� �� �������
        for (int j = 0; j < n - 1 - i; j++) {  // ���������� ���� ��� ��������� �������� ���������
            if (mas[j] > mas[j + 1]) {  // ���� ������� ������� ������ ����������
                // ����� ����������
                int t = mas[j];       // ��������� ������� ������� �� ��������� ����������
                mas[j] = mas[j + 1];  // ������ ������� ��������
                mas[j + 1] = t;       // ������ ������� ��������
            }
        }
    }
}

// ������� ������� ����������
void quickSort(int mas[], int low, int high) {
    if (low < high) {  // ���� ���� ���� �� ��� �������� ��� ����������
        int pivot = mas[high];  // ������� ������� - ��������� ������� �������
        int i = low - 1;  // ������ ��� ������� ���������

        for (int j = low; j < high; j++) {  // ���������� �������� �������
            if (mas[j] < pivot) {  // ���� ������� ������� ������ ��������
                i++;  // ����������� ������ ��� ������� ���������
                swap(mas[i], mas[j]);  // ������ �������
            }
        }

        swap(mas[i + 1], mas[high]);  // ���������� ������� ������� �� ��� ���������� �������
        int pi = i + 1;  // ������� �������� ��������

        // ���������� ��������� �������� �� � ����� ��������
        quickSort(mas, low, pi - 1);
        quickSort(mas, pi + 1, high);
    }
}

// ������� ��� ������ �������
void printArray(int mas[], int n) {
    for (int i = 0; i < n; i++) {  // �������� �� ����� �������
        cout << mas[i] << " ";  // ������� �������� �������
    }
    cout << endl;  // ������� �� ����� ������
}

int main7() {
    setlocale(LC_ALL, "Russian"); // ������������� ������� ������ ��� ��������� ��������� � �������
    std::cout << "\033[32m�������� �.�. ���-230916�\033[0m" << std::endl; // ������ ���� ��� ������
    // �������� ������ ��� ����������
    int mas[] = { 2, 5, -8, 1, -4, 6, 3, -5, -9, 13, 0, 4, 9 };
    int n = sizeof(mas) / sizeof(int);  // ���������� ���������� ��������� � �������

    // ����� ������ ����������:
    cout << "���������� ����������� ����������:" << endl;
    bubbleSort(mas, n);  // �������� ������� ����������� ����������
    printArray(mas, n);   // ������� ��������������� ������

    // ���������� ������� ��� ������� ����������
    int mas2[] = { 2, 5, -8, 1, -4, 6, 3, -5, -9, 13, 0, 4, 9 };
    cout << "���������� ������� ����������:" << endl;
    quickSort(mas2, 0, n - 1);  // �������� ������� ������� ����������
    printArray(mas2, n);  // ������� ��������������� ������

    return 0;  // ���������� 0 ��� ���������� ���������
}


//����������� ���������� � ������� ���������� ����� ���� ������������ ��� ������ � ������������ ���������,��������, � ��������� ���� int mas[rows][cols]. 
// ������ ����� ���������, ��� ���������� ������������ ������� ����� �������� ���� �� �������, ���� �� �������� (� ����������� �� ������).