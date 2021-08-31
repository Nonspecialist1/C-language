#include<stdio.h>
#include<time.h>

int arrayAnimal[4][5]; // ī�� ����(��20��)
int checkAnimal[4][5]; // ���������� ���� Ȯ�� 
char* strAnimal[10];

void initAnimalArray();
void initAnimalName();
void shuffleAnimal();
int getEmptyPosition();
int conv_pos_x(int x);
int conv_pos_y(int y);
void printAnimals();
void printQuestion();
int foundAllAnimal();

int main_multiplearray(void) {
	/*
	// ������ �迭 Multidimensional Array
	int i; // ��
	// 1���� �迭
	int arr[5]; // ������ -> [0][1][2][3][4]
	 
	// 2���� �迭
	int arr2[2][5]; 
	// ������ 
	// ������ 
	// [0.0][0.1][0.2][0.3][0.4] 
	// [1.0][1.1][1.2][1.3][1.4]
	int arr3[4][2]; 
	// ��� 
	// ��� 
	// ��� 
	// ��� -> [0.0][0.1]  [1.0][1.1]  [2.0][2.1]  [3.0][3.1]
	  
	// 3���� �迭 
	int arr4[3][3][3]; 
	// ���� 
	// ���� 
	// ����   
	
	// ���� 
	// ���� 
	// ����  
	
	// ���� 
	// ���� 
	// ����
	// [0.0.0] [0.0.1] [0.0.2]  [0.1.0] [0.1.1] [0.1.2]  [0.2.0] [0.2.1] [0.2.2]
	// [1.0.0] [1.0.1] [1.0.2]  [1.1.0] [1.1.1] [1.1.2]  [1.2.0] [1.2.1] [1.2.2]
	// [2.0.0] [2.0.1] [2.0.2]  [2.1.0] [2.1.1] [2.1.2]  [2.2.0] [2.2.1] [2.2.2]

	int arr2[4][2] = {
		{1, 2},
		{1, 2},
		{1, 2},
		{1, 2}
	};
	
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 2; j++) {
			printf("2���� �迭 (%d, %d)�� �� : %d\n", i, j, arr2[i][j]);
		}
		printf("\n");
	}

	int arr3[3][3][3] = {
		{
			{1,2,3},
			{4,5,6},
			{7,8,9}
		},
		{
			{11,12,13},
			{14,15,16},
			{17,18,19}
		},
		{
			{21,22,23},
			{24,25,26},
			{27,28,29}
		}
	};
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				printf("3���� �迭 (%d, %d, %d)�� �� : %d\n", i, j, k, arr3[i][j][k]);
			}
		}
		printf("\n");
	}
	*/
	// ������Ʈ 10������ ���� �ٸ� ����(�� ī�� 2�徿) 
	// ����ڷκ��� 2���� �Է°��� ���� -> ���� ���� ã���� ī�� ������
	// ��� ���� ���� ã���� ���� ����
	// �� ���� Ƚ�� �˷��ֱ�
	srand(time(NULL));

	initAnimalArray();
	initAnimalName();

	shuffleAnimal();
	int failCount = 0; // ���� Ƚ�� 
	while (1) {
		int select1 = 0; // ����ڰ� ������ ó�� ��
		int select2 = 0; // ����ڰ� ������ �ι�° ��

		//printAnimals(); // ���� ��ġ ���
		printQuestion(); // ���� ��� (ī�� ����)
		printf("������ ī�带 2�� ������ : ");
		scanf_s("%d %d", &select1, &select2);
		if (select1 == select2) // ���� ī�� ���� �� ��ȿ 
		continue;
		// ��ǥ�� �ش��ϴ� ī�带 ������ ���� ���� ���� Ȯ�� 
		// ���� ��ǥ�� (x,y)�� ��ȯ 
		int firstSelect_x = conv_pos_x(select1);
		int firstSelect_y = conv_pos_y(select1);

		int secondSelect_x = conv_pos_x(select2);
		int secondSelect_y = conv_pos_y(select2);
		
		if (
			(checkAnimal[firstSelect_x][firstSelect_y] == 0 && checkAnimal[secondSelect_x][secondSelect_y] == 0) && 
			(arrayAnimal[firstSelect_x][firstSelect_y] == arrayAnimal[secondSelect_x][secondSelect_y])
			) //ī�尡 �������� �ʾҴ���, �� ������ ������ ���� Ȯ��
		{
			printf("\n\n���� ! : %s �߰�\n\n", strAnimal[arrayAnimal[firstSelect_x][firstSelect_y]]);
			checkAnimal[firstSelect_x][firstSelect_y] = 1;
			checkAnimal[secondSelect_x][secondSelect_y] = 1;
		} // �ٸ� ������ ���
		else {
			printf("\n\n ��!!  Ʋ�Ȱų� �̹� ������ ī���Դϴ�.\n\n");
			printf("%d : %s\n", select1, strAnimal[arrayAnimal[firstSelect_x][firstSelect_y]]);
			printf("%d : %s\n", select2, strAnimal[arrayAnimal[secondSelect_x][secondSelect_y]]);
			printf("\n\n");
			failCount ++;
		}
		// ��� ������ ã�Ҵ��� ����, 1 = �� / 0 = ����
		if (foundAllAnimal() == 1) {
			printf("\n\n �����մϴ� ! ��� ������ �� ã�ҳ׿� \n");
			printf("���ݱ��� �� %d�� �Ǽ��Ͽ����ϴ� \n", failCount);
			break;
		}
	}


	return 0;
}


