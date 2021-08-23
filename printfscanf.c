#include <stdio.h>
int main_printfscanf(void) {
	//정수형 변수 int 
	/*
	int age = 12;
	printf("%d\n", age);
	age = 13;
	printf("%d\n", age);
	return 0;
	*/

	//실수형 변수 float, double 
	/*
	float f = 46.5f;
	printf("%.2f\n", f);
	double d = 46.5;
	printf("%.2lf\n", d);
	return 0;
	*/

	//상수 const
	/*
	const int YEAR = 1996;
	printf("출생년도 : %d\n", YEAR);
	return 0;
	*/

	//printf 연산
	/*
	int add = 3 + 7; //10
	printf("3 + 7 = %d\n", add);
	printf("%d + %d = %d\n", 3, 7, 3 + 7);
	printf("%d x %d = %d\n", 30, 75, 30 * 75);
	return 0;
	*/
	
	//scanf 입력 값을 받아서 저장 
	/*
	int input;
	printf("값을 입력하세요 : ");
	scanf_s("%d", &input);
	printf("입력값 : %d\n", input);
	
	int one, two, three;
	printf("3개의 정수를 입력하세요 : ");
	scanf_s("%d %d %d", &one, &two, &three);
	printf("첫번째 값 : %d\n", one);
	printf("두번째 값 : %d\n", two);
	printf("세번째 값 : %d\n", three);
	return 0;
	*/

	//char 문자(한 글자), 문자열(한 글자 이상)
	/*
	char c = 'A';
	printf("%c\n", c);
	
	char str[256];
	scanf_s("%s", str, sizeof(str));
	printf("%s\n", str);
	return 0;
	*/

	//프로젝트1 경찰관의 취조(조서 작성)
	// 이름, 나이, 몸무게, 키, 범죄명
	char name[256];
	printf("이름이 뭐에요? ");
	scanf_s("%s", name, sizeof(name));

	int age;
	printf("몇 살이에요? ");
	scanf_s("%d", &age);

	float weight;
	printf("몸무게는 몇 kg 이에요? ");
	scanf_s("%f", &weight);

	double height;
	printf("키는 몇 cm 이에요? ");
	scanf_s("%lf", &height);

	char what[256];
	printf("무슨 범죄를 저질렀어요? ");
	scanf_s("%s", what, sizeof(what));
	
	//조서 내용 출력
	printf("\n\n--- 범죄자 정보 ---\n\n");
	printf(" 이름    : %s\n", name);
	printf(" 나이    : %d\n", age);
	printf(" 몸무게  : %.2f\n", weight);
	printf(" 키      : %.2lf\n", height);
	printf(" 범죄    : %s\n", what);
	return 0;
}