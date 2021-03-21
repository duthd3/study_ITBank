#include<stdio.h>

void Swap_value(int* pnum1, int* pnum2) {
	*pnum1 = 20;
	*pnum2 = 60;

	//반환이 의미가 없어서 안붙인다.
}
	

//main함수의 int와 return 0는 os한테 프로그램이 정상종료 되었음을 알리기 위함.(규칙)
int main_0203(void)
{
	//c언어에서 콤마(,)가 연산자로써 하는 기능
	//=>연산식에서 서로다른 연산식을 연결시켜 한 줄로 붙여준다.
	//c언어의 함수는 반환값이 여러개가 될수없다!
	//포인터 변수가 함수에서 사용된다
	//매개변수와 return의 역할을 둘 다 수행할 수 있다
	
	//준비구간 + 입력구간
	int num1 = 10; //20->
	int num2 = 20; //60->
	printf("전 : %d, %d \n", num1, num2);
	
	//처리구간
	Swap_value(&num1, &num2);
	printf("후: %d, %d", num1, num2);
	return 0;
}
