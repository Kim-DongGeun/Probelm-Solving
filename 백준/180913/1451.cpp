/*
	idea : 직사각형 3개가 만들어질 수 있는 경우가 6가지밖에 없다.
		   경우를 전부 해본다.
*/
#include <iostream>
#include <algorithm>
using namespace std;

long long d[101][101];
int map[101][101];

long long sum(int x1, int y1, int x2, int y2)
{
	return d[y2][x2] - d[y2][x1-1] - d[y1-1][x2] + d[y1-1][x1-1];
}

int main()
{
	int N, M;

	scanf("%d %d", &N, &M);

	//맵 입력
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			scanf("%1d", &map[i][j]);

	//d[i][j]는 map[1][1] ~ map[i][j]까지 합
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			d[i][j] = d[i - 1][j] + d[i][j - 1] - d[i - 1][j - 1] + map[i][j];

	//세로로 나누어질 경우
	long long ans = 0;
	for(int i = 1; i <= M - 2; i++)
		for (int j = i + 1; j <= M - 1; j++)
		{
			long long a1 = sum(1, 1, i, N);
			long long a2 = sum(i + 1, 1, j, N);
			long long a3 = sum(j + 1, 1, M, N);
			ans = max(ans, a1*a2*a3);
		}

	//가로로 나누어질 경우
	for(int i = 1; i <= N-2; i++)
		for (int j = i + 1; j <= N - 1; j++)
		{
			long long a1 = sum(1, 1, M, i);
			long long a2 = sum(1, i + 1, M, j);
			long long a3 = sum(1, j + 1, M, N);
			ans = max(ans, a1*a2*a3);
		}

	//T 형태로 나누어질 경우
	for (int i = 1; i <= N-1; i++)
		for (int j = 1; j <= M - 1; j++)
		{
			long long a1 = sum(1, 1, M, i);
			long long a2 = sum(1, i + 1, j, N);
			long long a3 = sum(j+1, i+1, M, N);
			ans = max(ans, a1*a2*a3);
		}

	// ㅗ 형태로 나누어질 경우
	for (int i = 1; i <= N-1; i++)
		for (int j = 1; j <= M - 1; j++)
		{
			long long a1 = sum(1, 1, j, i);
			long long a2 = sum(j+1, 1, M, i);
			long long a3 = sum(1, i + 1, M, N);
			ans = max(ans, a1*a2*a3);
		}

	// |-- 형태로 나누어질 경우
	for (int i = 1; i <= N - 1; i++)
		for (int j = 1; j <= M - 1; j++)
		{
			long long a1 = sum(1, 1, j, N);
			long long a2 = sum(j + 1, 1, M, i);	
			long long a3 = sum(j + 1, i + 1, M, N);
			ans = max(ans, a1*a2*a3);
		}

	// --| 형태로 나누어질 경우
	for (int i = 1; i <= N - 1; i++)
		for (int j = 1; j <= M-1; j++)
		{
			long long a1 = sum(1, 1, j, i);
			long long a2 = sum(1, i + 1, j, N);
			long long a3 = sum(j + 1, 1, M, N);
			ans = max(ans, a1*a2*a3);
		}

	printf("%lld\n", ans);
	return 0;
}