#include <stdio.h>
#include <time.h>

int main(void) {
	
	// �迭�� �ϱ� �� 
	/*
	int subway_1 = 30; // 1ȣ���� 30���� ž��
	int subway_2 = 40;
	int subway_3 = 50;

	printf("����ö 1ȣ���� %d���� Ÿ�� �ֽ��ϴ�\n", subway_1);
	printf("����ö 2ȣ���� %d���� Ÿ�� �ֽ��ϴ�\n", subway_2);
	printf("����ö 3ȣ���� %d���� Ÿ�� �ֽ��ϴ�\n", subway_3);
	*/

	// �迭 =  ���� ���� �迭�̸�[���� ���] -> int imarray[2] = {4, 5}
	// ���� ���� ������ ���ÿ� ����, ���� �������� ������ ���� �����, �Ϻθ� �����ϸ� ������ ���� 0���� ��µ�
	// int array[] = {1, 2} -> int array[2]�� ����
	/*
	int subway[3];
	subway[0] = 30;
	subway[1] = 40;
	subway[2] = 50;

	for (int i = 0; i < 3; i++) {
		printf("����ö %dȣ���� %d���� Ÿ�� �ֽ��ϴ�\n", i+1, subway[i]);
	}
	*/

	// float Ÿ���� �迭 
	/*
	float arr[5] = { 1.1f, 2.2f, 3.3f };
	for (int i = 0; i < 5; i++) {
		printf("%f\n", arr[i]);
	}
	*/
	
	// ���� vs ���ڿ�
	/*
	char c = 'A';
	printf("%c\n", c);

	// ���ڿ� ������ '��'�� �ǹ��ϴ� NULL ���� '\0'�� ���ԵǾ�� �� 
	// char str[6] = "coding"; // [c] [o] [d] [i] [n] [g] [\0]
	char str[7] = "coding"; // {'c', 'o', 'd', 'i', 'n' ,'g', '\0'};
	printf("%s\n", str);

	char st[] = "coding";
	printf("%s\n", st);
	printf("%d\n", sizeof(st));

	for (int i = 0; i < sizeof(st); i++)
	{
		printf("%c\n", st[i]);
	}
	
	// char�� ������ ũ�� 1byte, �ѱ� 2byte
	// ��  �� 
	// En  Gl ish
	char kor[] = "�����ڵ�";
	printf("%s\n", kor);
	printf("%d\n", sizeof(kor));
	
	// ��ȭ 
	char carray[10] = { 'c', 'o', 'd', 'i', 'n' ,'g' };
	printf("%s\n", carray);
	
	for (int i = 0; i < sizeof(carray); i++) {
		printf("%d\n", carray[i]); // ASCII �ڵ� �� ��� NULL ���� 0���� �����
	}
	

	// ���� ASCII �ڵ�� ANSI(�̱�ǥ����ȸ)���� ������ ǥ�� �ڵ� ü��
	// 7bit, �� 128���� �ڵ�(0~127), a�� 97, A�� 65, 0�� 48
	printf("%c\n", 'a');
	printf("%d\n", 'a');
	printf("%c\n", '\0');
	printf("%d\n", '\0');
	
	// 0~127 ������ �ƽ�Ű�ڵ� ���� ���� �ش��ϴ� ���� Ȯ�� 
	for (int i = 0; i < 128; i++) {
		printf("�ƽ�Ű�ڵ� ���� %d = %c \n", i, i);
	}
	*/

	// ������Ʈ

	srand(time(NULL));
	printf("\n\n === �ƺ��� ��Ӹ� ���� === \n\n");
	int answer; // ����� �Է°�
	int treatment = rand() % 4; // �߸��� ����(0~3)
	// ���� �����ִ� �� ������ �ٸ��� �Ͽ� ����� ���(ó���� 2��, ���� 3��...)
	int cntShowBottle = 0; // �̹� ���ӿ� ������ �� ����
	int preCntShowBottle = 0; // �� ���ӿ� ������� �� ����
	// 3���� ��ȸ 
	for (int i = 1; i <= 3; i++) {
		int bottle[4] = { 0, 0, 0, 0 }; //4���� ��
		do {
			cntShowBottle = rand() % 2 + 2; // ������ �� ���� (2~3)
		} while (cntShowBottle == preCntShowBottle);
		preCntShowBottle = cntShowBottle;
		
		int isIncluded = 0; // ������ �� �߿� �߸����� ���ԵǾ����� ����
		printf(" > %d ��° �õ� : ", i);
		// ������ �� ������ ����
		for (int j = 0; j < cntShowBottle; j++) {
			int randBottle = rand() % 4;
			// ���� ���õ��� ���� ���̸�, ���� ó�� 
			if (bottle[randBottle] == 0) {
				bottle[randBottle] = 1;
				if (randBottle == treatment) {
					isIncluded = 1;
				}
			}
			// �̹� ���õ� ���̸�, �ߺ��̹Ƿ� �ٽ� ���� 
			else {
				j--;
			}
		}
		// ����ڿ��� ���� ǥ�� 
		for (int k = 0; k < 4; k++) {
			if (bottle[k] == 1)
				printf("%d ", k + 1);
		}
		printf(" ������ �Ӹ��� �ٸ��ϴ�\n\n");
		if (isIncluded == 1) {
			printf(" >> ���� ! �Ӹ��� ����� !\n\n");
		}
		else {
			printf(" >> ���� ! �Ӹ��� ���� �ʾҾ�� !\n\n");
		}
		printf("\n ...��� �Ϸ��� �ƹ� Ű�� ��������...\n");
		getchar();
	}

	printf("\n\n �߸����� �� �� �ϱ��? ");
	scanf_s("%d", &answer);
	if (answer == treatment + 1) {
		printf("\n >> �����Դϴ� ! \n ");
	}
	else {
		printf("\n >> �� ! Ʋ�Ⱦ��, ������ %d �Դϴ� \n", treatment + 1);
	}	 
	return 0;
}
