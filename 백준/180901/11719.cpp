#include <iostream>
using namespace std;

int main()
{
	char c;

	//getchar ���๮������ �ѱ��ھ� �Է¹���
	while ((c = getchar()) && c != EOF)
		printf("%c", c);

	return 0;
}