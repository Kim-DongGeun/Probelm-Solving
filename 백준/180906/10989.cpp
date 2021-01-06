#include <iostream>
using namespace std;

int main()
{
	int arr[10001] = { 0 };
	int N;
	scanf("%d", &N);

	for(int i = 0 ; i < N; i++)
	{
		int a;
		scanf("%d", &a);
		arr[a]++;
	}

	for (int i = 1; i <= 10000; i++)
	{
		for (int j = 0; j < arr[i]; j++)
			printf("%d\n", i);
	}
	return 0;
}