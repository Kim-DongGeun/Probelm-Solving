/*
	idea : 주어진 범위에서 같은지 확인하고 같이 않으면 다시 9개로 나누어서
		   같은지 확인한다
*/
#include <iostream>
using namespace std;

int arr[2188][2188];
int cnt[3] = { 0 };


bool same(int x, int y, int n)
{
	for(int i = y; i < y + n; i++)
		for (int j = x; j < x + n; j++)
		{
			if (arr[y][x] != arr[i][j])
				return false;
		}
	return true;
}

void solve(int x, int y, int n)
{
	if (same(x, y, n))
	{
		cnt[arr[y][x] + 1]++;
		return;
	}
	int m = n / 3;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			solve(x + j * m, y + i * m, m);
}

int main()
{
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &arr[i][j]);

	solve(0, 0, N);

	for (int x : cnt)
		printf("%d\n", x);
	return 0;
}