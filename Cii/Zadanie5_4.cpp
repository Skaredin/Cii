#include <stdio.h>
#include <locale.h>
#include <wchar.h>
#include <fcntl.h>
#include <io.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Функция для замены паттернов вида -1-, -2-, -3- на 1, 2, 3 и т.д.
void process_page(FILE* in, FILE* out) {
    wchar_t line[1024]; // Буфер для строки
    int counter = 1; // Счётчик для замены на цифры

    while (fgetws(line, sizeof(line) / sizeof(wchar_t), in)) {  // Чтение строки из файла
        // Обработка символа \f
        wchar_t* pos = line;
        while ((pos = wcsstr(pos, L"\\f")) != NULL) {
            // Заменяем \f на \n\n
            wmemmove(pos + 1, pos + 2, wcslen(pos + 2) + 1);  // Сдвигаем строку после \f
            pos[0] = L'\n';  // Заменяем \f на \n
            pos[1] = L'\n';  // Добавляем второй \n
            pos += 2;  // Двигаемся к следующей части строки
        }

        // Новый буфер для строки после обработки
        wchar_t new_line[1024];
        wchar_t* new_pos = new_line; // Указатель на новый буфер

        pos = line;  // Сбросим указатель на начало строки

        while (*pos) {
            // Ищем паттерн -число-
            if (*pos == L'-' && iswdigit(*(pos + 1))) {
                pos++; // Пропускаем минус

                // Считываем цифры, пока встречаем цифры
                while (iswdigit(*pos)) {
                    pos++;
                }

                // Пропускаем закрывающий минус
                if (*pos == L'-') {
                    pos++;
                }

                // Заменяем паттерн на текущий счётчик (без минуса)
                new_pos += swprintf(new_pos, 10, L"%d", counter++);
            }
            else {
                // Копируем остальные символы без изменений
                *new_pos++ = *pos++;
            }
        }

        // Завершаем строку
        *new_pos = L'\0';

        // Записываем строку в выходной файл
        fputws(new_line, out);
    }
}

int main() {
    setlocale(LC_ALL, "");  // Настройка локализации
    _setmode(_fileno(stdout), _O_U16TEXT);  // Переключение консоли на UTF-16 для вывода Unicode

    FILE* in;
    FILE* out;
    char name_in[] = "C:\\Users\\Admin\\source\\repos\\Cii\\Cii\\TestPerenos.txt";  // Путь к исходному файлу
    char name_out[] = "C:\\Users\\Admin\\source\\repos\\Cii\\Cii\\Processed.txt";  // Путь к файлу для записи результата

    // Открытие исходного файла для чтения
    if (fopen_s(&in, name_in, "r, ccs=UTF-8") != 0) {
        perror("Ошибка открытия файла для чтения");
        return 1;
    }

    // Открытие файла для записи результата
    if (fopen_s(&out, name_out, "w, ccs=UTF-8") != 0) {
        perror("Ошибка открытия файла для записи");
        fclose(in);
        return 1;
    }

    wprintf(L"Файл '%hs' открыт успешно!\n\n", name_in);

    process_page(in, out);  // Обработка текста

    fclose(in);
    fclose(out);

    wprintf(L"Обработка завершена, результат записан в '%hs'\n", name_out);
    return 0;
}
