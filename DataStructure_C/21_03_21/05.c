#include<stdio.h>

int main_0205(void)
{
	//포인터변수 이용해 배열을 다루는 방법 : 똑같은 방법을 사용한다.
	// 배열변수: 값이 있는 공간을 저장하고 있는 변수
	int arr[3] = { 4,5,6 };

	//포인터변수: 자신의 크기정보 + 값을 바꿀 수 있음

	int* parr = arr;	
	printf("%d, %d\n", arr[1], *(parr + 1));
	return 0;
}
