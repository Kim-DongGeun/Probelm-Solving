#include <iostream>
using namespace std;

int ans;
int map[101][101];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,-1,0,1 };

void dfs(int x, int y, int index) {

	if (y == 0) {
		ans = x;
		return;
	}
	if (index == 1) {
		int x1 = x + dx[(index + 3) % 4]; //right
		int y1 = y + dy[(index + 3) % 4];

		if (map[y1][x1] == 1 || map[y1][x1] == 2) {
			index = (index + 3) % 4;
			dfs(x1, y1, index);
		}
		else
		{
			x1 = x + dx[(index + 5) % 4]; //left
			y1 = y + dy[(index + 5) % 4];

			if (map[y1][x1] == 1 || map[y1][x1] == 2) {
				index = (index + 5) % 4;
				dfs(x1, y1, index);
			}
			else
			{
				dfs(x + dx[index], y + dy[index], index);
			}
		}
	}
	else if (index == 0) {
		int x1 = x + dx[(index + 5) % 4]; //left
		int y1 = y + dy[(index + 5) % 4];

		if (map[y1][x1] == 1 || map[y1][x1] == 2) {
			index = (index + 5) % 4;
			dfs(x1, y1, index);
		}
		else
		{
			dfs(x + dx[index], y + dy[index], index);
		}
	}
	else if (index == 2)
	{
		int x1 = x + dx[(index + 3) % 4]; //right
		int y1 = y + dy[(index + 3) % 4];

		if (map[y1][x1] == 1 || map[y1][x1] == 2) {
			index = (index + 3) % 4;
			dfs(x1, y1, index);
		}
		else
		{
			dfs(x + dx[index], y + dy[index], index);
		}
	}
}

int main()
{
	for (int t = 1; t <= 10; t++) {
		int test;
		int start;
		ans = 0;
		scanf("%d", &test);

		for (int i = 0; i < 100; i++)
			for (int j = 0; j < 100; j++) {
				scanf("%d", &map[i][j]);
				if (map[i][j] == 2) start = j;
			}
		dfs(start, 99, 1);
		printf("#%d %d\n", t, ans);
	}
	return 0;
}