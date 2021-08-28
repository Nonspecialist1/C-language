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
// 프로젝트 
// 물고기 6마리가 있어요, 이들은 사막에 있는 어항 속에 있어요, 사막이 너무 덥고 건조해서 물이 아주 빨리 증발해요
// 물이 다 증발하기 전에 부지런히 어항에 물을 줘서 물고기를 살려주세요, 물고기는 시간이 갈수록 점점 커져서...나중에는 냠냠...

int main(void) {
	/*
	// 포인터
	// [철수] : 101호
	// [영희] : 201호
	// [민수] : 301호
	// 각 문 앞에 암호가 있음
	int 철수 = 1;
	int 영희 = 2;
	int 민수 = 3;

	printf("\n철수네 주소 : %d,  암호 : %d\n", &철수, 철수);
	printf("\n영희네 주소 : %d,  암호 : %d\n", &영희, 영희);
	printf("\n민수네 주소 : %d,  암호 : %d\n", &민수, 민수);
	// 미션맨 !
	// 1번째 미션 : 아파트의 각 집에 방문하여 문에 적힌 암호 확인 
	int* 미션맨; //포인터 함수
	미션맨 = &철수;
	printf("\n미션맨이 방문하는 주소 : %d,  암호 : %d\n", 미션맨, *미션맨);
	미션맨 = &영희;
	printf("\n미션맨이 방문하는 주소 : %d,  암호 : %d\n", 미션맨, *미션맨);
	미션맨 = &민수;
	printf("\n미션맨이 방문하는 주소 : %d,  암호 : %d\n", 미션맨, *미션맨);

	// 2번째 미션 : 각 암호에 3을 곱해라
	미션맨 = &철수;
	*미션맨 = *미션맨 * 3;
	printf("\n미션맨이 암호를 바꾼 주소 : %d,  암호 : %d\n", 미션맨, *미션맨);

	미션맨 = &영희;
	*미션맨 = *미션맨 * 3;
	printf("\n미션맨이 암호를 바꾼 주소 : %d,  암호 : %d\n", 미션맨, *미션맨);

	미션맨 = &민수;
	*미션맨 = *미션맨 * 3;
	printf("\n미션맨이 암호를 바꾼 주소 : %d,  암호 : %d\n", 미션맨, *미션맨);

	// 스파이, 미션맨이 바꾼 암호에서 2를 빼라 !
	int* 스파이 = 미션맨;
	printf("\n...스파이가 미션을 수행하는 중...\n\n");

	스파이 = &철수;
	*스파이 = *스파이 - 2; // 철수 = 철수 - 2와 동일한 식
	printf("스파이가 방문하는 주소 : %d,  암호 : %d\n", 스파이, *스파이);

	스파이 = &영희;
	*스파이 = *스파이 - 2; // 철수 = 철수 - 2와 동일한 식
	printf("스파이가 방문하는 주소 : %d,  암호 : %d\n", 스파이, *스파이);

	스파이 = &민수;
	*스파이 = *스파이 - 2; // 철수 = 철수 - 2와 동일한 식
	printf("스파이가 방문하는 주소 : %d,  암호 : %d\n", 스파이, *스파이);

	printf("\n...철수 영희 민수는 집에 오고서는 바뀐 암호를 보고 깜놀...\n\n");
	printf("\n철수네 주소 : %d,  암호 : %d\n", &철수, 철수);
	printf("\n영희네 주소 : %d,  암호 : %d\n", &영희, 영희);
	printf("\n민수네 주소 : %d,  암호 : %d\n", &민수, 민수);
	//참고로 미션맨이 사는 곳의 주소는 &미션맨으로 확인
	printf("\n미션맨의 주소 : %d\n", &미션맨);
	printf("\n스파이의 주소 : %d\n", &스파이);
	
	// 배열
	int arr[3] = { 5, 10, 15 };
	int* ptr = arr;
	
	for (int i = 0; i < 3; i++) {
		printf("배열 arr[%d]의 값 : %d\n", i, arr[i]);
	}
	for (int i = 0; i < 3; i++) {
		printf("포인트 ptr[%d]의 값 : %d\n", i, ptr[i]);
	}
	ptr[0] = 100;
	ptr[1] = 200;
	ptr[2] = 300;
	for (int i = 0; i < 3; i++) {
		//printf("배열 arr[%d]의 값 : %d\n", i, arr[i]);
		printf("배열 arr[%d]의 값 : %d\n", i, *(arr + i));
	}
	for (int i = 0; i < 3; i++) {
		//printf("배열 arr[%d]의 값 : %d\n", i, ptr[i]);
		printf("포인터 ptr[%d]의 값 : %d\n", i, *(ptr + i));
	}
	// *(arr + i) == arr[i] 같은 표현
	// arr == arr 배열의 첫번째 값의 주소와 동일 == &arr[0]
	printf("arr 자체의 값 : %d\n", arr);
	printf("arr[0]의 주소 : %d\n", &arr[0]);

	printf("arr 자체의 값이 가지는 주소의 실제 값 : %d\n", *arr); // *(arr + 0)과 같다
	printf("arr[0]의 실제 값 : %d\n", *&arr[0]);

	// *&는 아무것도 없는 것과 같다. &는 주소이고 *는 그 주소의 값이기 때문에 서로 상쇄된다.
	printf("arr[0]의 실제 값 : %d\n", *&*&*&*&*&*&arr[0]);
	printf("arr[0]의 실제 값 : %d\n", arr[0]);
	
	// SWAP 값을 바꾸다
	int a = 10;
	int b = 20;
	printf("a의 주소 : %d\n", &a);
	printf("b의 주소 : %d\n", &b);

	// a와 b의 값을 바꾸다
	printf("SWAP 함수 전 => a : %d,  b : %d\n", a, b);
	swap(a, b);
	printf("SWAP 함수 후 => a : %d,  b : %d\n", a, b);
	
	// 값에 의한 복사(Call by Value) -> 값만 복사한다는 의미
	// 주소값을 넘기면? 메모리 공간에 있는 주소값 자체를 넘긴다,,철수네처럼 
	printf("(주소값 전달)SWAP 함수 전 => a : %d,  b : %d\n", a, b);
	swap_addr(&a, &b);
	printf("(주소값 전달)SWAP 함수 후 => a : %d,  b : %d\n", a, b);
	
	//배열일 때 arr2 -> 주소 
	int arr2[3] = { 10, 20, 30 };
	changeArray(&arr2[0]); // changeArray(arr2);
	for (int i = 0; i < 3; i++) {
		printf("%d\n", arr2[i]);
	}
	*/

	// 프로젝트 
	long startTime = 0; // 게임 시작 시간
	long totalElapsedTime = 0; // 총 경과 시간
	1

	long prevElapsedTime = 0; // 직전 경과 시간(최근에 물을 준 간격)

	int num; // 몇 번 어항에 물을 줄 것인지, 사용자 입력
	initData();
	
	cursor = arrayFish; // cursor[0]....cursor[1]

	startTime = clock(); // 현재시간을 millisec(1000분의 1초) 단위로 반환
	while (1) {
		printfFishes();
		printf("몇 번 어항에 물을 주시겠어요? ");
		scanf_s("%d", &num);
		// 입력값 체크
		if (num < 1 || num > 6) {
			printf("\n 입력값이 잘못되었습니다\n");
			continue;
		}

		totalElapsedTime = (clock() - startTime) / CLOCKS_PER_SEC;
		printf("총 경과 시간 : %ld 초\n", totalElapsedTime);

		// 직전에 물을 줬던 시간 이후로 흐른 시간 
		prevElapsedTime = totalElapsedTime - prevElapsedTime;
		printf("최근 경과 시간 : %ld 초\n", prevElapsedTime);

		// 어항의 물 감소(증발)
		decreaseWater(prevElapsedTime);

		// 사용자가 입력한 어항에 물을 준다 
		// 1번 어항의 물이 0이면? 물을 줄 필요가 없다
		if (cursor[num - 1] <= 0) {
			printf("%d번 물고기는 이미 죽었습니다...물을 줄 필요가 없습니다\n", num);
		}
		// 2번 어항의 물이 0이 아닌 경우? 물을 줘야한다, 100을 넘지 않는지 체크 
		else if (cursor[num - 1] + 1 <= 100) {
			printf("%d번 어항에 물을 줍니다\n\n", num);
			cursor[num - 1] += 1;
		}
		// 레벨업을 할 건지 확인(레벨업은 20초마다 한 번씩 수행)
		if (totalElapsedTime / 20 > level - 1) {
			level++;
			printf("*** 축 레벨업 ! 기존 %d 레벨에서 %d 레벨로 업그레이드 ***\n\n", level -1, level);
			// 최종 레벨 : 5
			if (level == 5) {
				printf("\n\n축하합니다. 최고 레벨을 달성하였습니다. 게임을 종료합니다 !\n\n");
				exit(0);
			}
		}
		// 모든 물고기가 죽었는지 확인
		if (checkFishAlive() == 0) {
			// 물고기가 모두 죽음
			printf("모든 물고기가 죽었어요 !\n");
			exit(0);
		}
		else {
			// 물고기 1마리 이상 생존
			printf("물고기가 아직 살아있어요 !\n");
		}
		prevElapsedTime = totalElapsedTime;
	}

	return 0;
} 

