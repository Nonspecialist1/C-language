#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 10000

// ��й�ȣ�� �Է� �޾Ƽ� �´� ��� �ϱ⸦ �о�ͼ� �����ְ�, ��� �ۼ��Ѵ�
// Ʋ�� ��� ��� �޼����� ǥ���ϰ� ���α׷��� �����Ѵ�

int main(void) {
	// fgets, fputs Ȱ��
	char line[MAX]; // ���Ͽ��� �ҷ��� ������ ������ ����
	char contents[MAX]; // �ϱ��忡 �Է��� ����
	char password[20];
	char c; // ��й�ȣ�� �Է� �� �� Ű�� Ȯ�ο�(����ŷ) 

	printf(" '����ϱ�'�� ���� ���� ȯ���մϴ�\n");
	printf("  ��й�ȣ�� �Է��ϼ��� :  ");

	// getchar()�� getch()�� ����
	// getchar() : ���͸� �Է¹޾ƾ� ����, getch() : Ű �Է� �� ��� ����
	int i = 0;
	while (1) {
		c = getch();
		if (c == 13) // 13�� ENTER�� �ƽ�Ű �ڵ� -> ��й�ȣ �Է� ����
		{
			password[i] = '\0';
			break;
		}
		else  // ��й�ȣ �Է� ��
		{
			printf("*");
			password[i] = c;
		}
		i++;
	}
	// ��й�ȣ : �����ڵ� skehzheld
	printf("\n\n ===== ��й�ȣ Ȯ�� ��... =====\n\n");

	if (strcmp(password, "a") == 0) // ��й�ȣ�� �´� ���
	{
		printf(" ===== ��й�ȣ Ȯ�οϷ� ===== \n\n");

		char* fileName = "secretdiary.txt";
		FILE* file = fopen(fileName, "a+b"); // a+b�� ������ ������ ����, ������ append �ϴ� ��
		if (file == NULL) {
			printf(" ���� ���� ���� \n");
			return 1;
		}

		while (fgets(line, MAX, file) != NULL) {
			printf("%s", line);
		}
		printf("\n\n ������ ��� �ۼ��ϼ��� ! �����Ͻ÷��� EXIT�� �Է��ϼ��� \n\n");

		while(1) {
			scanf("%[^\n]", contents); // �� �ٹٲ��� ������ ������ �о����(�� ���徿 ����)
			getchar(); // Enter �Է� (\n) Flush ó��
			if (strcmp(contents, "EXIT") == 0) {
				printf("����ϱ� �Է��� �����մϴ�\n\n");
				break;
			}
			fputs(contents, file);
			fputs("\n", file); // Enter�� ������ ���� ó���Ͽ����Ƿ� ���Ƿ� �߰�
		}
		fclose(file);
	}
	else // ��й�ȣ�� Ʋ�� ���
	{
		printf(" =======  ��й�ȣ�� Ʋ�Ⱦ��  ====== \n\n");
		printf(" ��� ������?!! ���� �� �ϱ����� ??!! \n");
	}
	return 0;
}