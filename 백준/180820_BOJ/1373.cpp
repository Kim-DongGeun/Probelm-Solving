#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	char a[1000002] = { '0', '0' };

	scanf("%s", a + 2);

	int num = strlen(a);

	for (int i = num % 3; i < num; i += 3)
		printf("%d", (a[i] - '0') * 4 + (a[i + 1] - '0') * 2 + (a[i + 2] - '0'));

	return 0;
}