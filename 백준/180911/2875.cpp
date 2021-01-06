#include <iostream>
using namespace std;

int main()
{
	int N, M, K;

	scanf("%d %d %d", &N, &M, &K);

	while (K > 0)
	{
		if ((N / 2) >= M)
			N--;
		else
			M--;

		K--;
	}

	N / 2 < M ? printf("%d\n", N / 2) : printf("%d\n", M);
	return 0;
}