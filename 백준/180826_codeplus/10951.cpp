/*
	scanf�� ���ϰ��� �ùٸ��� �Է¹��� �ڷ��� ����
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