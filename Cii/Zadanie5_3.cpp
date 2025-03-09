#include <stdio.h>
#include <locale.h>
#include <wchar.h>
#include <fcntl.h>
#include <io.h>
#include <string.h>

// Функция для удаления символов новой строки и лишних пробелов
void trim_newline(wchar_t* str) {
    size_t len = wcslen(str);
    if (len > 0 && str[len - 1] == L'\n') {
        str[len - 1] = L'\0';  // Убираем символ новой строки
    }
}

// Функция поиска подстроки в файле и записи результатов в новый файл
void search_and_maybe_write(FILE* in, const wchar_t* search_string, const char* output_filename) {
    FILE* out = NULL;

    // Открываем файл для записи в UTF-8, только если подстрока найдена
    errno_t err = fopen_s(&out, output_filename, "w, ccs=UTF-8");
    if (err != 0) {
        perror("Ошибка при открытии файла для записи");
        return;
    }

    wchar_t line[1024];
    int found = 0;

    // Чтение файла строками
    fseek(in, 0, SEEK_SET); // Устанавливаем указатель в начало файла

    while (fgetws(line, sizeof(line) / sizeof(wchar_t), in)) {
        trim_newline(line);  // Убираем символ новой строки в конце строки
        if (wcsstr(line, search_string) != NULL) {  // Если подстрока найдена в строке
            wprintf(L"Подстрока найдена: %ls\n", line);  // Выводим в консоль
            if (out) {
                fputws(line, out);  // Записываем найденную строку в файл
            }
            found = 1;
        }
    }

    if (!found) {
        wprintf(L"Подстрока не найдена в файле.\n");
    }

    if (out) {
        fclose(out);  // Закрываем файл, если он был открыт
    }
}

// Основная функция
int main(void) {
    setlocale(LC_ALL, ""); // Настройка локализации
    _setmode(_fileno(stdout), _O_U16TEXT); // Переключение консоли на UTF-16 для вывода Unicode

    wprintf(L"\033[32mСкаредин А.В. РИЗ-230916у\033[0m\n"); // Зелёный текст (ФИО + группа)

    FILE* in;
    char name[] = "C:\\Users\\Admin\\source\\repos\\Cii\\Cii\\Test.txt";  // Полный путь к файлу

    // Используем fopen_s для безопасного открытия файла
    errno_t err = fopen_s(&in, name, "r, ccs=UTF-8");
    if (err != 0) {
        perror("Ошибка открытия файла");
        return 1;
    }

    wprintf(L"Файл '%hs' открыт успешно!\n\n", name);
    wprintf(L"\033[35mВ файле находится это:\033[0m\n"); // Печатаем содержимое файла в консоль

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

    wprintf(L"\n\n\033[31mУчитывает только англисскую строку, русский у меня не получилось, так как нужно устанавливать (ccs=UTF-8) но у меня почемуто жалуется и не хочет работать с выводом \033[0m\n\n"); // Зелёный текст (ФИО + группа)

    wprintf(L"\n\nВведите подстроку для поиска: ");
    wchar_t search_string[100];
    fgetws(search_string, sizeof(search_string) / sizeof(wchar_t), stdin);
    trim_newline(search_string);  // Убираем символ новой строки в конце

    // Поиск подстроки и вывод результатов в консоль, запись в файл если найдено
    search_and_maybe_write(in, search_string, "output.txt");

    fclose(in);
    wprintf(L"\nОперация завершена.\n");

    return 0;
}
