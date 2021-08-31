#include<stdio.h>
#include<time.h>

void initCats();
void printCat(int selected);
int checkColection();

typedef struct {
	char* name; // �̸�
	int age; // ����
	char* character; //����
	int level; //Ű��� ���̵� 1~5
} CAT;

// ������� ������ �����
int collection[5] = { 0, 0, 0, 0, 0 };
// ��ü ����� ����Ʈ
CAT cats[5];

/*
struct GameInfo
{
	char* name;
	int year;
	int price;
	char* company;

	struct GameInfo* friendGame; // ���� ��ü ����
};

typedef struct
{
	char* name;
	int year;
	int price;
	char* company;

	struct GameInfo* friendGame; // ���� ��ü ����
} GAME_INFO;
*/

int main_struct(void) {
	/*
	//[���� ���]
	// �̸� : ��������
	// �߸ų⵵ : 2017��
	// ���� : 50��
	// ���ۻ� : ����ȸ�� 
	char* name = "��������";
	int year = 2017;
	int price = 50;
	char* company = "����ȸ��";

	//[���� ���]
	// �̸� : �ʵ�����
	// �߸ų⵵ : 2017��
	// ���� : 100��
	// ���ۻ� : �ʵ�ȸ�� 
	char* name2 = "�ʵ�����";
	int year2 = 2017;
	int price2 = 100;
	char* company2 = "�ʵ�ȸ��";

	// ����ü ���
	struct GameInfo gameinfo1;
	gameinfo1.name = "��������";
	gameinfo1.year = 2017;
	gameinfo1.price = 50;
	gameinfo1.company = "����ȸ��";
	// ����ü ���
	printf("---- ���� ��� ���� ----\n");
	printf(" ���Ӹ� : %s\n", gameinfo1.name);
	printf(" �߸ų⵵ : %d\n", gameinfo1.year);
	printf(" ���� : %d\n", gameinfo1.price);
	printf(" ������ : %s\n", gameinfo1.company);

	// ����ü�� �迭ó�� �ʱ�ȭ
	struct GameInfo gameinfo2 = {"�ʵ�����", 2017, 100, "�ʵ�ȸ��"};
	printf("---- ���� ��� ���� ----\n");
	printf(" ���Ӹ� : %s\n", gameinfo2.name);
	printf(" �߸ų⵵ : %d\n", gameinfo2.year);
	printf(" ���� : %d\n", gameinfo2.price);
	printf(" ������ : %s\n", gameinfo2.company);

	// ����ü �迭 
	struct GameInfo gameArray[2] = {
		{"��������", 2017, 50, "����ȸ��"},
		{"�ʵ�����", 2017, 100, "�ʵ�ȸ��"}
	};
	// ����ü ������ 
	struct GameInfo* gamePtr; // �̼Ǹ�
	gamePtr = &gameinfo1;
	printf("\n\n---- �̼Ǹ��� ���� ��� ���� ----\n");
	printf(" ���Ӹ� : %s\n", gamePtr->name); // (*gamePtr).name = gamePtr->name  ���� ǥ��
	printf(" �߸ų⵵ : %d\n", (*gamePtr).year);
	printf(" ���� : %d\n", (*gamePtr).price);
	printf(" ������ : %s\n", (*gamePtr).company);

	// ���� ��ü ���� �Ұ� 
	gameinfo1.friendGame = &gameinfo2;
	printf("\n\n---- ���� ��ü�� ���� ��� ���� ----\n");
	printf(" ���Ӹ� : %s\n", gameinfo1.friendGame->name);
	printf(" �߸ų⵵ : %d\n", gameinfo1.friendGame->year);
	printf(" ���� : %d\n", gameinfo1.friendGame->price);
	printf(" ������ : %s\n", gameinfo1.friendGame->company);

	// typedef �ڷ����� ���� ���� 
	int i = 1;
	typedef int ����;
	typedef float �Ǽ�;
	���� �������� = 3; //int i = 3
	�Ǽ� �Ǽ����� = 3.12f; //float f =3.12f
	printf("\n �������� : %d, �Ǽ����� : %.2f \n\n", ��������, �Ǽ�����);

	typedef struct GameInfo ��������;
	�������� game1;
	game1.name = "�ѱ۰���";
	game1.year = 2015;
	printf(" ���Ӹ� : %s\n", game1.name);
	printf(" �߸ų⵵ : %d\n\n", game1.year);

	GAME_INFO game2;
	game2.name = "�ѱ� ����2";
	game2.year = 2014;
	printf(" ���Ӹ� : %s\n", game2.name);
	printf(" �߸ų⵵ : %d\n", game2.year);
	
	/*
	struct GameInformation game3;
	game3.name = "�ѱ۰���3";
	*/
	// ������Ʈ 5������ ����̰� �ִ�, �ƹ� Ű�� ������ �������� ����̸� �̴´�
	// 5���� ��� �� ������ �ؼ� ������ Ű��� �Ǵ� ���� !
	// �ߺ� �߻� ����

	// ����� : �̸�, ����, ����, Ű��� ���̵�(����)
	srand(time(NULL));

	initCats();
	while (1) {
		printf("�αٵα�~! ��� ������� ���簡 �ɱ��?\n �ƹ� Ű�� ������ Ȯ���ϼ��� !");
		getchar();

		int selected = rand() % 5; 
		printCat(selected); // ���� ����� ���� ��� 
		collection[selected] = 1; // ����� �̱� ó�� 

		int collectAll = checkColection();
		if (collectAll == 1) {
			break;
		}

	}

	return 0;
}
void initCats() {
	cats[0].name = "������";
	cats[0].age = 5;
	cats[0].character = "�¼�";
	cats[0].level = 1;

	cats[1].name = "�Ϳ��";
	cats[1].age = 3;
	cats[1].character = "��ī�Ӵ�";
	cats[1].level = 2;

	cats[2].name = "������";
	cats[2].age = 7;
	cats[2].character = "�� �Ḹ ��";
	cats[2].level = 3;

	cats[3].name = "�����";
	cats[3].age = 2;
	cats[3].character = "�ò�����";
	cats[3].level = 4;

	cats[4].name = "�ų���";
	cats[4].age = 1;
	cats[4].character = "�����";
	cats[4].level = 5;
};
void printCat(int selected) {
	printf("\n\n=== ����� �� ������� ���簡 �Ǿ���� ! ===\n\n");
	printf(" �̸�        : %s\n", cats[selected].name);
	printf(" ����        : %d\n", cats[selected].age);
	printf(" Ư¡(����)  : %s\n", cats[selected].character);
	printf(" ����        : ");
	for (int i = 0; i < cats[selected].level; i++) {
		printf("%s", "��");
	}
	printf("\n\n");
};
int checkColection() {
	// ���� ������ ����� ��� ����ϸ鼭 �� ��Ҵ��� ���� ��ȯ
	int collectAll = 1;

	printf("\n\n =====  ������ ����� ����̿���  ===== \n\n");
	
	for (int i = 0; i < 5; i++) {
		if (collection[i] == 0) {
			printf("%12s", " (�� �ڽ�) ");
			collectAll = 0; // �� ������ ���� ����
		}
		else {
			printf("%12s", cats[i].name);
		}
	}
	printf("\n\n =================================================================== \n\n");

	if (collectAll) {
		printf("\n\n �����մϴ� ! ��� ����̸� �� ��Ҿ��. ������ Ű���ּ��� !\n\n");
	}

	return collectAll;
}