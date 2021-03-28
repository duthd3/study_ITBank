#include<stdio.h>

int get_sum_while(int limit)
{
	int num = 1;
	int result1 = 0;
	while (num <= limit)
	{
		result1 += num;
		num++;
	}
	return result1;
}

int get_sum_recur(int num, int limit)
{	
	if (num <= limit) {
		return num + get_sum_recur(num + 1, limit);
	}
	else
		return 0;
	
}
int main(void)
{
	//재귀함수 : 함수를 통해 구현되는 while 반복문
	//while : 조건식/증감식 등이 부정확하면 무한반복이 일어난다.
	//->조건식을 제어할 수 있도록 증감식 등을 설정
	//->기준이 되는 위치가 바뀌지 않는 형태일 때 사용
	//->특정 규칙성을 가지느 코드를 반복시킬 때

	//재귀함수 : 조건식/증감식 등이 부정확하면 Stack Overflow 에러가 발생한다.
	//->조건문을 통해 제어가 되도록 설정(탈출조건)
	//->기준의 위치가 바뀌지만, 반복되는 형태일 때 사용
	//->특정 규칙성을 가지는 알고리즘 반복시킬 때

	int num = 1;
	int result1 = get_sum_while(10);
	int result2 = get_sum_recur(1, 10);
	printf("%d \n", result1);
	printf("%d \n", result1);
	return 0;
}
