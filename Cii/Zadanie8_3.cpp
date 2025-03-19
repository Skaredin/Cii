#include <iostream>
#include <fstream>
#include <cstring>
#include <string> // �������� ��� ������ ��� ������������� getline
#include <locale> // ��� ��������� �������� �����


//���� ���������� c=c^key[i]

using namespace std;

// ������� ��� ����������
void encrypt_file(ifstream& in, ofstream& out, const string& key) {
    char ch;
    size_t key_len = key.length();
    size_t key_index = 0;

    while (in.get(ch)) {  // ������ ����
        unsigned char encrypted_char = static_cast<unsigned char>(ch) ^ key[key_index];  // XOR � ������
        out.put(encrypted_char);  // ���������� � ����
        key_index = (key_index + 1) % key_len;  // ������� � ���������� ������� �����
    }
}

int main28() {
    setlocale(LC_ALL, "Russian"); // ������������� ����������� ��� �������� �����
    // ���������� ������ (������ ���� ��� � ������)
    std::cout << "\033[32m�������� �.�. ���-230916�\033[0m" << std::endl;
    // ���� ����� ����������
    string key;
    cout << "������� ���� ����������: ";
    getline(cin, key);  // ���������� getline ��� ����� ������

    if (key.empty()) {
        cout << "���� �� ����� ���� ������.\n";
        return 1;
    }

    // ��������� ���� ��� ������
    const char* input_file = "C:\\Users\\Admin\\source\\repos\\Cii\\Cii\\ShifrFile.txt";
    const char* output_file = "C:\\Users\\Admin\\source\\repos\\Cii\\Cii\\Zadanie8_3.txt";

    // ��������� ������� ����
    ifstream in(input_file, ios::binary);
    if (!in) {
        cerr << "������ �������� ��������� �����\n";
        return 1;
    }

    // ��������� �������� ����
    ofstream out(output_file, ios::binary);
    if (!out) {
        cerr << "������ �������� ����� ��� ������\n";
        return 1;
    }

    // ��������� ����������
    encrypt_file(in, out, key);

    // ��������� �����
    in.close();
    out.close();

    cout << "���� ���������� � ������� � '" << output_file << "'\n";
    return 0;
}
