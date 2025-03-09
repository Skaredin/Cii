#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

// Функция для шифрования
void encrypt_file(FILE* in, FILE* out, const char* key) {
    unsigned char ch;
    size_t key_len = strlen(key);  // Длина ключа
    size_t key_index = 0;  // Индекс для ключа

    // Чтение символов из входного файла и запись в выходной
    while ((ch = fgetc(in)) != EOF) {
        // Шифруем символ с использованием символа из ключа
        unsigned char encrypted_char = ch ^ key[key_index];

        // Записываем зашифрованный символ в выходной файл
        fputc(encrypted_char, out);

        // Переходим к следующему символу в ключе, если он есть
        key_index = (key_index + 1) % key_len;
    }
}

int main(int argc, char* argv[]) {
    setlocale(LC_ALL, ""); // Настройка локализации

    char key[256];  // Буфер для ключа

    // Просим пользователя ввести ключ шифрования
    printf("Введите ключ шифрования: ");
    if (fgets(key, sizeof(key), stdin) == NULL) {
        printf("Ошибка при вводе ключа.\n");
        return 1;
    }

    // Убираем символ новой строки в конце
    key[strcspn(key, "\n")] = '\0';

    if (strlen(key) == 0) {
        printf("Ключ не может быть пустым.\n");
        return 1;
    }

    FILE* in;
    FILE* out;
    const char* input_file = "C:\\Users\\Admin\\source\\repos\\Cii\\Cii\\output.txt";  // Путь к исходному файлу
    const char* output_file = "C:\\Users\\Admin\\source\\repos\\Cii\\Cii\\ShifrFile.txt";  // Путь к файлу для записи зашифрованного текста

    // Используем fopen_s для безопасного открытия файлов
    if (fopen_s(&in, input_file, "r") != 0) {
        perror("Ошибка открытия исходного файла");
        return 1;
    }

    // Открытие файла для записи результата
    if (fopen_s(&out, output_file, "w") != 0) {
        perror("Ошибка открытия файла для записи");
        fclose(in);
        return 1;
    }

    // Шифрование файла
    encrypt_file(in, out, key);

    fclose(in);
    fclose(out);

    printf("Файл зашифрован и записан в '%s'\n", output_file);
    return 0;
}
