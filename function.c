#include <stdio.h>
#include <time.h>

//���� main �Լ� ���� 
/*
void p(int num);
void function_without_return();
int function_with_return();
void function_without_params();
void function_with_params(int n1, int n2, int n3);
int apple(int total, int ate);
int add(int num, int num2);
int sub(int num, int num2);
int mul(int num, int num2);
int div(int num, int num2);
*/
int getRandomNumber(int level);
void showQuestion(int level, int n1, int n2);
void success();
void fail();

int main_function(void)
{
	/*
	int num = 2;
	//printf("num�� %d �Դϴ�.\n", num);
	p(num);

	num = num + 3;
	p(num);

	num -= 1;
	p(num);

	num *= 3;
	p(num);

	num /= 6;
	p(num);
	*/

	// �Լ� ����
	// ��ȯ���� ���� �Լ�
	// function_without_return();

	// ��ȯ���� �ִ� �Լ�
	// int ret = function_with_return();
	// p(ret);

	// �Ķ����(���ް�)�� ���� �Լ�
	// function_without_params();

	// �Ķ����(���ް�)�� �ִ� �Լ�
	// function_with_params(31, 22, 43);

	// �Ķ����(���ް�)�� �ް� ��ȯ���� �ִ� �Լ�
	// int ret = apple(5, 2);
	// printf("��� 5�� �߿� 2���� ������ %d���� ���ƿ�.\n", ret);
	// printf("��� %d�� �߿� %d���� ������ %d���� ���ƿ�.\n", 10, 4, apple(10, 4));

	// ���� �Լ�
	/*
	int num = 2;
	num = add(num, 3);
	p(num);

	num = sub(num, 1);
	p(num);

	num = mul(num, 3);
	p(num);

	num = div(num, 6);
	p(num);
	*/

	// ������Ʈ 5���� �� ���� ����, ���̵� ���� ���
	srand(time(NULL));
	int count = 0; // ���� ����
	for (int i = 1; i <= 5; i++)
	{
		int n1 = getRandomNumber(i);
		int n2 = getRandomNumber(i);
		showQuestion(i, n1, n2);

		int answer = -1;
		scanf_s("%d", &answer);
		if (answer == -1) {
			printf("���α׷��� �����մϴ�\n");
			exit(0);
		}
		else if (answer == n1 * n2) {
			//����
			success();
			count++;
		}
		else {
			//����
			fail();
		}
	}
	printf("\n\n ����� 5���� ��й�ȣ �� %d ���� �������ϴ�.\n", count);
		
	return 0;
}

// ���� main �Լ� �Ʒ���

// ��ȯ�� �Լ�(���ް�){} 
// void �Լ��̸�(int num1, int num2, char c, float f) { }
/*
void p(int num)
{
	printf("num�� %d �Դϴ�.\n", num);
}

void function_without_return()
{
	printf("��ȯ���� ���� �Լ��Դϴ�.\n");
}

int function_with_return()
{
	printf("��ȯ���� �ִ� �Լ��Դϴ�.\n");
	return 10;
}

void function_without_params()
{
	printf("���ް��� ���� �Լ��Դϴ�.\n");
}

void function_with_params(int n1, int n2, int n3)
{
	printf("���ް��� �ִ� �Լ��Դϴ�. ���޹��� ���� %d, %d, %d�Դϴ�.\n", n1, n2, n3);
}

int apple(int total, int ate)
{
	printf("���ް��� ��ȯ���� �ִ� �Լ��Դϴ�.\n");
	return total - ate;
}

int add(int num, int num2)
{
	return num + num2;
}
int sub(int num, int num2)
{
	return num - num2;
}
int mul(int num, int num2)
{
	return num * num2;
}
int div(int num, int num2)
{
	return num / num2;
}
*/
int getRandomNumber(int level)
{
	return rand() % (level * 7) + 1;
}
void showQuestion(int level, int n1, int n2)
{
	printf("\n\n\n######### %d��° ��й�ȣ #########\n", level);
	printf("\n\t %d x %d ��? \n\n", n1, n2);
	printf("#########################################\n");
	printf("\n ��й�ȣ�� �Է��ϼ��� (���� -1) >>");
}
void success()
{
	printf("\n >> Good ! �����Դϴ� ! \n");
}
void fail()
{
	printf("\n >> �� ! Ʋ�Ƚ��ϴ� ! \n");
}