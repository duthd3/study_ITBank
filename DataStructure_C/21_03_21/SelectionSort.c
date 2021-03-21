#include<stdio.h>

int main(void)
{
	int arr[10] = { 10,8,5,2,1,9,7,6,3,4 };
	int i, j;
	int temp;

	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9-i; j++) {
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	for (i = 0; i < 10; i++) {
		printf("%d ", arr[i]);
	}


	return 0;

}
