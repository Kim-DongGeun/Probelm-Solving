#include <iostream>
using namespace std;

int main()
{
	int N;
	scanf("%d", &N);

	int ans = 1;
	for (int i = 1; i <= N; i++)
		ans *= i;
	printf("%d\n", ans);
	return 0;
}