#include<stdio.h>

void Swap(int* ptr1, int* ptr2) {
	int temp;
	temp = *ptr1; //num1의 값 temp에 저장
	*ptr1 = *ptr2; //num2의 값 num1에 저장
	*ptr2 = temp; //temp(num1)의 값 num2에 저장

	//return값이 2개 이상이 필요하기 때문에 포인터 변수 사용!
}
int main_0204(void)
{
	//두 변수의 값을 교체하는 함수
	//swap을 만들어보세요.
	
	int num1 = 10;
	int num2 = 20;
	
	printf("전:%d, %d \n", num1, num2);
	
	Swap(&num1, &num2); //num1과 num2의 값 swap
	printf("후:%d, %d \n", num1, num2);
	return 0;
}
