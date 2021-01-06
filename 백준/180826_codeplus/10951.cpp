/*
	scanf의 리턴값은 올바르게 입력받은 자료의 갯수
*/
#include <iostream>
using namespace std;

int main()
{
	int A, B;

	while (scanf("%d %d", &A, &B) == 2)
		printf("%d\n", A + B);

	return 0;
}