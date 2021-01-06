#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int map[1002][1002];
int check[1002][1002] = { 0 };
vector<pair<int,int>> arr;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main()
{
	int R, C, num = 1;

	scanf("%d %d", &C, &R);

	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
		{
			scanf("%d", &map[i][j]);
			if (map[i][j] == 1)
				arr.push_back({ i,j });
		}
	}

	queue<pair<int, int>> q;
	for (int i = 0; i < arr.size(); i++) {
		q.push(arr[i]);
		check[arr[i].first][arr[i].second] = 1;
	}

	int ans = 0;
	while (!q.empty())
	{
		int x = q.front().second;
		int y = q.front().first;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nextR = y + dy[i];
			int nextC = x + dx[i];

			if (nextR > 0 && nextR <= R && nextC > 0 && nextC <= C && !check[nextR][nextC] && map[nextR][nextC] == 0)
			{
				q.push({ nextR, nextC });
				check[nextR][nextC] = check[y][x] + 1;
				ans = check[nextR][nextC];
			}
		}
	}

	bool out = false;
	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
		{
			if (check[i][j] == 0 && map[i][j] == 0)
			{
				out = true;
				break;
			}
		}
		if (out)break;
	}
	
	if (out) printf("-1\n");
	else if (ans == 0)printf("%d\n", ans);
	else printf("%d\n", ans-1);
	return 0;
}