/*
	idea : stl을 쓰면 편함
*/
#include <iostream>
#include <vector>
using namespace std;

vector<int> arr(10000);
int N;

bool pre_permutation()
{
	int k = N - 1;
	int j = N - 1;

	for (int i = 1; i < N; i++)
	{
		if (arr[k - 1] > arr[k]) break;
		else k--;
	}
	if (!k) return false;

	for (; k <= j; j--)
	{
		if (arr[j] < arr[k - 1]) break;
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
		scanf("%d", &arr[i]);

	if (pre_permutation())
		for (int i = 0; i < N; i++)
			printf("%d ", arr[i]);
	else printf("-1\n");
	return 0;
}