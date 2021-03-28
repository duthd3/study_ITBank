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

void enQueue(Queue** front, Queue** rear, int data) { //새로운 값을 기존 값의 꼬리에 물린다.
	Queue* tmp = getNode(); //tmp가 새 노드를 가리킨다.
	tmp->data = data;
	if (*front == NULL) { //처음 데이터를 저장할때
		
		*front = tmp; //front가 tmp가 가리키는 새 노드를 가리킨다.
		*rear = tmp; // rear가 tmp가 가리키는 새 노드를 가리킨다.		
	}
	else {//두번째 이후 데이터를 저장할때
		
		(*rear)->link = tmp; //마지막 노드의 link가 새노드를 가리킨다.
		(*rear) = tmp; //rear가 새 노드를 가리킨다.		
		
	}
}
// enQueue : 최초로 값을 넣을 때를 위해 front가 존재
int deQueue(Queue** front, Queue** rear) {
	if (*front == NULL)
		return 0;
	Queue* tmp = *front; //삭제할 노드의 주소값 저장
	int data = (*front)->data;
	*front = (*front)->link; //삭제할 노드의 다음노드를 front가 가리킨다
	if (*front == NULL) {
		*rear = *front;
		
	}
	free(tmp);//삭제할 노드 소멸

	return data;
}
//deQueue : 값을 다 뺏을 때를 위해 rear가 존재
void clear(Queue* front) {
	
	while (front != NULL)
	{
		Queue* tmp = front;
		front = front->link;
		free(tmp);
		
	}
}
void print_Queue(Queue* front) {
	Queue* tmp = front;
	if (tmp == NULL)
		printf("출력할 값이 없습니다.\n");
	while (tmp != NULL) {
		printf("%d ", tmp->data);
		tmp = tmp->link;
	}
	
}

int main(void)
{
	Queue* front = NULL;
	Queue* rear = NULL;
	enQueue(&front, &rear,10);
	enQueue(&front, &rear,20);
	enQueue(&front, &rear,30);
	clear(front);
	print_Queue(front);
	
	
	return 0;
	

	



}
