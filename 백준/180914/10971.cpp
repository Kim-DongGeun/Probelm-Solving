/*
		idea : 노드가 10이하면 완전탐색으로 시간안에 풀 수 있다고한다.
			   모든 경우의 수를 다 순회하면서 최솟값을 찾음
*/
#include <iostream>
#include <algorithm>
using namespace std;

int N, M = INT32_MAX;
int map[11][11];
bool check[11] = { false };


void dfs(int start, int cur, int cnt, int sum)
{
	if (map[cur][start] && cnt == N) //시작과 연결되어있고 순회 마지막 순서이면
	{
		M = min(M, sum + map[cur][start]); //최솟값 저장
		return;
	}

	for (int i = 1; i <= N; i++)
	{
		if (map[cur][i] && !check[i]) //가는길이 있고 체크가 안되어있으면
		{
			check[i] = true; //체크
			dfs(start, i, cnt + 1, sum + map[cur][i]); //갯수를 늘리고 합을 계산해서 dfs
			check[i] = false; //탐색후 체크 해제
		}
	}
}

int main()
{
	
	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			scanf("%d", &map[i][j]);

	for (int i = 1; i <= N; i++)
	{
		check[i] = true;
		dfs(i, i, 1, 0);
		check[i] = false;
	}

	printf("%d\n", M);
	return 0;
}