#include<stdio.h>

void recur(int limit, int num) {

	if (num < limit) {
		printf("반복중\n");
		num++;
		recur(limit, num);
	}
	else
		return;
}

int recur_2(int limit, int num) {
	int result = 0;	 
	
	if (num <= limit) {
		result += num;
		num += 2;
		return result + recur_2(limit, num);
	}
	else
		return 0;
	
		
}

int main(void)
{
	//단순 반복
	//재귀함수를 이용하여 내가 원하는 횟수만큼 반복하여 출력하도록 구성
	int result;
	recur(5, 0);	
	
	//수치의 반복
	//재귀함수를 이용하여 100까지의 2의 배수의 합을 구한다.
	result = recur_2(100, 2);
	printf("%d\n", result);
	
	return 0;
}
