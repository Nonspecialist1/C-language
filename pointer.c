#include <stdio.h>
#include <time.h>
void initData();
void printfFishes();
void decreaseWater(long elapsedTime);

int* cursor;
int level;
int arrayFish[6];

/*
void swap(int a, int b);
void swap_addr(int* a, int* b);
void changeArray(int* ptr);
*/
// ������Ʈ 
// ����� 6������ �־��, �̵��� �縷�� �ִ� ���� �ӿ� �־��, �縷�� �ʹ� ���� �����ؼ� ���� ���� ���� �����ؿ�
// ���� �� �����ϱ� ���� �������� ���׿� ���� �༭ ����⸦ ����ּ���, ������ �ð��� ������ ���� Ŀ����...���߿��� �ȳ�...

int main(void) {
	/*
	// ������
	// [ö��] : 101ȣ
	// [����] : 201ȣ
	// [�μ�] : 301ȣ
	// �� �� �տ� ��ȣ�� ����
	int ö�� = 1;
	int ���� = 2;
	int �μ� = 3;

	printf("\nö���� �ּ� : %d,  ��ȣ : %d\n", &ö��, ö��);
	printf("\n����� �ּ� : %d,  ��ȣ : %d\n", &����, ����);
	printf("\n�μ��� �ּ� : %d,  ��ȣ : %d\n", &�μ�, �μ�);
	// �̼Ǹ� !
	// 1��° �̼� : ����Ʈ�� �� ���� �湮�Ͽ� ���� ���� ��ȣ Ȯ�� 
	int* �̼Ǹ�; //������ �Լ�
	�̼Ǹ� = &ö��;
	printf("\n�̼Ǹ��� �湮�ϴ� �ּ� : %d,  ��ȣ : %d\n", �̼Ǹ�, *�̼Ǹ�);
	�̼Ǹ� = &����;
	printf("\n�̼Ǹ��� �湮�ϴ� �ּ� : %d,  ��ȣ : %d\n", �̼Ǹ�, *�̼Ǹ�);
	�̼Ǹ� = &�μ�;
	printf("\n�̼Ǹ��� �湮�ϴ� �ּ� : %d,  ��ȣ : %d\n", �̼Ǹ�, *�̼Ǹ�);

	// 2��° �̼� : �� ��ȣ�� 3�� ���ض�
	�̼Ǹ� = &ö��;
	*�̼Ǹ� = *�̼Ǹ� * 3;
	printf("\n�̼Ǹ��� ��ȣ�� �ٲ� �ּ� : %d,  ��ȣ : %d\n", �̼Ǹ�, *�̼Ǹ�);

	�̼Ǹ� = &����;
	*�̼Ǹ� = *�̼Ǹ� * 3;
	printf("\n�̼Ǹ��� ��ȣ�� �ٲ� �ּ� : %d,  ��ȣ : %d\n", �̼Ǹ�, *�̼Ǹ�);

	�̼Ǹ� = &�μ�;
	*�̼Ǹ� = *�̼Ǹ� * 3;
	printf("\n�̼Ǹ��� ��ȣ�� �ٲ� �ּ� : %d,  ��ȣ : %d\n", �̼Ǹ�, *�̼Ǹ�);

	// ������, �̼Ǹ��� �ٲ� ��ȣ���� 2�� ���� !
	int* ������ = �̼Ǹ�;
	printf("\n...�����̰� �̼��� �����ϴ� ��...\n\n");

	������ = &ö��;
	*������ = *������ - 2; // ö�� = ö�� - 2�� ������ ��
	printf("�����̰� �湮�ϴ� �ּ� : %d,  ��ȣ : %d\n", ������, *������);

	������ = &����;
	*������ = *������ - 2; // ö�� = ö�� - 2�� ������ ��
	printf("�����̰� �湮�ϴ� �ּ� : %d,  ��ȣ : %d\n", ������, *������);

	������ = &�μ�;
	*������ = *������ - 2; // ö�� = ö�� - 2�� ������ ��
	printf("�����̰� �湮�ϴ� �ּ� : %d,  ��ȣ : %d\n", ������, *������);

	printf("\n...ö�� ���� �μ��� ���� ������ �ٲ� ��ȣ�� ���� ����...\n\n");
	printf("\nö���� �ּ� : %d,  ��ȣ : %d\n", &ö��, ö��);
	printf("\n����� �ּ� : %d,  ��ȣ : %d\n", &����, ����);
	printf("\n�μ��� �ּ� : %d,  ��ȣ : %d\n", &�μ�, �μ�);
	//����� �̼Ǹ��� ��� ���� �ּҴ� &�̼Ǹ����� Ȯ��
	printf("\n�̼Ǹ��� �ּ� : %d\n", &�̼Ǹ�);
	printf("\n�������� �ּ� : %d\n", &������);
	
	// �迭
	int arr[3] = { 5, 10, 15 };
	int* ptr = arr;
	
	for (int i = 0; i < 3; i++) {
		printf("�迭 arr[%d]�� �� : %d\n", i, arr[i]);
	}
	for (int i = 0; i < 3; i++) {
		printf("����Ʈ ptr[%d]�� �� : %d\n", i, ptr[i]);
	}
	ptr[0] = 100;
	ptr[1] = 200;
	ptr[2] = 300;
	for (int i = 0; i < 3; i++) {
		//printf("�迭 arr[%d]�� �� : %d\n", i, arr[i]);
		printf("�迭 arr[%d]�� �� : %d\n", i, *(arr + i));
	}
	for (int i = 0; i < 3; i++) {
		//printf("�迭 arr[%d]�� �� : %d\n", i, ptr[i]);
		printf("������ ptr[%d]�� �� : %d\n", i, *(ptr + i));
	}
	// *(arr + i) == arr[i] ���� ǥ��
	// arr == arr �迭�� ù��° ���� �ּҿ� ���� == &arr[0]
	printf("arr ��ü�� �� : %d\n", arr);
	printf("arr[0]�� �ּ� : %d\n", &arr[0]);

	printf("arr ��ü�� ���� ������ �ּ��� ���� �� : %d\n", *arr); // *(arr + 0)�� ����
	printf("arr[0]�� ���� �� : %d\n", *&arr[0]);

	// *&�� �ƹ��͵� ���� �Ͱ� ����. &�� �ּ��̰� *�� �� �ּ��� ���̱� ������ ���� ���ȴ�.
	printf("arr[0]�� ���� �� : %d\n", *&*&*&*&*&*&arr[0]);
	printf("arr[0]�� ���� �� : %d\n", arr[0]);
	
	// SWAP ���� �ٲٴ�
	int a = 10;
	int b = 20;
	printf("a�� �ּ� : %d\n", &a);
	printf("b�� �ּ� : %d\n", &b);

	// a�� b�� ���� �ٲٴ�
	printf("SWAP �Լ� �� => a : %d,  b : %d\n", a, b);
	swap(a, b);
	printf("SWAP �Լ� �� => a : %d,  b : %d\n", a, b);
	
	// ���� ���� ����(Call by Value) -> ���� �����Ѵٴ� �ǹ�
	// �ּҰ��� �ѱ��? �޸� ������ �ִ� �ּҰ� ��ü�� �ѱ��,,ö����ó�� 
	printf("(�ּҰ� ����)SWAP �Լ� �� => a : %d,  b : %d\n", a, b);
	swap_addr(&a, &b);
	printf("(�ּҰ� ����)SWAP �Լ� �� => a : %d,  b : %d\n", a, b);
	
	//�迭�� �� arr2 -> �ּ� 
	int arr2[3] = { 10, 20, 30 };
	changeArray(&arr2[0]); // changeArray(arr2);
	for (int i = 0; i < 3; i++) {
		printf("%d\n", arr2[i]);
	}
	*/

	// ������Ʈ 
	long startTime = 0; // ���� ���� �ð�
	long totalElapsedTime = 0; // �� ��� �ð�
	1

	long prevElapsedTime = 0; // ���� ��� �ð�(�ֱٿ� ���� �� ����)

	int num; // �� �� ���׿� ���� �� ������, ����� �Է�
	initData();
	
	cursor = arrayFish; // cursor[0]....cursor[1]

	startTime = clock(); // ����ð��� millisec(1000���� 1��) ������ ��ȯ
	while (1) {
		printfFishes();
		printf("�� �� ���׿� ���� �ֽðھ��? ");
		scanf_s("%d", &num);
		// �Է°� üũ
		if (num < 1 || num > 6) {
			printf("\n �Է°��� �߸��Ǿ����ϴ�\n");
			continue;
		}

		totalElapsedTime = (clock() - startTime) / CLOCKS_PER_SEC;
		printf("�� ��� �ð� : %ld ��\n", totalElapsedTime);

		// ������ ���� ��� �ð� ���ķ� �帥 �ð� 
		prevElapsedTime = totalElapsedTime - prevElapsedTime;
		printf("�ֱ� ��� �ð� : %ld ��\n", prevElapsedTime);

		// ������ �� ����(����)
		decreaseWater(prevElapsedTime);

		// ����ڰ� �Է��� ���׿� ���� �ش� 
		// 1�� ������ ���� 0�̸�? ���� �� �ʿ䰡 ����
		if (cursor[num - 1] <= 0) {
			printf("%d�� ������ �̹� �׾����ϴ�...���� �� �ʿ䰡 �����ϴ�\n", num);
		}
		// 2�� ������ ���� 0�� �ƴ� ���? ���� ����Ѵ�, 100�� ���� �ʴ��� üũ 
		else if (cursor[num - 1] + 1 <= 100) {
			printf("%d�� ���׿� ���� �ݴϴ�\n\n", num);
			cursor[num - 1] += 1;
		}
		// �������� �� ���� Ȯ��(�������� 20�ʸ��� �� ���� ����)
		if (totalElapsedTime / 20 > level - 1) {
			level++;
			printf("*** �� ������ ! ���� %d �������� %d ������ ���׷��̵� ***\n\n", level -1, level);
			// ���� ���� : 5
			if (level == 5) {
				printf("\n\n�����մϴ�. �ְ� ������ �޼��Ͽ����ϴ�. ������ �����մϴ� !\n\n");
				exit(0);
			}
		}
		// ��� ����Ⱑ �׾����� Ȯ��
		if (checkFishAlive() == 0) {
			// ����Ⱑ ��� ����
			printf("��� ����Ⱑ �׾���� !\n");
			exit(0);
		}
		else {
			// ����� 1���� �̻� ����
			printf("����Ⱑ ���� ����־�� !\n");
		}
		prevElapsedTime = totalElapsedTime;
	}

	return 0;
} 

