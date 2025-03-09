#include <stdio.h>
#include <locale.h>
#include <wchar.h>
#include <fcntl.h>
#include <io.h>

int main16(void) {
    setlocale(LC_ALL, ""); // Настройка локализации
    _setmode(_fileno(stdout), _O_U16TEXT); // Переключение консоли на UTF-16 для вывода Unicode

    wprintf(L"\033[32mСкаредин А.В. РИЗ-230916у\033[0m\n"); // Зелёный текст (ФИО + группа)

    FILE* in;
    char name[] = "C:\\Users\\Admin\\source\\repos\\Cii\\Cii\\Test.txt";  // Полный путь к файлу

    if (fopen_s(&in, name, "r, ccs=UTF-8") != 0) {
        perror("Ошибка");
        return 1;
    }

    wprintf(L"Файл '%hs' открыт успешно!\n\n", name);
    wprintf(L"\033[35mВ фаиле находится это:\033[0m\n"); // Зелёный текст (ФИО + группа)
    
    // Проверка, пустой ли файл
    fseek(in, 0, SEEK_END);
    long file_size = ftell(in);
    rewind(in);

    if (file_size == 0) {
        wprintf(L"Файл пуст!\n");
        fclose(in);
        return 0;
    }

    // Чтение и вывод символов с безопасной функцией fwscanf_s
    wchar_t wc;
    while (fwscanf_s(in, L"%lc", &wc, 1) != EOF) {  // Чтение по одному символу
        wprintf(L"%lc", wc);
    }

    fclose(in);
    return 0;
}
