#include<stdio.h>
#include<stdlib.h>

typedef struct data {
	int data; //다루고자 하는 값에 따라 결정
	struct data* link;
}Stack;

Stack* getNode(void) {
	Stack* newNode = (Stack*)malloc(sizeof(Stack));
	newNode->data = 0;
	newNode->link = NULL;
	return newNode;
}

void push(Stack** top, int data)
{
	//포인터변수:일반변수에 대한 값의 사용(매개변수) / 값의저장(반환처리)
	//이중포인터변수: 일반변수 + 포인터변수에 대해 기능을 수행할 수 있음
	Stack* tmp = *top;
	*top = getNode();
	(*top)->data = data;
	(*top)->link = tmp;
}

int pop(Stack** top)
{
	if (*top == NULL)
		return 0;
	int result = (*top)->data;;
	Stack* tmp = *top;
	*top = (*top)->link;
	free(tmp);
	return result;
}

void print_Stack(Stack* top) {
	Stack* tmp = top;
	while (tmp != NULL) {

		printf("%d ", tmp->data);
		
		tmp = tmp->link;
	}
}

void clear1(Stack** top) {
	while (*top != NULL) {
		pop(top);
	}
}

void clear2(Stack* top) {
	while (top != NULL) {
		Stack* tmp = top;
		top = top->link;
		free(tmp);
	}
}

int main(void)
{
	
	Stack* top = NULL;
	push(&top, 10);
	push(&top, 20);
	push(&top, 30);
	push(&top, 40);
	push(&top, 50);
	
	print_Stack(top);
	printf("\n");
	//1.삭제, top도 같이 변경
	//clear1(&top); 언제든지 실행가능한 코드
	//clear2(top); 종료시점에 실행하는 코드
	printf("pop:%d", pop(&top));
	return 0;
}
