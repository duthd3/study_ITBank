#include<stdio.h>
#include<stdlib.h>

int main_0208(void) {
	int size;
	int* parr;
	printf("배열의 크기를 입력:");
	scanf_s("%d", &size);
	//동적할당으로 배열생성시, 크기를 곱하기 형태로 분리해서 처리
	
	parr = (int*)malloc(sizeof(int) * size);
	for (int i = 0; i < size; i++)
	{
		parr[i] = i + 1;
	}
	for (int i = 0; i < size; i++)
	{
		printf("%d ", parr[i]);
	}
	free(parr);

}
