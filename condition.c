#include <stdio.h>
#include <time.h>

int main_condition(void) {

	// if ���ǹ� {} else if{} else{}
	/*
	int age = 25;
	if (age>19) {
		printf("���� ����Դϴ�.");
	}
	else {
		printf("�л� ����Դϴ�.");
	}
	*/

	// break�� continue
	/*
	for (int i = 1; i <= 30; i++) {
		if (i > 5) {
			printf("������ �л��� ���� ������.\n");
			break;
		}
		printf("%d�� �л��� ���� ��ǥ �غ� �ϼ���.\n", i);
	}
	
	for (int i = 1; i <= 30; i++) {
		if (i >= 6 && i <= 10) {
			if (i == 7) {
				printf("%d�� �л��� �Ἦ�Դϴ�.\n", i);
				continue;
			}
			printf("%d�� �л��� ���� ��ǥ �غ� �ϼ���.\n", i);
		}
	}
	*/

	// ���� int num = rand() % 3 + 1 // 1 ~ 3
	// ���� �ʱ�ȭ srand(time(NULL)); 
	/*
	printf("���� �ʱ�ȭ ��...\n");
	for (int i = 0; i < 10; i++)
		printf("%d ", rand() % 10);

	srand(time(NULL)); 
	printf("\n\n ���� �ʱ�ȭ ����...\n");
	for (int i = 0; i < 10; i++)
		printf("%d ", rand() % 10);
	*/

	// switch���� ����0 ����1 ��2
	/*
	srand(time(NULL));
	int i = rand() % 3;
		switch (i)
		{
		case 0: printf("����\n"); break;
		case 1: printf("����\n"); break;
		case 2: printf("��\n"); break;
		default: printf("�����\n"); break;
		}
	*/

	// switch break Ȱ�� 
	/*
	int age = 19;
	switch (age)
	{
	case 8:
	case 9:
	case 10:
	case 11:
	case 12:
	case 13: printf("�ʵ��л��Դϴ�\n"); break;
	case 14:
	case 15:
	case 16: printf("���л��Դϴ�\n"); break;
	case 17: 
	case 18:
	case 19: printf("����л��Դϴ�\n"); break;
	default: printf("�л��� �ƴմϴ�\n"); break;
	}
	*/

	// ������Ʈ Up and Down
	srand(time(NULL));
	int num = rand() % 100 + 1;
	printf("���� : %d\n", num);
	int answer;
	int chance = 5;
	while (1) {
		printf("���� ��ȸ�� %d��\n", chance--);
		printf("���ڸ� ���������� (1~100) : ");
		scanf_s("%d", &answer);

		if (answer < num) {
			printf("UP ��\n\n");
		}
		else if (answer > num) {
			printf("DOWN ��\n\n");
		}
		else if (answer == num) {
			printf("�����Դϴ� !!\n\n");
			break;
		}
		else {
			printf("�� �� ���� ������ �߻��߽��ϴ�.\n\n");
		}
		if (chance == 0) {
			printf("��� ��ȸ�� �� ����ϼ̽��ϴ�.\n\n"); 
			break;
		}
	}
	return 0;

}