#include <stdio.h>
int main_printfscanf(void) {
	//������ ���� int 
	/*
	int age = 12;
	printf("%d\n", age);
	age = 13;
	printf("%d\n", age);
	return 0;
	*/

	//�Ǽ��� ���� float, double 
	/*
	float f = 46.5f;
	printf("%.2f\n", f);
	double d = 46.5;
	printf("%.2lf\n", d);
	return 0;
	*/

	//��� const
	/*
	const int YEAR = 1996;
	printf("����⵵ : %d\n", YEAR);
	return 0;
	*/

	//printf ����
	/*
	int add = 3 + 7; //10
	printf("3 + 7 = %d\n", add);
	printf("%d + %d = %d\n", 3, 7, 3 + 7);
	printf("%d x %d = %d\n", 30, 75, 30 * 75);
	return 0;
	*/
	
	//scanf �Է� ���� �޾Ƽ� ���� 
	/*
	int input;
	printf("���� �Է��ϼ��� : ");
	scanf_s("%d", &input);
	printf("�Է°� : %d\n", input);
	
	int one, two, three;
	printf("3���� ������ �Է��ϼ��� : ");
	scanf_s("%d %d %d", &one, &two, &three);
	printf("ù��° �� : %d\n", one);
	printf("�ι�° �� : %d\n", two);
	printf("����° �� : %d\n", three);
	return 0;
	*/

	//char ����(�� ����), ���ڿ�(�� ���� �̻�)
	/*
	char c = 'A';
	printf("%c\n", c);
	
	char str[256];
	scanf_s("%s", str, sizeof(str));
	printf("%s\n", str);
	return 0;
	*/

	//������Ʈ1 �������� ����(���� �ۼ�)
	// �̸�, ����, ������, Ű, ���˸�
	char name[256];
	printf("�̸��� ������? ");
	scanf_s("%s", name, sizeof(name));

	int age;
	printf("�� ���̿���? ");
	scanf_s("%d", &age);

	float weight;
	printf("�����Դ� �� kg �̿���? ");
	scanf_s("%f", &weight);

	double height;
	printf("Ű�� �� cm �̿���? ");
	scanf_s("%lf", &height);

	char what[256];
	printf("���� ���˸� ���������? ");
	scanf_s("%s", what, sizeof(what));
	
	//���� ���� ���
	printf("\n\n--- ������ ���� ---\n\n");
	printf(" �̸�    : %s\n", name);
	printf(" ����    : %d\n", age);
	printf(" ������  : %.2f\n", weight);
	printf(" Ű      : %.2lf\n", height);
	printf(" ����    : %s\n", what);
	return 0;
}