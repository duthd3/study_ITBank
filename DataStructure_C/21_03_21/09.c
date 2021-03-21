#include<stdio.h>
#include<stdlib.h>

int* reallocation1(int* pnum, int size)
{
	int* tmp = (int*)realloc(pnum, size);
	if (tmp == NULL) {
		printf("동적할당 실패\n");
	}
	else
		pnum = tmp;
	return pnum;
}
// 포인터변수: 매개변수 + 반환역할을 동시에 수행
// 이중포인터: 자료형이 맞지 않기 때문에 사용하는 것
// -> 대상 변수의 값을 바꾸는 것이 목적이면 의미 없음
// -> 대상 포인터변수의 값도 바꾸면서, 포인터변수가 가리키는 공간의 값도 불러오고
// 바꾸는 용도: 이중포인터
void reallocation2(int** pnum, int size)
{
	int* tmp = (int*)realloc(pnum,  size);
	if (tmp == NULL) {
		printf("동적할당 실패\n");
	}
	else
		*pnum = tmp;
	
}

int main_0209(void) {
	//realloc : 재할당
	//동적할당시 주의사항: 0이하로 들어가면 안된다.
	//int*pnum = (int*)malloc(0)  X

	int size = 3;
	int* pnum = (int*)malloc(sizeof(int) * size);
	for (int i = 0; i < size; i++) {
		pnum[i] = i + 1;
	}

	//realloc : 기존 값을 그대로 복사, 공간을 확장/축소
	//기존 공간은 할당해제처리가 된다.
	//#잘못된 사용방식
	//pnum = (int*)realloc(pnum, sizeof(int) * 10);
	pnum = reallocation1(pnum, 1000);
	reallocation2(&pnum, 10);
	free(pnum);
	return 0;
}
