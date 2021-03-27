#include<stdio.h>

//구조체 : 값을 보관 / 보관된 값의 사용이 목적
//변수의 한계를 극복(배열)
//배열 : '하나의 값만 저장할 수 있다'를 극복하는 것이 목적
//구조체 : 자료형의 한계를 극복
//구조체 : '한 종류의 값만 취급할 수 있다'를 극복하는 것

typedef struct data1 {
	//만들기 위해서는 내부에 무엇을 보관할 것인가?
	char name[11];
	int age;
	double height;
	double weight;
	//선언만 가능하고, 초기화는 불가능
}Node;

int main(void) {
	Node man1;
	Node man2 = { "홍길동", 36, 177.7, 98.8 };
	//구조체 변수 그 자체는 값 덩어리
	//man2 변수 그자체는 사용불가
	//구조체는 내부에 있는 값을 적절하게 불러와야 한다
	// -> 구조체를 정의할 때 만든 변수로 값에 접근
	// -> 해당 변수의 종류에 따른 특징을 모두 준수한다.
	printf("이름\t: %s\n", man2.name);
	printf("나이\t: %d\n", man2.age);
	printf("키\t: %.1f\n", man2.height);
	printf("몸무게\t: %.1f\n", man2.weight);
	man1 = man2; //값을 자동으로 복사처리한다
	printf("%s %s \n", man1.name, man2.name);

	

}
