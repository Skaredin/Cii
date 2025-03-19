#include <iostream>
#include <fstream>
#include <cstring>
#include <string> // Добавьте эту строку для использования getline
#include <locale> // Для поддержки русского языка


//Ключ шифрования c=c^key[i]

using namespace std;

// Функция для шифрования
void encrypt_file(ifstream& in, ofstream& out, const string& key) {
    char ch;
    size_t key_len = key.length();
    size_t key_index = 0;

    while (in.get(ch)) {  // Читаем байт
        unsigned char encrypted_char = static_cast<unsigned char>(ch) ^ key[key_index];  // XOR с ключом
        out.put(encrypted_char);  // Записываем в файл
        key_index = (key_index + 1) % key_len;  // Переход к следующему символу ключа
    }
}

int main28() {
    setlocale(LC_ALL, "Russian"); // Устанавливаем локализацию для русского языка
    // Оформление вывода (зелёный цвет ФИО и группы)
    std::cout << "\033[32mСкаредин А.В. РИЗ-230916у\033[0m" << std::endl;
    // Ввод ключа шифрования
    string key;
    cout << "Введите ключ шифрования: ";
    getline(cin, key);  // Используем getline для ввода строки

    if (key.empty()) {
        cout << "Ключ не может быть пустым.\n";
        return 1;
    }

    // Указываем пути для файлов
    const char* input_file = "C:\\Users\\Admin\\source\\repos\\Cii\\Cii\\ShifrFile.txt";
    const char* output_file = "C:\\Users\\Admin\\source\\repos\\Cii\\Cii\\Zadanie8_3.txt";

    // Открываем входной файл
    ifstream in(input_file, ios::binary);
    if (!in) {
        cerr << "Ошибка открытия исходного файла\n";
        return 1;
    }

    // Открываем выходной файл
    ofstream out(output_file, ios::binary);
    if (!out) {
        cerr << "Ошибка открытия файла для записи\n";
        return 1;
    }

    // Запускаем шифрование
    encrypt_file(in, out, key);

    // Закрываем файлы
    in.close();
    out.close();

    cout << "Файл зашифрован и записан в '" << output_file << "'\n";
    return 0;
}
