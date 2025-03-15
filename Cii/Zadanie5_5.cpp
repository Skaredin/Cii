#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>


//Ключ шифрования c=c^key[i]

// Функция для шифрования
void encrypt_file(FILE* in, FILE* out, const char* key) {
    int ch;  // Должен быть int, чтобы корректно обрабатывать EOF
    size_t key_len = strlen(key);
    size_t key_index = 0;

    while ((ch = fgetc(in)) != EOF) {  // Читаем байт
        unsigned char encrypted_char = (unsigned char)ch ^ key[key_index];  // XOR с ключом
        fputc(encrypted_char, out);  // Записываем в файл
        key_index = (key_index + 1) % key_len;  // Переход к следующему символу ключа
    }
}

int main() {
    setlocale(LC_ALL, ""); // Локализация

    char key[256];

    // Ввод ключа
    printf("Введите ключ шифрования: ");
    if (fgets(key, sizeof(key), stdin) == NULL) {
        printf("Ошибка при вводе ключа.\n");
        return 1;
    }

    // Убираем символ новой строки
    key[strcspn(key, "\n")] = '\0';

    if (strlen(key) == 0) {
        printf("Ключ не может быть пустым.\n");
        return 1;
    }



    const char* input_file = "C:\\Users\\Admin\\source\\repos\\Cii\\Cii\\ShifrFile.txt";
    // Фаил который обработал второй раз(1 раз зашифровал(ShifrFile), а второй раз расшифровал и создал ещё один text с названием (ShifrFile1))
    const char* output_file = "C:\\Users\\Admin\\source\\repos\\Cii\\Cii\\ShifrFile1.txt";

    FILE* in;
    FILE* out;

    // Открываем входной файл в бинарном режиме
    if (fopen_s(&in, input_file, "rb") != 0) {
        perror("Ошибка открытия исходного файла");
        return 1;
    }

    // Открываем выходной файл в бинарном режиме
    if (fopen_s(&out, output_file, "wb") != 0) {
        perror("Ошибка открытия файла для записи");
        fclose(in);
        return 1;
    }

    // Запускаем шифрование
    encrypt_file(in, out, key);

    fclose(in);
    fclose(out);

    printf("Файл зашифрован и записан в '%s'\n", output_file);
    return 0;
}
