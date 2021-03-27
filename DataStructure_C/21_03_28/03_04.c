#include<stdio.h>
#include<stdlib.h>


//자기참조구조체:구조체 포인터 변수가 포함된 구조체
typedef struct data {
	int int_data;
	double dbl_data;
	struct data* next; //자기참조구조체
}Node;

int main(void) {
	Node* data1 = (Node*)malloc(sizeof(Node));
	Node* data2 = (Node*)malloc(sizeof(Node));
	Node* data3 = (Node*)malloc(sizeof(Node));
	//data1구조체
	data1->int_data = 10;
	data1->dbl_data = 3.14;
	data1->next = data2;

	//data2구조체
//	data2->int_data = 20;
//	data2->dbl_data = 3.15;
//	data2->next = data3;
	data1->next->int_data = 20;
	data1->next->dbl_data = 3.15;
	data1->next->next = data3;

	//data3구조체
//	data3->int_data = 30;
//	data3->dbl_data = 3.16;
	data2->next->int_data = 30;
	data2->next->dbl_data = 3.16;


	printf("%d %.2f\n", data1->int_data, data1->dbl_data);
	printf("%d %.2f\n", data1->next->int_data, data1->next->dbl_data);
	printf("%d %.2f\n", data1->next->next->int_data, data1->next->next->dbl_data);
	
	free(data1);
	free(data2);
	free(data3);

	return 0;
}