void initData() {
	level = 1; // ���� ����(1~5)
	for (int i = 0; i < 6; i++) {
		arrayFish[i] = 100; //������ �� ����(0~100)
	}
}
void printfFishes() {
	printf("%3d�� %3d�� %3d�� %3d�� %3d�� %3d��\n", 1, 2, 3, 4, 5, 6);
	for (int i = 0; i < 6; i++) {
		printf(" %4d ", arrayFish[i]);
	}
	printf("\n\n");
}
void decreaseWater(long elapsedTime) {
	for (int i = 0; i < 6; i++) {
		arrayFish[i] -= (level * 3 * (int)elapsedTime); // 3�� ���̵� ������ ���� ��
		if (arrayFish[i] < 0) {
			arrayFish[i] = 0;
		}
	}
}
int checkFishAlive() {
	for (int i = 0; i < 6; i++) {
		if (arrayFish[i] > 0) {
			return 1; // ������ ��ȯ
		}
		return 0;
	}
}

/*
void swap(int a, int b){
	printf("(SWAP �Լ� ��) a�� �ּ� : %d\n", &a);
	printf("(SWAP �Լ� ��) b�� �ּ� : %d\n", &b);

	int temp = a;
	a = b;
	b = temp;
	printf("SWAP �Լ� �� => a : %d,  b : %d\n", a, b);
}
void swap_addr(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
	printf("(�ּҰ� ����)SWAP �Լ� �� => a : %d,  b : %d\n", *a, *b);
}
void changeArray(int* ptr) {
	ptr[2] = 50;
}
*/