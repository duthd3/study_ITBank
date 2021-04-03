#include<stdio.h>
#include<stdlib.h>

typedef struct data {
	int data;
	struct data* link;
}List;
void Insert(List** head, int data1, int data2);
List* getNode(void) {
	List* newNode = (List*)malloc(sizeof(List));
	newNode->data = 0;
	newNode->link = NULL;
	return newNode;
}
void add(List** head, int data) {
	if (*head == NULL) {
		*head = getNode();
		(*head)->data = data;
	}
	else add(&(*head)->link, data);
}
void Insert(List** head, int data1, int data2)
{
	if ((*head) == NULL) {
		printf("입력된 데이터가 없습니다.\n");
		return;
	}
	//1단계 data1의 위치를 찾는다?
	else if ((*head)->data == data1) {
		List* tmp = getNode();
		tmp->data = data2;
		tmp->link = (*head)->link;
		(*head)->link = tmp;
	}//2단계 아닐경우 다음노드 계속해서 다음노드 확인?
	else {
		if ((*head)->link == NULL) {
			printf("%d를찾을수없습니다.\n", data1);
			return;
		}
		Insert(&(*head)->link, data1, data2);
		
	}
}
void modify(List** head, int find_data, int mod_data)
{
	if ((*head) == NULL) {
		printf("입력된 데이터가 없습니다.\n");
		return;
	}
	else if ((*head)->data == find_data)
	{
		(*head)->data = mod_data;
	}
	else {
		if ((*head)->link == NULL) {
			printf("%d를 찾을수 없습니다.\n", find_data);
			return;
		}
		modify(&(*head)->link, find_data, mod_data);
	}

}
void del(List** head, int find_data)
{
	if ((*head) == NULL)
	{
		printf("입력된 데이터가 없습니다.\n");
		return;
	}
	//첫번째 데이터 삭제할때
	List* tmp = *head;
	if (tmp->data == find_data)
	{
		*head = tmp->link;
		free(tmp);
	}//두번째 이후 데이터 삭제할때
	else if (tmp->data != find_data) {
		if ((*head)->link == NULL) {
			printf("%d를 찾을수 없습니다.\n", find_data);
			return;
		}
		del(&(*head)->link, find_data);
	}
}
void print_list(List* head)
{
	if (head == NULL) {
		printf("출력할 값이 없습니다.\n");
	}
	
	while (head != NULL) {
		printf("%d ", head->data);
		head = head->link;
	}
	
}
void clear(List* head)
{
	
	while (head != NULL) {
		List *tmp = head;
		head = (head)->link;
		free(tmp);
		
	}
	
}
int main(void) {
	//자기참조구조체를 이용해 만들어낸 특정 선형연결
	//Linked List(구현체:연결리스트)
	//배열처럼 값이 나열되어 있으면서, 기능이 훨씬 더 
	//많고 크기도 훨씬 더 자유로운 자료구조
	//Link List(자료구조:연결리스트)
	List* head = NULL;//배열의 선두역할
	add(&head, 10);
	add(&head, 20);
	add(&head, 30);
	add(&head, 40);

	
	
/*	del(&head, 10);
	del(&head, 20);
	del(&head, 30);
	del(&head, 40);*/
	clear(head);
	
	print_list(head);
	
	
	return 0;
}
