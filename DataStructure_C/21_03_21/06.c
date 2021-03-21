#include<stdio.h>
void print_arr(int* parr, int size)
{
	for (int i = 0; i < size; i++) {
		printf("%d ", parr[i]);
	}
}

int main_0206(void)
{
	int arr[3] = { 4,5,6 };
	int size = sizeof(arr) / sizeof(int);
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);

		
	}
	printf("\n");
	//배열을 다룰때 크기를 언제나 신경써야 한다.
	print_arr(arr, size);
	return 0;
}
