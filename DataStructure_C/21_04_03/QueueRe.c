#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct data {
	int data;
	struct data* link;
}Queue;

Queue* getNode(void) {
	Queue* newNode = (Queue*)malloc(sizeof(Queue));
	newNode->data = 0;
	newNode->link = NULL;
	return newNode;
}

void enQueue(Queue** front, Queue** rear, int data)
{
	Queue* tmp = getNode();
	tmp->data = data;
	if (*rear == NULL) {//최초로 값을 넣을때
		*front = tmp;
		*rear = tmp;
	}
	else {//두번째 이후로 값을 넣을때
		(*rear)->link = tmp;
		(*rear) = tmp;
	}

}

int deQueue(Queue** front, Queue** rear) 
{
	if (*front == NULL)
	{
		return -1;
	}
	int data = (*front)->data;
	Queue* tmp = *front;
	(*front) = (*front)->link;
	if(*front==NULL)
	{
		*rear = *front;
	}
	free(tmp);
	return data;
}
int input_data(void) {
	int data;
	scanf("%d", &data);
	return data;
}
void print_Queue(Queue* front) {
	if (front == NULL)return;
	printf("%d ", front->data);
	print_Queue(front->link);
}
int main(void)
{
	Queue* front = NULL;
	Queue* rear = NULL;
	int data;
	int result;
	for (int i = 1; i < 11; i++)
	{
		printf("%d번째 값 입력: ", i);
		data = input_data();
		enQueue(&front, &rear, data);
	}
	print_Queue(front);
	while (front->link != NULL)
	{
		deQueue(&front, &rear);//버림
		int tmp = deQueue(&front, &rear);//뒤로
		enQueue(&front, &rear, tmp);//뒤로


	}
	//print_Queue(front);
	return 0;
}
