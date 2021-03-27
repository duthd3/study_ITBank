#include<stdio.h>

typedef struct data {
	int data1;
	int data2;
}Node;

int main(void) {
	//구조체로 배열을 만들었다:인덱스를 찍어서
	//지정한 구조체 변수에 있는 멤버변수 하나를 지정해서
	//쓰는 과정
	//배열의 생성 : 자료형 변수명 [크기]
	Node sarr[3] = { {10,20},{30,40},{50,60} };
	sarr[0].data1 = 80;
	sarr[0].data2 = 80;
	//포인터변수 만들기
	//배열
	Node* psarr;
	psarr = sarr; //배열을 포인터로 넘겨도 이름만 바꿔쓴다.
	psarr[0].data1 = 100;
	//단일변수
	//화살표 연산자를 이용해 변수를 지정해 사용
	Node data1 = { 99,0 };
	Node* pdata = &data1;
	(*pdata).data2 = 50;
	printf("%d\n", pdata->data2);

}
