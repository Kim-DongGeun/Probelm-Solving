#include <iostream>
using namespace std;

int main()
{
	char c;

	//getchar 개행문자포함 한글자씩 입력받음
	while ((c = getchar()) && c != EOF)
		printf("%c", c);

	return 0;
}