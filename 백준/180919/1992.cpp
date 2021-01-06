/*
	idea : �־��� ĭ�� ������ Ȯ���ϰ� �ٸ��� 4���� ����� �ٽ� Ȯ���ϴ� ������ �ݺ��Ѵ�.
*/
#include <iostream>
using namespace std;

int arr[64][64];

bool same(int n, int x, int y)
{
	for (int i = y; i < y + n; i++)
		for (int j = x; j < x + n; j++)
			if (arr[y][x] != arr[i][j]) return false;
	return true;
}

void solve(int n, int x, int y)
{
	if (n == 0) return;
	if (same(n, x, y))
	{
		printf("%d", arr[y][x]);
	}
	else
	{
		printf("(");
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++) {
				
				solve(n / 2, x + n / 2 * j, y + n / 2 * i);
				
			}
		printf(")");
	}
}

int main()
{
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%1d", &arr[i][j]);

	solve(N, 0, 0);

	return 0;
}