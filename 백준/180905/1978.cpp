#include <iostream>
using namespace std;

int arr[1001];
bool c[1001] = { true, true, false };


void cal()
{
	for (int i = 2; i*i <= 1000; i++)
	{
		if (c[i] == false)
		{
			for (int j = i+i; j <= 1000; j += i)
			{
				c[j] = true;
			}
		}
	}
}


int main()
{
	for (int i = 1; i <= 100; i++)
		arr[i] = i;
	int N;
	scanf("%d", &N);
	cal();

	int ans = 0;
	while (N--)
	{
		int a;
		scanf("%d", &a);
		if (c[a] == false)
			ans++;
	}
	printf("%d\n", ans);
	return 0;
}