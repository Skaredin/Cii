#include <iostream>
#include <cstring>
#include <locale> // ��� ��������� �������� �����

using namespace std;

class Stroka3 {
private:
    char* str;  // ������������ ������ ��������
    int length; // ����� ������
public:

    // ����������� �� ���������
    Stroka3() : str(new char[1]), length(0) { str[0] = '\0'; }

    // ����������� � ����������
    Stroka3(const char* s) {
        length = strlen(s);
        str = new char[length + 1];
        strcpy_s(str, length + 1, s); // ���������� strcpy_s
    }

    // ����������� �����������
    Stroka3(const Stroka3& other) {
        length = other.length;
        str = new char[length + 1];
        strcpy_s(str, length + 1, other.str);
    }

    // �������� ������������
    Stroka3& operator=(const Stroka3& other) {
        if (this != &other) {
            delete[] str;
            length = other.length;
            str = new char[length + 1];
            strcpy_s(str, length + 1, other.str);
        }
        return *this;
    }

    // ����������
    ~Stroka3() {
        delete[] str;
    }

    // ���������� ��������� �����
    friend istream& operator>>(istream& in, Stroka3& s) {
        char buffer[256]; // ����� ��� ����� ������
        in.getline(buffer, 256);
        s.length = strlen(buffer);
        delete[] s.str; // ������� ������ ������
        s.str = new char[s.length + 1];
        strcpy_s(s.str, s.length + 1, buffer);
        return in;
    }

    // ���������� ��������� ������
    friend ostream& operator<<(ostream& out, const Stroka3& s) {
        out << s.str;
        return out;
    }
};

int main26() {
    setlocale(LC_ALL, "Russian"); // ������������� ����������� ��� �������� �����

    // ���������� ������ (������ ���� ��� � ������)
    std::cout << "\033[32m�������� �.�. ���-230916�\033[0m" << std::endl;
    Stroka3 s1, s2("Hello, world!");

    cout << "������� ������: ";
    cin >> s1;  // ���� ������ � ����������

    cout << "�� �����: " << s1 << endl; // ����� ������

    cout << "������ ������� �������� ������: " << s2 << endl;

    return 0;
}
