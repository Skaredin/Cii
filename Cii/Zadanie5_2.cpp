#include <stdio.h>
#include <locale.h>
#include <wchar.h>
#include <fcntl.h>
#include <io.h>

int main(void) {
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
    wprintf(L"\033[35mВ файле находится это:\033[0m\n");

    // Проверка, пустой ли файл
    fseek(in, 0, SEEK_END);
    long file_size = ftell(in);
    rewind(in);

    if (file_size == 0) {
        wprintf(L"Файл пуст!\n");
        fclose(in);
        return 0;
    }

    // Инициализация счетчиков
    int empty_count = 0;  // Счетчик пустых символов
    int non_empty_count = 0;  // Счетчик непустых символов

    wchar_t wc;
    while (fwscanf_s(in, L"%lc", &wc, 1) != EOF) {  // Чтение по одному символу
        // Подсчёт пустых и непустых символов
        if ((wc >= 0 && wc <= 31) || wc == 32) {
            empty_count++;  // Пустой символ (управляющий или пробел)
        }
        else {
            non_empty_count++;  // Непустой символ
        }

        // Выводим символ
        wprintf(L"%lc", wc);
    }

    // Выводим итоговые подсчеты
    wprintf(L"\n\nИтоговые результаты:\n");
    wprintf(L"Пустых символов: %d\n", empty_count);
    wprintf(L"Непустых символов: %d\n", non_empty_count);

    fclose(in);
    return 0;
}
