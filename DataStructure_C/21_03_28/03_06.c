#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>


typedef struct data {
	int data;
	struct data* next;
}Stack; // 자기참조구조체
//Node : 자료구조에 자료를 저장하고 있는 단위

Stack* getNode(void); // 구조체를 생성/초기화

void push(Stack** top, int data);//자료를 저장
int peek(Stack* ftop);
int pop(Stack** top); //자료를 꺼낸다(구조체제거&값을 복사)
int main(void)
{
	
	Stack* top = NULL;	

/*	push(&top, 10);
	push(&top, 20);
	
	printf("top->data: %d\n", top->data);
	printf("top->next->data: %d\n", top->next->data);
	
	int data;

	data = pop(&top);
	printf("pop:%d\n", data);

	data = pop(&top);
	printf("pop:%d\n", data);

	data = pop(&top);
	printf("pop:%d\n", data);*/

	int num;
	int pn;
	int data;
	
	while (1) {
		printf("*****1.push  2.pop 3.스택전체 출력 3.종료*****\n");
		scanf("%d", &num);
		if (num == 1) //push 선택
		{
			printf("push할 값 입력:");
			scanf("%d", &pn);
			push(&top, pn); //push
			
		}
		else if (num == 2) { //pop 선택
			data = pop(&top); //pop
			if (data == -1) { //더이상 삭제할 데이터가 없을경우
				printf("No data!\n");
				continue;
			}			
			printf("pop:%d\n", data);
		}
		else if (num == 3) { //전체출력!
			
			int re;
			
			while (1) {
				re=peek(&top);
				if (re == -1)
					break;

				printf("%d ", re);
				
			}
			printf("\n");
		}
		else //종료
			return -1;

	}

	return 0;
}

//push:구조체에 전달받은 값을 저장한다.
void push(Stack** top, int data)
{
	Stack* tmp = *top;
	*top = getNode();
	(*top)->data = data;
	(*top)->next = tmp;
}

Stack* getNode(void)
{
	Stack* newNode = (Stack*)malloc(sizeof(Stack));
	newNode->data = 0;
	newNode->next = NULL;
	return newNode;
}

int pop(Stack** top)
{
	if (*top == NULL) {
		
		return -1;
	}
	int result;
	Stack* tmp = *top;
	result = (*top)->data;
	*top = (*top)->next;
	
	free(tmp);
	return result;
}
int peek(Stack** top)
{
	if ((*top) == NULL)
		return -1;
	int d;
	Stack* ftop = *top;
	d = ftop->data;
	(*top)= (*top)->next;
	
	return d;
}
