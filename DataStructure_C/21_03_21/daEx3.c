#include<stdio.h>
#include<malloc.h>

void Add(int* pnum1, double* pnum2);
void Avg(int* pnum1, double* pnum2);
int main_Ex3(void)
{
	int num1;
	double num2;
	int* pnum1 = (int*)malloc(sizeof(int));
	double* pnum2 = (double*)malloc(sizeof(double));

	printf("정수값 입력:");
	scanf_s("%d", &num1);

	*pnum1 = num1;

	printf("실수값 입력:");
	scanf_s("%lf", &num2);

	*pnum2 = num2;

	Add(pnum1, pnum2);
	Avg(pnum1, pnum2);

	free(pnum1);
	free(pnum2);
	return 0;
}

void Add(int* pnum1, double* pnum2)
{
	printf("두 수의 합:%f\n", (double)*pnum1 + *pnum2);
}

void Avg(int* pnum1, double* pnum2)
{
	printf("두 수의 평균:%f\n", ((double)*pnum1 + *pnum2)/2);
}
