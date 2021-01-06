#include <iostream>
#include <algorithm>
using namespace std;

int arr[500001];

int main()
{
	int N;
	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &arr[i]);
	}

	sort(arr + 1, arr + N + 1);
	

	int M, target;
	scanf("%d", &M);

	for (int i = 0; i < M; i++)
	{
		int small = 1;
		int big = N;

		scanf("%d", &target);
		bool found = false;
		while (small <= big)
		{
			int mid = (big + small) / 2;

			if (arr[mid] < target)
				small = mid + 1;
			else if (arr[mid] > target)
				big = mid - 1;
			else
			{
				found = true;
				break;
			}
		}

		if (found) printf("1 ");
		else printf("0 ");
	}
	return 0;
}