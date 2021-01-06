#include <iostream>
using namespace std;

int main()
{
	char input[100];

	while (scanf("%10s", input) == 1)
		printf("%s\n", input);
	return 0;
}