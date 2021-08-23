#include <stdio.h>
#include <time.h>

int main(void) {
	
	// 배열을 하기 전 
	/*
	int subway_1 = 30; // 1호차에 30명이 탑승
	int subway_2 = 40;
	int subway_3 = 50;

	printf("지하철 1호선에 %d명이 타고 있습니다\n", subway_1);
	printf("지하철 2호선에 %d명이 타고 있습니다\n", subway_2);
	printf("지하철 3호선에 %d명이 타고 있습니다\n", subway_3);
	*/

	// 배열 =  값의 종류 배열이름[오직 상수] -> int imarray[2] = {4, 5}
	// 여러 개의 변수를 동시에 생성, 값을 설정하지 않으면 더미 값출력, 일부만 설정하면 나머지 값은 0으로 출력됨
	// int array[] = {1, 2} -> int array[2]와 동일
	/*
	int subway[3];
	subway[0] = 30;
	subway[1] = 40;
	subway[2] = 50;

	for (int i = 0; i < 3; i++) {
		printf("지하철 %d호선에 %d명이 타고 있습니다\n", i+1, subway[i]);
	}
	*/

	// float 타입의 배열 
	/*
	float arr[5] = { 1.1f, 2.2f, 3.3f };
	for (int i = 0; i < 5; i++) {
		printf("%f\n", arr[i]);
	}
	*/
	
	// 문자 vs 문자열
	/*
	char c = 'A';
	printf("%c\n", c);

	// 문자열 끝에는 '끝'을 의미하는 NULL 문자 '\0'이 포함되어야 함 
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
	
	// char와 영어의 크기 1byte, 한글 2byte
	// 한  글 
	// En  Gl ish
	char kor[] = "나도코딩";
	printf("%s\n", kor);
	printf("%d\n", sizeof(kor));
	
	// 심화 
	char carray[10] = { 'c', 'o', 'd', 'i', 'n' ,'g' };
	printf("%s\n", carray);
	
	for (int i = 0; i < sizeof(carray); i++) {
		printf("%d\n", carray[i]); // ASCII 코드 값 출력 NULL 문자 0으로 출력함
	}
	

	// 참고 ASCII 코드란 ANSI(미국표준협회)에서 제시한 표준 코드 체계
	// 7bit, 총 128개의 코드(0~127), a는 97, A는 65, 0은 48
	printf("%c\n", 'a');
	printf("%d\n", 'a');
	printf("%c\n", '\0');
	printf("%d\n", '\0');
	
	// 0~127 사이의 아스키코드 정수 값에 해당하는 문자 확인 
	for (int i = 0; i < 128; i++) {
		printf("아스키코드 정수 %d = %c \n", i, i);
	}
	*/

	// 프로젝트

	srand(time(NULL));
	printf("\n\n === 아빠는 대머리 게임 === \n\n");
	int answer; // 사용자 입력값
	int treatment = rand() % 4; // 발모제 선택(0~3)
	// 서로 보여주는 병 갯수를 다르게 하여 정답률 향상(처음에 2개, 이후 3개...)
	int cntShowBottle = 0; // 이번 게임에 보여줄 병 갯수
	int preCntShowBottle = 0; // 앞 게임에 보여줬던 병 갯수
	// 3번의 기회 
	for (int i = 1; i <= 3; i++) {
		int bottle[4] = { 0, 0, 0, 0 }; //4개의 병
		do {
			cntShowBottle = rand() % 2 + 2; // 보여줄 병 갯수 (2~3)
		} while (cntShowBottle == preCntShowBottle);
		preCntShowBottle = cntShowBottle;
		
		int isIncluded = 0; // 보여줄 병 중에 발모제가 포함되었는지 여부
		printf(" > %d 번째 시도 : ", i);
		// 보여줄 병 종류를 선택
		for (int j = 0; j < cntShowBottle; j++) {
			int randBottle = rand() % 4;
			// 아직 선택되지 않은 병이면, 선택 처리 
			if (bottle[randBottle] == 0) {
				bottle[randBottle] = 1;
				if (randBottle == treatment) {
					isIncluded = 1;
				}
			}
			// 이미 선택된 병이면, 중복이므로 다시 선택 
			else {
				j--;
			}
		}
		// 사용자에게 문제 표시 
		for (int k = 0; k < 4; k++) {
			if (bottle[k] == 1)
				printf("%d ", k + 1);
		}
		printf(" 물약을 머리에 바릅니다\n\n");
		if (isIncluded == 1) {
			printf(" >> 성공 ! 머리가 났어요 !\n\n");
		}
		else {
			printf(" >> 실패 ! 머리가 나지 않았어요 !\n\n");
		}
		printf("\n ...계속 하려면 아무 키나 누르세요...\n");
		getchar();
	}

	printf("\n\n 발모제는 몇 번 일까요? ");
	scanf_s("%d", &answer);
	if (answer == treatment + 1) {
		printf("\n >> 정답입니다 ! \n ");
	}
	else {
		printf("\n >> 땡 ! 틀렸어요, 정답은 %d 입니다 \n", treatment + 1);
	}	 
	return 0;
}
