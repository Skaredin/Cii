#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>


//���� ���������� c=c^key[i]

// ������� ��� ����������
void encrypt_file(FILE* in, FILE* out, const char* key) {
    int ch;  // ������ ���� int, ����� ��������� ������������ EOF
    size_t key_len = strlen(key);
    size_t key_index = 0;

    while ((ch = fgetc(in)) != EOF) {  // ������ ����
        unsigned char encrypted_char = (unsigned char)ch ^ key[key_index];  // XOR � ������
        fputc(encrypted_char, out);  // ���������� � ����
        key_index = (key_index + 1) % key_len;  // ������� � ���������� ������� �����
    }
}

int main() {
    setlocale(LC_ALL, ""); // �����������

    char key[256];

    // ���� �����
    printf("������� ���� ����������: ");
    if (fgets(key, sizeof(key), stdin) == NULL) {
        printf("������ ��� ����� �����.\n");
        return 1;
    }

    // ������� ������ ����� ������
    key[strcspn(key, "\n")] = '\0';

    if (strlen(key) == 0) {
        printf("���� �� ����� ���� ������.\n");
        return 1;
    }



    const char* input_file = "C:\\Users\\Admin\\source\\repos\\Cii\\Cii\\ShifrFile.txt";
    // ���� ������� ��������� ������ ���(1 ��� ����������(ShifrFile), � ������ ��� ����������� � ������ ��� ���� text � ��������� (ShifrFile1))
    const char* output_file = "C:\\Users\\Admin\\source\\repos\\Cii\\Cii\\ShifrFile1.txt";

    FILE* in;
    FILE* out;

    // ��������� ������� ���� � �������� ������
    if (fopen_s(&in, input_file, "rb") != 0) {
        perror("������ �������� ��������� �����");
        return 1;
    }

    // ��������� �������� ���� � �������� ������
    if (fopen_s(&out, output_file, "wb") != 0) {
        perror("������ �������� ����� ��� ������");
        fclose(in);
        return 1;
    }

    // ��������� ����������
    encrypt_file(in, out, key);

    fclose(in);
    fclose(out);

    printf("���� ���������� � ������� � '%s'\n", output_file);
    return 0;
}
