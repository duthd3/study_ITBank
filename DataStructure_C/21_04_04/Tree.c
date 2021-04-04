#include<stdio.h>
#include<stdlib.h>
//반복: 속도가 가장 빠름. 변수만 있어도 처리 가능
//재귀함수: 비선형으로 이루어진, 논리에 대응하는 것이 목적
//->반복되는 내용은 있지만, 규칙성이 존재하지 않는다
//이진탐색트리:크기를 기준으로 좌측우측으로 정렬되는 트리구조
typedef struct data {
	int data;
	struct data* left;
	struct data* right;
}Tree;
Tree* getNode(void)
{
	Tree* newNode = (Tree*)malloc(sizeof(Tree));
	newNode->data = 0;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}
void Insert(Tree** root, int data)
{//일정한 코드가 반복은 되지만, 비선형구조는
	//반복문으로 처리가 안된다. 논리에 대응해서 실행될 수 있도록 재쉬함수 사용.
	if (*root == NULL) {
		*root = getNode();
		(*root)->data = data;
	}
	else if (data < (*root)->data) {
		Insert(&(*root)->left, data);
	}
	else if (data > (*root)->data) {
		Insert(&(*root)->right, data);
	}
	else
		printf("중복된 값이 존재합니다.\n");
}
void Del(Tree** root, int data)
{
	
	if ((*root) == NULL) {
		printf("찾는값이 없습니다.\n");
	}
	else if (data < (*root)->data) {
		Del(&(*root)->left, data);
	}
	else if (data > (*root)->data) {
		Del(&(*root)->right, data);
	}
	else {//양쪽이 비어있을 때 실행되는 내용
		if ((*root)->left == NULL && (*root)->right == NULL) {
			free(*root);
			*root = NULL;
		}
		else if ((*root)->left != NULL && (*root)->right == NULL) {
			Tree* tmp= *root;
			*root = (*root)->left;
			free(tmp);
		}
		else if ((*root)->left == NULL && (*root)->right != NULL) {
			Tree* tmp = *root;
			*root = (*root)->right;
			free(tmp);
		}
		//한쪽만 연결되어 있을 때(left,right를 정확하게 구분한다)
		//현재 위치에, 남아있는 링크를 연결시킨다.
		//원래 있던 구조체는 동적할당해제한다.
	}
		
}
//전위순회:root에서 원하는 작업을 처리한 뒤 left부터 확인하고, 그 다음right를 확인한다.
void preOrder(Tree* root) {
	if (root == NULL) return;
		printf("%d ", root->data); //root
		preOrder(root->left);//left
		preOrder(root->right);//right
	
}
//중위순회:left부터 확인하고 root에서 원하는 작업을 처리한 뒤 right를 확인한다.
void InOrder(Tree* root) {
	if (root == NULL) return;
	InOrder(root->left);//left
	printf("%d ", root -> data);//root
	InOrder(root->right);//right
}
//후위순회:right부터 확인하고 root에서 원하는 작업을 처리한 뒤 left를 확인한다.
void  PostOrder(Tree* root) {
	if (root == NULL) return;
	PostOrder(root->right);//right
	printf("%d ", root->data);//root
	PostOrder(root->left);//left
}
int main(void)
{
	Tree* root = NULL;
	Insert(&root, 6);
	
	Insert(&root, 3);
	
	Insert(&root, 1);
	
	Insert(&root, 5);
	
	Insert(&root, 9);
	
	Insert(&root, 8);
	//전위순회
	preOrder(root);
	printf("\n");
	InOrder(root);
	printf("\n");
	PostOrder(root);
	return 0;
}
