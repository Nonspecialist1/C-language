# include <stdio.h>

int main(void) {
	
	// ++ 쁠쁠
	/*
	int a = 10;
	printf("a는 %d\n", a);
	a++;
	printf("a는 %d\n", a);
	a++;
	printf("a는 %d\n", a);
	*/

	// ++ 실행 순서 
	/*
	int b = 20;
	printf("b는 %d\n", ++b);
	printf("b는 %d\n", b++);
	printf("b는 %d\n", b);
	*/

	// 반복문 for, while, do while
	// for(선언; 조건; 증감;){}
	/*
	for (int i = 1; i <= 10; i++) {
		printf("Hello world %d\n", i);
	}
	*/

	// while(조건){}
	/*
	int i = 1;
	while (i <= 10)
	{
		printf("Hello world %d\n", i++);
	}
	*/

	// do {} while(조건)
	/*
	int i = 1;
	do {
		printf("Hello world %d\n", i++);
	} while (i <= 10);
	*/

	// 2중 반복문
	/*
	for (int i = 1; i <= 3; i++) {
		printf("첫번째 반복문 : %d\n", i);
		for (int j = 1; j <= 3; j++) {
			printf("     두번째 반복문 : %d\n", j);
		}
	}
	*/

	// 구구단
	/*
	for (int i = 2; i <= 9; i++) {
		printf("%d단 계산\n", i);
		for (int j = 1; j <= 9; j++) {
			printf("  %d x %d = %d\n", i, j, i*j);
		}
	}
	*/

	// 별의 증가 
	/*
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j <= i; j++) {
			printf("*");
		}
		printf("\n");
	}
	*/

	// 별의 증가 띄어쓰기 이용 오른쪽부터
	/*
	for (int i = 0; i < 5; i++) {
		for (int j = i; j < 4; j++) {
			printf(" ");
		}
		for (int k = 0; k <= i; k++) {
			printf("*");
		}
		printf("\n");
	}
	*/

	// 프로젝트 피라미드 층 쌓기 게임 
	int floor;
	printf("몇 층으로 쌓겠느냐?");
	scanf_s("%d", &floor);

	for (int i = 0; i < floor; i++) {
		for (int j = i; j < floor-1; j++) {
			printf(" ");
		}
		for (int k = 0; k < i*2 + 1; k++) {
			printf("*");
		}
		printf("\n");
	}
	return 0;
}
