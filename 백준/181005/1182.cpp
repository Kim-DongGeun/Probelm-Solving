/*
	idea : 모든수열을 구해서 전부 더해서 비교해본다
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int N, S, ans = 0;
vector<int> arr(20);
vector<int> order(20, 0);

void cal(int depth, int n)
{
	if (depth == n)
	{
		int sum = 0;
		for (int i = 0; i < depth; i++)
		{
			if (order[i]) sum += arr[i];
		}
		if (sum == S) ans++;
		return;
	}

	order[n] = 1;
	cal(depth, n + 1);
	order[n] = 0;
	cal(depth, n + 1);
}

int main()
{
	
	scanf("%d %d", &N, &S);
	
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	cal(N, 0);

	if (S == 0) ans--;
	printf("%d\n", ans);
	return 0;
}