#include <stdio.h>
#include <locale.h>
#include <wchar.h>
#include <fcntl.h>
#include <io.h>
#include <string.h>

// ������� ��� �������� �������� ����� ������ � ������ ��������
void trim_newline(wchar_t* str) {
    size_t len = wcslen(str);
    if (len > 0 && str[len - 1] == L'\n') {
        str[len - 1] = L'\0';  // ������� ������ ����� ������
    }
}

// ������� ������ ��������� � ����� � ������ ����������� � ����� ����
void search_and_maybe_write(FILE* in, const wchar_t* search_string, const char* output_filename) {
    FILE* out = NULL;

    // ��������� ���� ��� ������ � UTF-8, ������ ���� ��������� �������
    errno_t err = fopen_s(&out, output_filename, "w, ccs=UTF-8");
    if (err != 0) {
        perror("������ ��� �������� ����� ��� ������");
        return;
    }

    wchar_t line[1024];
    int found = 0;

    // ������ ����� ��������
    fseek(in, 0, SEEK_SET); // ������������� ��������� � ������ �����

    while (fgetws(line, sizeof(line) / sizeof(wchar_t), in)) {
        trim_newline(line);  // ������� ������ ����� ������ � ����� ������
        if (wcsstr(line, search_string) != NULL) {  // ���� ��������� ������� � ������
            wprintf(L"��������� �������: %ls\n", line);  // ������� � �������
            if (out) {
                fputws(line, out);  // ���������� ��������� ������ � ����
            }
            found = 1;
        }
    }

    if (!found) {
        wprintf(L"��������� �� ������� � �����.\n");
    }

    if (out) {
        fclose(out);  // ��������� ����, ���� �� ��� ������
    }
}

// �������� �������
int main(void) {
    setlocale(LC_ALL, ""); // ��������� �����������
    _setmode(_fileno(stdout), _O_U16TEXT); // ������������ ������� �� UTF-16 ��� ������ Unicode

    wprintf(L"\033[32m�������� �.�. ���-230916�\033[0m\n"); // ������ ����� (��� + ������)

    FILE* in;
    char name[] = "C:\\Users\\Admin\\source\\repos\\Cii\\Cii\\Test.txt";  // ������ ���� � �����

    // ���������� fopen_s ��� ����������� �������� �����
    errno_t err = fopen_s(&in, name, "r, ccs=UTF-8");
    if (err != 0) {
        perror("������ �������� �����");
        return 1;
    }

    wprintf(L"���� '%hs' ������ �������!\n\n", name);
    wprintf(L"\033[35m� ����� ��������� ���:\033[0m\n"); // �������� ���������� ����� � �������

    // ��������, ������ �� ����
    fseek(in, 0, SEEK_END);
    long file_size = ftell(in);
    rewind(in);

    if (file_size == 0) {
        wprintf(L"���� ����!\n");
        fclose(in);
        return 0;
    }

    // ������ � ����� �������� � ���������� �������� fwscanf_s
    wchar_t wc;
    while (fwscanf_s(in, L"%lc", &wc, 1) != EOF) {  // ������ �� ������ �������
        wprintf(L"%lc", wc);
    }

    wprintf(L"\n\n\033[31m��������� ������ ���������� ������, ������� � ���� �� ����������, ��� ��� ����� ������������� (ccs=UTF-8) �� � ���� �������� �������� � �� ����� �������� � ������� \033[0m\n\n"); // ������ ����� (��� + ������)

    wprintf(L"\n\n������� ��������� ��� ������: ");
    wchar_t search_string[100];
    fgetws(search_string, sizeof(search_string) / sizeof(wchar_t), stdin);
    trim_newline(search_string);  // ������� ������ ����� ������ � �����

    // ����� ��������� � ����� ����������� � �������, ������ � ���� ���� �������
    search_and_maybe_write(in, search_string, "output.txt");

    fclose(in);
    wprintf(L"\n�������� ���������.\n");

    return 0;
}
