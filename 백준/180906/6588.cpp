#include <iostream>
using namespace std;

bool check[1000001] = { false, true, false };

void prime()
{
	for (int i = 2; i*i <= 1000000; i++)
	{
		if (check[i] == false)
		{
			for (int j = i + i; j <= 1000000; j += i)
			{
				check[j] = true;
			}
		}
	}
}
int main()
{
	prime();

	while (true)
	{
		int N;
		bool ok = false;
		scanf("%d", &N);
		if (N == 0)
			break;

		for (int i = 3; i < N; i += 2)
		{
			if (check[i] == false && check[N - i] == false)
			{
				printf("%d = %d + %d\n", N, i, N - i);
				ok = true;
				break;
			}
		}
		if (ok == false)
			printf("Goldbach's conjecture is wrong\n");
	}
	return 0;
}