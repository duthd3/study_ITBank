#include<stdio.h>

void print_d_arr(double* d_arr, int size)//double형 배열을 인자로 받기 위함
{
	int i;
	for (i = 0; i < size; i++)
	{
		printf("%.1f ", d_arr[i]);
		if (i == 3)
			printf("\n");
		
	}
}

void print_c_arr(char* c_arr, int size)//char형 배열을 인자로 받기위함
{
	int i;
	for (i = 0; i < size; i++)
	{
		printf("%c", c_arr[i]);
		
	}
}
//포인터 변수 : 새로운 이름을 붙여서 사용하는 ㄴ과정
int main_Ex10(void)
{
	int size1, size2;

	double d_arr[8] = { 1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8 }; 
	size1 = sizeof(d_arr) / sizeof(double);

	print_d_arr(d_arr, size1);//d_arr출력

	printf("\n\n");

	char c_arr[6] = { 'A','B','C','D','E' };
	size2 = sizeof(c_arr) / sizeof(char);

	print_c_arr(c_arr, size2);//c_arr출력
	
	return 0;

}



