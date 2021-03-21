#include<stdio.h>

void Dswap(int** dptr1, int *ptr)
{
	
	*dptr1 = ptr; 
}




int main_0210(void)
{
	
	int num1 = 10;
	int num2 = 20;
	int* ptr1 = &num1;
	int* ptr2 = &num2;
	int** dptr1 = &ptr1;
	int** dptr2 = &ptr2;

	printf("*ptr: %d\n", *ptr1);

	Dswap(dptr1,&num2);

	printf("*ptr: %d\n", *ptr1);
	
	return 0;
}
