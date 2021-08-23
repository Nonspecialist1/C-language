#include <stdio.h>
#include <time.h>

int main_condition(void) {

	// if 조건문 {} else if{} else{}
	/*
	int age = 25;
	if (age>19) {
		printf("성인 요금입니다.");
	}
	else {
		printf("학생 요금입니다.");
	}
	*/

	// break와 continue
	/*
	for (int i = 1; i <= 30; i++) {
		if (i > 5) {
			printf("나머지 학생은 집에 가세요.\n");
			break;
		}
		printf("%d번 학생은 조별 발표 준비를 하세요.\n", i);
	}
	
	for (int i = 1; i <= 30; i++) {
		if (i >= 6 && i <= 10) {
			if (i == 7) {
				printf("%d번 학생은 결석입니다.\n", i);
				continue;
			}
			printf("%d번 학생은 조별 발표 준비를 하세요.\n", i);
		}
	}
	*/

	// 랜덤 int num = rand() % 3 + 1 // 1 ~ 3
	// 난수 초기화 srand(time(NULL)); 
	/*
	printf("난수 초기화 전...\n");
	for (int i = 0; i < 10; i++)
		printf("%d ", rand() % 10);

	srand(time(NULL)); 
	printf("\n\n 난수 초기화 이후...\n");
	for (int i = 0; i < 10; i++)
		printf("%d ", rand() % 10);
	*/

	// switch구문 가위0 바위1 보2
	/*
	srand(time(NULL));
	int i = rand() % 3;
		switch (i)
		{
		case 0: printf("가위\n"); break;
		case 1: printf("바위\n"); break;
		case 2: printf("보\n"); break;
		default: printf("몰라요\n"); break;
		}
	*/

	// switch break 활용 
	/*
	int age = 19;
	switch (age)
	{
	case 8:
	case 9:
	case 10:
	case 11:
	case 12:
	case 13: printf("초등학생입니다\n"); break;
	case 14:
	case 15:
	case 16: printf("중학생입니다\n"); break;
	case 17: 
	case 18:
	case 19: printf("고등학생입니다\n"); break;
	default: printf("학생이 아닙니다\n"); break;
	}
	*/

	// 프로젝트 Up and Down
	srand(time(NULL));
	int num = rand() % 100 + 1;
	printf("숫자 : %d\n", num);
	int answer;
	int chance = 5;
	while (1) {
		printf("남은 기회는 %d번\n", chance--);
		printf("숫자를 맞혀보세요 (1~100) : ");
		scanf_s("%d", &answer);

		if (answer < num) {
			printf("UP ↑\n\n");
		}
		else if (answer > num) {
			printf("DOWN ↓\n\n");
		}
		else if (answer == num) {
			printf("정답입니다 !!\n\n");
			break;
		}
		else {
			printf("알 수 없는 오류가 발생했습니다.\n\n");
		}
		if (chance == 0) {
			printf("모든 기회를 다 사용하셨습니다.\n\n"); 
			break;
		}
	}
	return 0;

}