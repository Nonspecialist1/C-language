#include <stdio.h>
#include <time.h>

//선언 main 함수 위에 
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
	//printf("num은 %d 입니다.\n", num);
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

	// 함수 종류
	// 반환값이 없는 함수
	// function_without_return();

	// 반환값이 있는 함수
	// int ret = function_with_return();
	// p(ret);

	// 파라미터(전달값)이 없는 함수
	// function_without_params();

	// 파라미터(전달값)이 있는 함수
	// function_with_params(31, 22, 43);

	// 파라미터(전달값)도 받고 반환값이 있는 함수
	// int ret = apple(5, 2);
	// printf("사과 5개 중에 2개를 먹으면 %d개가 남아요.\n", ret);
	// printf("사과 %d개 중에 %d개를 먹으면 %d개가 남아요.\n", 10, 4, apple(10, 4));

	// 계산기 함수
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

	// 프로젝트 5개의 문 수식 퀴즈, 난이도 점점 상승
	srand(time(NULL));
	int count = 0; // 정답 갯수
	for (int i = 1; i <= 5; i++)
	{
		int n1 = getRandomNumber(i);
		int n2 = getRandomNumber(i);
		showQuestion(i, n1, n2);

		int answer = -1;
		scanf_s("%d", &answer);
		if (answer == -1) {
			printf("프로그램을 종료합니다\n");
			exit(0);
		}
		else if (answer == n1 * n2) {
			//성공
			success();
			count++;
		}
		else {
			//실패
			fail();
		}
	}
	printf("\n\n 당신은 5개의 비밀번호 중 %d 개를 맞혔습니다.\n", count);
		
	return 0;
}

// 정의 main 함수 아래에

// 반환형 함수(전달값){} 
// void 함수이름(int num1, int num2, char c, float f) { }
/*
void p(int num)
{
	printf("num은 %d 입니다.\n", num);
}

void function_without_return()
{
	printf("반환값이 없는 함수입니다.\n");
}

int function_with_return()
{
	printf("반환값이 있는 함수입니다.\n");
	return 10;
}

void function_without_params()
{
	printf("전달값이 없는 함수입니다.\n");
}

void function_with_params(int n1, int n2, int n3)
{
	printf("전달값이 있는 함수입니다. 전달받은 값은 %d, %d, %d입니다.\n", n1, n2, n3);
}

int apple(int total, int ate)
{
	printf("전달값과 반환값이 있는 함수입니다.\n");
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
	printf("\n\n\n######### %d번째 비밀번호 #########\n", level);
	printf("\n\t %d x %d 는? \n\n", n1, n2);
	printf("#########################################\n");
	printf("\n 비밀번호를 입력하세요 (종료 -1) >>");
}
void success()
{
	printf("\n >> Good ! 정답입니다 ! \n");
}
void fail()
{
	printf("\n >> 땡 ! 틀렸습니다 ! \n");
}