void initAnimalArray() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 5; j++) {
			arrayAnimal[i][j] = -1;
		}
	}
}
void initAnimalName() {
	strAnimal[0] = "������";
	strAnimal[1] = "�ϸ�";
	strAnimal[2] = "������";
	strAnimal[3] = "�����";
	strAnimal[4] = "����";

	strAnimal[5] = "�ڳ���";
	strAnimal[6] = "�⸰";
	strAnimal[7] = "��Ÿ";
	strAnimal[8] = "Ÿ��";
	strAnimal[9] = "ȣ����";
}
void shuffleAnimal() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 2; j++) {
			int pos = getEmptyPosition();
			int x = conv_pos_x(pos);
			int y = conv_pos_y(pos);
			arrayAnimal[x][y] = i;
		}
	}
}
// ��ǥ���� �� ���� ã��
int getEmptyPosition() {
	while (1) {
		int randPos = rand() % 20; // 0~19 ������ ���� ��ȯ, 19 -> {3,4} ��ǥ�� ��ȯ�ؾ� ��
		int x = conv_pos_x(randPos);
		int y = conv_pos_y(randPos);
		if (arrayAnimal[x][y] == -1) {
			return randPos;
		}
	}
	return 0;
}
int conv_pos_x(int x) {
	// 19 -> {3,4} ��ǥ�� ��ȯ�ؾ� ��, 5�� ������ ���� �̿� 
	return x / 5;
}
int conv_pos_y(int y) {
	// 19 -> {3,4} ��ǥ�� ��ȯ�ؾ� ��, 5�� ������ �������� �̿�
	return y % 5;
}
void printAnimals() {
	printf("\n\n================�̰� ����ε�.. ���� �����ݴϴ�=================\n\n");
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 5; j++) {
			printf("%8s", strAnimal[arrayAnimal[i][j]]);
		}
		printf("\n");
	}
	printf("\n\n============================================================\n\n\n");
}
void printQuestion() {
	printf("\n\n(����)\n");
	int seq = 0;
					// seq					  //checkAnimal
	//����������		 0    1   2    3    4         0  0  0  0  0
 	//����������	     �ϸ� 6    7    8    9		  1  0  0  0  0
	//����������      10  11   12  �ϸ�  14         0  0  0  1  0
	//����������      15  16   17   18   19        0  0  0  0  0
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 5; j++) {
			// ī�带 ����� ������ �������� "���� �̸�" ǥ��
			if (checkAnimal[i][j] != 0) {
				printf("%8s", strAnimal[arrayAnimal[i][j]]);
			} // Ʋ������ �޸� -> ��ġ�� ��Ÿ���� ���ڸ� ǥ��
			else {
				printf("%8d", seq);
			}
			seq ++;
		}
		printf("\n");
	}
}
int foundAllAnimal() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 5; j++) {
			if (checkAnimal[i][j] == 0)
				return 0;
		}
	}
	return 1; // ��� �� ã�� 
}