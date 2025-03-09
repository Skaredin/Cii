#include <stdio.h>
#include <locale.h>
#include <wchar.h>
#include <fcntl.h>
#include <io.h>

int main(void) {
    setlocale(LC_ALL, ""); // ��������� �����������
    _setmode(_fileno(stdout), _O_U16TEXT); // ������������ ������� �� UTF-16 ��� ������ Unicode

    wprintf(L"\033[32m�������� �.�. ���-230916�\033[0m\n"); // ������ ����� (��� + ������)

    FILE* in;
    char name[] = "C:\\Users\\Admin\\source\\repos\\Cii\\Cii\\Test.txt";  // ������ ���� � �����

    if (fopen_s(&in, name, "r, ccs=UTF-8") != 0) {
        perror("������");
        return 1;
    }

    wprintf(L"���� '%hs' ������ �������!\n\n", name);
    wprintf(L"\033[35m� ����� ��������� ���:\033[0m\n");

    // ��������, ������ �� ����
    fseek(in, 0, SEEK_END);
    long file_size = ftell(in);
    rewind(in);

    if (file_size == 0) {
        wprintf(L"���� ����!\n");
        fclose(in);
        return 0;
    }

    // ������������� ���������
    int empty_count = 0;  // ������� ������ ��������
    int non_empty_count = 0;  // ������� �������� ��������

    wchar_t wc;
    while (fwscanf_s(in, L"%lc", &wc, 1) != EOF) {  // ������ �� ������ �������
        // ������� ������ � �������� ��������
        if ((wc >= 0 && wc <= 31) || wc == 32) {
            empty_count++;  // ������ ������ (����������� ��� ������)
        }
        else {
            non_empty_count++;  // �������� ������
        }

        // ������� ������
        wprintf(L"%lc", wc);
    }

    // ������� �������� ��������
    wprintf(L"\n\n�������� ����������:\n");
    wprintf(L"������ ��������: %d\n", empty_count);
    wprintf(L"�������� ��������: %d\n", non_empty_count);

    fclose(in);
    return 0;
}
