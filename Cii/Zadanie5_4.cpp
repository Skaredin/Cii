#include <stdio.h>
#include <locale.h>
#include <wchar.h>
#include <fcntl.h>
#include <io.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// ������� ��� ������ ��������� ���� -1-, -2-, -3- �� 1, 2, 3 � �.�.
void process_page(FILE* in, FILE* out) {
    wchar_t line[1024]; // ����� ��� ������
    int counter = 1; // ������� ��� ������ �� �����

    while (fgetws(line, sizeof(line) / sizeof(wchar_t), in)) {  // ������ ������ �� �����
        // ��������� ������� \f
        wchar_t* pos = line;
        while ((pos = wcsstr(pos, L"\\f")) != NULL) {
            // �������� \f �� \n\n
            wmemmove(pos + 1, pos + 2, wcslen(pos + 2) + 1);  // �������� ������ ����� \f
            pos[0] = L'\n';  // �������� \f �� \n
            pos[1] = L'\n';  // ��������� ������ \n
            pos += 2;  // ��������� � ��������� ����� ������
        }

        // ����� ����� ��� ������ ����� ���������
        wchar_t new_line[1024];
        wchar_t* new_pos = new_line; // ��������� �� ����� �����

        pos = line;  // ������� ��������� �� ������ ������

        while (*pos) {
            // ���� ������� -�����-
            if (*pos == L'-' && iswdigit(*(pos + 1))) {
                pos++; // ���������� �����

                // ��������� �����, ���� ��������� �����
                while (iswdigit(*pos)) {
                    pos++;
                }

                // ���������� ����������� �����
                if (*pos == L'-') {
                    pos++;
                }

                // �������� ������� �� ������� ������� (��� ������)
                new_pos += swprintf(new_pos, 10, L"%d", counter++);
            }
            else {
                // �������� ��������� ������� ��� ���������
                *new_pos++ = *pos++;
            }
        }

        // ��������� ������
        *new_pos = L'\0';

        // ���������� ������ � �������� ����
        fputws(new_line, out);
    }
}

int main() {
    setlocale(LC_ALL, "");  // ��������� �����������
    _setmode(_fileno(stdout), _O_U16TEXT);  // ������������ ������� �� UTF-16 ��� ������ Unicode

    FILE* in;
    FILE* out;
    char name_in[] = "C:\\Users\\Admin\\source\\repos\\Cii\\Cii\\TestPerenos.txt";  // ���� � ��������� �����
    char name_out[] = "C:\\Users\\Admin\\source\\repos\\Cii\\Cii\\Processed.txt";  // ���� � ����� ��� ������ ����������

    // �������� ��������� ����� ��� ������
    if (fopen_s(&in, name_in, "r, ccs=UTF-8") != 0) {
        perror("������ �������� ����� ��� ������");
        return 1;
    }

    // �������� ����� ��� ������ ����������
    if (fopen_s(&out, name_out, "w, ccs=UTF-8") != 0) {
        perror("������ �������� ����� ��� ������");
        fclose(in);
        return 1;
    }

    wprintf(L"���� '%hs' ������ �������!\n\n", name_in);

    process_page(in, out);  // ��������� ������

    fclose(in);
    fclose(out);

    wprintf(L"��������� ���������, ��������� ������� � '%hs'\n", name_out);
    return 0;
}
