#include <iostream>
using namespace std;

int main()
{
	int N;
	int a;
	scanf("%d", &N);

	int sum = 0;
	while (N--)
	{
		scanf("%1d", &a);
		sum += a;
	}
	printf("%d\n", sum);
}