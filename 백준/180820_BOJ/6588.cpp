#include <iostream>
using namespace std;

int arr[1000001] = { 0, };

void cal() // �Ҽ����ϱ� �����佺�׳׽��� ü
{
	for (int i = 2; i*i < 1000001; i++)
	{
		if (!arr[i])
		{
			for (int j = i * i; j < 1000001; j += i)
				arr[j] = 1;
		}
	}
}

int main()
{
	int N;

	cal();

	while (scanf("%d", &N) && N)
	{
		for (int i = 3; i < N ; i += 2)
		{
			if (!arr[i] && !arr[N - i])
			{
				printf("%d = %d + %d\n", N, i, N - i);
				break;
			}
		}
	}

	return 0;
}