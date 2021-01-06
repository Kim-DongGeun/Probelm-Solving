#include <iostream>
#include <set>
using namespace std;

const int dx[] = { 1,0,-1,0,1,-1,-1,1 };
const int dy[] = { 0,-1,0,1,-1,-1,1,1 };

int N, M, index;

int map[52][52];
bool check[50][50];

void dfs(int curR, int curC)
{
	check[curR][curC] = true;

	for (int i = 0; i < 8; i++)
	{
		int dr = curR + dy[i];
		int dc = curC + dx[i];
		if (dr > 0 && dr <= M && dc > 0 && dc <= N && map[dr][dc] == 1 && check[dr][dc] == false)
		{
			dfs(dr, dc);
		}
	}
}


int main()
{
	
	while (true)
	{
		scanf("%d %d", &N, &M);

		if (N == 0 && M == 0)
			return 0;
		//초기화
		for (int i = 1; i <= M; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				map[i][j] = 0;
				check[i][j] = false;
			}
		}
		//맵 입력
		for (int i = 1; i <= M; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				scanf("%d", &map[i][j]);
			}
		}

		//dfs
		index = 0;
		for (int i = 1; i <= M; i++) {
			for (int j = 1; j <= N; j++) {
				if (check[i][j] == false && map[i][j] == 1)
				{
					index++;
					dfs(i, j);
				}
			}
		}
		//출력
		printf("%d\n", index);
	}
	return 0;
}