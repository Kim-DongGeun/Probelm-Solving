/*
	idea : 모든순열을 구할때에는 do while문은 많이 쓴다.
*/
#include <iostream>
using namespace std;

int arr[8];
int N;

bool next_permutation()
{
	int k = N - 1;
	int j = N - 1;

	for (int i = 1; i < N; i++)
	{
		if (arr[k - 1] < arr[k]) break;
		else k--;
	}
	if (!k) return false;

	for (; k <= j; j--)
	{
		if (arr[j] > arr[k - 1]) break;
	}

	swap(arr[k - 1], arr[j]);

	for (int i = 0; i < (N - k) / 2; i++)
		swap(arr[k + i], arr[N - i - 1]);

	return true;
}

int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		arr[i] = i + 1;

	do
	{
		for (int i = 0; i < N; i++)
			printf("%d ", arr[i]);
		printf("\n");
	} while (next_permutation());
	return 0;
}