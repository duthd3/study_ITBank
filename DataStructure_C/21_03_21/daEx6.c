#include<stdio.h>
#include<stdlib.h>

void Input(double* darr, int size);
void output(double* darr, int size);

int main_Ex6(void)
{
	int size;
	printf("배열의 크기 지정:");
	scanf_s("%d", &size);

	double* darr = (double*)malloc(sizeof(double) * size); //배열을 동적할당(길이 size)

	Input(darr, size); //입력
	output(darr, size); //출력

	free(darr);//할당된 메모리 해제
	return 0;
}

void Input(double* darr, int size)
{
	int i;
	double num;
	for (i = 0; i < size; i++) {
		printf("실수%d 입력:", i+1);
		scanf_s("%lf", &num);
		darr[i] = num; //배열값 초기화
	}
}

void output(double* darr, int size)
{
	int i;
	double sum = 0.0;
	for (i = 0; i < size; i++) {
		printf("실수%d:%.1f ", i+1, darr[i]);
		sum += darr[i];
	}
	printf("\n");
	printf("평균: %.2f \n", sum / size);
}