void initData() {
	level = 1; // 게임 레벨(1~5)
	for (int i = 0; i < 6; i++) {
		arrayFish[i] = 100; //어항의 물 높이(0~100)
	}
}
void printfFishes() {
	printf("%3d번 %3d번 %3d번 %3d번 %3d번 %3d번\n", 1, 2, 3, 4, 5, 6);
	for (int i = 0; i < 6; i++) {
		printf(" %4d ", arrayFish[i]);
	}
	printf("\n\n");
}
void decreaseWater(long elapsedTime) {
	for (int i = 0; i < 6; i++) {
		arrayFish[i] -= (level * 3 * (int)elapsedTime); // 3은 난이도 조절을 위한 값
		if (arrayFish[i] < 0) {
			arrayFish[i] = 0;
		}
	}
}
int checkFishAlive() {
	for (int i = 0; i < 6; i++) {
		if (arrayFish[i] > 0) {
			return 1; // 참으로 반환
		}
		return 0;
	}
}

/*
void swap(int a, int b){
	printf("(SWAP 함수 내) a의 주소 : %d\n", &a);
	printf("(SWAP 함수 내) b의 주소 : %d\n", &b);

	int temp = a;
	a = b;
	b = temp;
	printf("SWAP 함수 내 => a : %d,  b : %d\n", a, b);
}
void swap_addr(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
	printf("(주소값 전달)SWAP 함수 내 => a : %d,  b : %d\n", *a, *b);
}
void changeArray(int* ptr) {
	ptr[2] = 50;
}
*/