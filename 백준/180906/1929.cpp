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
	int N, M;

	scanf("%d %d", &N, &M);

	//소수 구하기
	prime();

	for (int i = N; i <= M; i++)
	{
		if (check[i] == false)
			printf("%d\n", i);
	}
	return 0;
}