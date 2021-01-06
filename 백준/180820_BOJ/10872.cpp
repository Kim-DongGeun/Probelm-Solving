#include <iostream>
using namespace std;

int main()
{
	int N, answer = 1;
	cin >> N;

	if (!N)
	{
		printf("1\n");
		return 0;
	}

	while (N)
	{
		answer *= N;
		N--;
	}

	printf("%d\n", answer);
	return 0;
}