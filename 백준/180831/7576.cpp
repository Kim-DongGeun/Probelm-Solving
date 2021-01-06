#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int dx[] = { 1,0,-1,0 };
const int dy[] = { 0,-1,0,1 };

int map[1002][1002];
int check[1001][1001];
vector<pair<int,int>> tomato;
queue<pair<int, int>> q;
pair<int, int> ans;

int M, N;


int main()
{
	scanf("%d %d", &M, &N);

	// 맵
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			scanf("%d", &map[i][j]);
			if (map[i][j] == 1)
				tomato.push_back(make_pair(i, j));
		}
	}
	int x = tomato.size();
	
	//초기값
	for (int i = 0; i < x; i++)
	{
		q.push(tomato[i]);
		check[tomato[i].first][tomato[i].second] = 1;
	}

	int nextY, nextX;

	while (true)
	{
		if (q.empty())
		{
			ans = make_pair(nextY, nextX);
			break;
		}


		nextY = q.front().first;
		nextX = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int dr = nextY + dy[i];
			int dc = nextX + dx[i];

			if (dr > 0 && dr <= N && dc > 0 && dc <= M && map[dr][dc] == 0 && check[dr][dc] == 0)
			{
				check[dr][dc] = check[nextY][nextX] + 1;
				q.push(make_pair(dr, dc));
			}
		}
	}

	//탐색안된 자리 찾기
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (check[i][j] == 0 && map[i][j] == 0)
			{
				printf("-1\n");
				return 0;
			}
		}
	}

	printf("%d\n", check[ans.first][ans.second] - 1);
	return 0;
}