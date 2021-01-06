/*
	idea : 첫번째 자릿수부터 맞춰가며 순열과 갯수를 찾아가면됨
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

long long facto(int n)
{
	long long sum = 1;
	for (int i = 1; i <= n; i++)
		sum *= i;
	return sum;
}

int main()
{
	int N, k;
	scanf("%d", &N);
	scanf("%d", &k);
	vector<int> arr(N);
	vector<int> order(N);
	for (int i = 0; i < N; i++) {
		arr[i] = i + 1;
		order[i] = i + 1;
	}

	if (k == 1)
	{
		long long M;
		scanf("%lld", &M);

		int index = 0;
		int index1 = 0;
		while (true)
		{
			while (!order[index1])
				index1++;
			int cur = order[index1];

			arr[index] = cur;

			if (facto(N - 1 - index) > M)
			{
				index++;
				order[index1] = 0;
				index1 = 0;
			}
			else if(facto(N - 1 - index) < M)
			{
				M -= facto(N - 1 - index);
				index1++;
			}
			else
			{
				order[index1] = 0;
				index++;
				index1 = N-1;
				while (index != N)
				{
					while (!order[index1])
						index1--;
					cur = order[index1];
					arr[index++] = cur;
					order[index1] = 0;
				}
				break;
			}
		}
		for (auto x : arr)
			printf("%d ", x);
	}
	else if (k == 2)
	{
		long long cnt = 0;
		for (int i = 0; i < N; i++)
			scanf("%d", &arr[i]);

		int index = 0;
		int index1 = 0;
		vector<int> ans(N);

		while (true)
		{
			if (order[index1] == arr[index])
			{
				ans[index] = arr[index];
				order[index1] = 0;
				index1 = 0;
				while (index1 < N && !order[index1])
					index1++;
				index++;
			}
			else if (order[index1] < arr[index])
			{
				cnt += facto(N - 1 - index);
				index1++;
				while (!order[index1])
					index1++;
			}
			if (index == N) break;
		}
		printf("%lld\n", cnt+1);
	}
	return 0;
}