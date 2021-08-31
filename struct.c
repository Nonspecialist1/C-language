#include<stdio.h>
#include<time.h>

void initCats();
void printCat(int selected);
int checkColection();

typedef struct {
	char* name; // 이름
	int age; // 나이
	char* character; //성격
	int level; //키우기 난이도 1~5
} CAT;

// 현재까지 보유한 고양이
int collection[5] = { 0, 0, 0, 0, 0 };
// 전체 고양이 리스트
CAT cats[5];

/*
struct GameInfo
{
	char* name;
	int year;
	int price;
	char* company;

	struct GameInfo* friendGame; // 연관 업체 게임
};

typedef struct
{
	char* name;
	int year;
	int price;
	char* company;

	struct GameInfo* friendGame; // 연관 업체 게임
} GAME_INFO;
*/

int main_struct(void) {
	/*
	//[게임 출시]
	// 이름 : 나도게임
	// 발매년도 : 2017년
	// 가격 : 50원
	// 제작사 : 나도회사 
	char* name = "나도게임";
	int year = 2017;
	int price = 50;
	char* company = "나도회사";

	//[게임 출시]
	// 이름 : 너도게임
	// 발매년도 : 2017년
	// 가격 : 100원
	// 제작사 : 너도회사 
	char* name2 = "너도게임";
	int year2 = 2017;
	int price2 = 100;
	char* company2 = "너도회사";

	// 구조체 사용
	struct GameInfo gameinfo1;
	gameinfo1.name = "나도게임";
	gameinfo1.year = 2017;
	gameinfo1.price = 50;
	gameinfo1.company = "나도회사";
	// 구조체 출력
	printf("---- 게임 출시 정보 ----\n");
	printf(" 게임명 : %s\n", gameinfo1.name);
	printf(" 발매년도 : %d\n", gameinfo1.year);
	printf(" 가격 : %d\n", gameinfo1.price);
	printf(" 제조사 : %s\n", gameinfo1.company);

	// 구조체를 배열처럼 초기화
	struct GameInfo gameinfo2 = {"너도게임", 2017, 100, "너도회사"};
	printf("---- 게임 출시 정보 ----\n");
	printf(" 게임명 : %s\n", gameinfo2.name);
	printf(" 발매년도 : %d\n", gameinfo2.year);
	printf(" 가격 : %d\n", gameinfo2.price);
	printf(" 제조사 : %s\n", gameinfo2.company);

	// 구조체 배열 
	struct GameInfo gameArray[2] = {
		{"나도게임", 2017, 50, "나도회사"},
		{"너도게임", 2017, 100, "너도회사"}
	};
	// 구조체 포인터 
	struct GameInfo* gamePtr; // 미션맨
	gamePtr = &gameinfo1;
	printf("\n\n---- 미션맨의 게임 출시 정보 ----\n");
	printf(" 게임명 : %s\n", gamePtr->name); // (*gamePtr).name = gamePtr->name  같은 표현
	printf(" 발매년도 : %d\n", (*gamePtr).year);
	printf(" 가격 : %d\n", (*gamePtr).price);
	printf(" 제조사 : %s\n", (*gamePtr).company);

	// 연관 업체 게임 소개 
	gameinfo1.friendGame = &gameinfo2;
	printf("\n\n---- 연관 업체의 게임 출시 정보 ----\n");
	printf(" 게임명 : %s\n", gameinfo1.friendGame->name);
	printf(" 발매년도 : %d\n", gameinfo1.friendGame->year);
	printf(" 가격 : %d\n", gameinfo1.friendGame->price);
	printf(" 제조사 : %s\n", gameinfo1.friendGame->company);

	// typedef 자료형에 별명 지정 
	int i = 1;
	typedef int 정수;
	typedef float 실수;
	정수 정수변수 = 3; //int i = 3
	실수 실수변수 = 3.12f; //float f =3.12f
	printf("\n 정수변수 : %d, 실수변수 : %.2f \n\n", 정수변수, 실수변수);

	typedef struct GameInfo 게임정보;
	게임정보 game1;
	game1.name = "한글게임";
	game1.year = 2015;
	printf(" 게임명 : %s\n", game1.name);
	printf(" 발매년도 : %d\n\n", game1.year);

	GAME_INFO game2;
	game2.name = "한글 게임2";
	game2.year = 2014;
	printf(" 게임명 : %s\n", game2.name);
	printf(" 발매년도 : %d\n", game2.year);
	
	/*
	struct GameInformation game3;
	game3.name = "한글게임3";
	*/
	// 프로젝트 5마리의 고양이가 있다, 아무 키나 눌러서 랜덤으로 고양이를 뽑는다
	// 5마리 모두 다 수집을 해서 열심히 키우면 되는 게임 !
	// 중복 발생 가능

	// 고양이 : 이름, 나이, 성격, 키우기 난이도(레벨)
	srand(time(NULL));

	initCats();
	while (1) {
		printf("두근두근~! 어느 고양이의 집사가 될까요?\n 아무 키나 눌러서 확인하세요 !");
		getchar();

		int selected = rand() % 5; 
		printCat(selected); // 뽑은 고양이 정보 출력 
		collection[selected] = 1; // 고양이 뽑기 처리 

		int collectAll = checkColection();
		if (collectAll == 1) {
			break;
		}

	}

	return 0;
}
void initCats() {
	cats[0].name = "깜냥이";
	cats[0].age = 5;
	cats[0].character = "온순";
	cats[0].level = 1;

	cats[1].name = "귀요미";
	cats[1].age = 3;
	cats[1].character = "날카롭다";
	cats[1].level = 2;

	cats[2].name = "수줍이";
	cats[2].age = 7;
	cats[2].character = "늘 잠만 잠";
	cats[2].level = 3;

	cats[3].name = "까꿍이";
	cats[3].age = 2;
	cats[3].character = "시끄러움";
	cats[3].level = 4;

	cats[4].name = "돼냥이";
	cats[4].age = 1;
	cats[4].character = "배고픔";
	cats[4].level = 5;
};
void printCat(int selected) {
	printf("\n\n=== 당신은 이 고양이의 집사가 되었어요 ! ===\n\n");
	printf(" 이름        : %s\n", cats[selected].name);
	printf(" 나이        : %d\n", cats[selected].age);
	printf(" 특징(성격)  : %s\n", cats[selected].character);
	printf(" 레벨        : ");
	for (int i = 0; i < cats[selected].level; i++) {
		printf("%s", "★");
	}
	printf("\n\n");
};
int checkColection() {
	// 현재 보유한 고양이 목록 출력하면서 다 모았는지 여부 반환
	int collectAll = 1;

	printf("\n\n =====  보유한 고양이 목록이에요  ===== \n\n");
	
	for (int i = 0; i < 5; i++) {
		if (collection[i] == 0) {
			printf("%12s", " (빈 박스) ");
			collectAll = 0; // 다 모으지 못한 상태
		}
		else {
			printf("%12s", cats[i].name);
		}
	}
	printf("\n\n =================================================================== \n\n");

	if (collectAll) {
		printf("\n\n 축하합니다 ! 모든 고양이를 다 모았어요. 열심히 키워주세요 !\n\n");
	}

	return collectAll;
}