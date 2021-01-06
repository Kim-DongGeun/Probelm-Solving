/*
	정말 짜증나는 문제
*/
#include <iostream>
#include <string>
#include <queue>
using namespace std;

#define MAX 1000
string map[22];

enum Direction
{
	Right, UP, Left, Down
};

int visit[21][21][4][16] = {};
int dx[4] = { 1,0,-1,0 }; // R U L D
int dy[4] = { 0,-1,0,1 };
int R, C;

struct Data {
	int y, x;
	int memory, index;
};

/*bool dfs(int memory, int count, int y, int x, int index)
{
	if (count == 1000) {
		return false;
	}

	visit[y][x][memory] = 1;

	if (map[y][x] == '?')
	{
		for (int i = 0; i < 4; i++)
		{
			x = (x + dx[index + i] + C) % C;
			y = (y + dy[index + i] + R) % R;

			if (visit[y][x][memory]) continue;
			return dfs(memory, count + 1, y, x, index);
		}
	}
	else {
		if (map[y][x] >= '0' && map[y][x] <= '9')
			memory = map[y][x] - '0';
		else if (map[y][x] == '<')
			index = Left;
		else if (map[y][x] == '>')
			index = Right;
		else if (map[y][x] == '^')
			index = UP;
		else if (map[y][x] == 'v')
			index = Down;
		else if (map[y][x] == '_')
			index = memory == 0 ? Right : Left;
		else if (map[y][x] == '|')
			index = memory == 0 ? Down : UP;
		else if (map[y][x] == '@') {
			return true;
		}
		else if (map[y][x] == '-')
			memory = memory == 0 ? 15 : memory -= 1;
		else if (map[y][x] == '+')
			memory = memory == 15 ? 0 : memory += 1;
		x = (x + dx[index] + C) % C;
		y = (y + dy[index] + R) % R;

		//if (visit[y][x][memory]) return false;
		return dfs(memory, count + 1, y, x, index);
	}
}*/


int main()
{
	int T, ans;
	scanf("%d", &T);

	for (int test = 1; test <= T; test++)
	{
		ans = 0;
		scanf("%d %d", &R, &C);

		for (int i = 0; i < R; i++)
			cin >> map[i];

		for (int i = 0; i < 21; i++)
			for (int j = 0; j < 21; j++)
				for (int l = 0; l < 4; l++)
					for (int k = 0; k < 16; k++)
						visit[i][j][l][k] = 0;

		Data d = { 0,0,0,0 };
		queue<Data> q;
		q.push(d);
		visit[0][0][0][0] = 1;
		while (!q.empty())
		{
			auto cur = q.front();
			q.pop();


			if (map[cur.y][cur.x] >= '0' && map[cur.y][cur.x] <= '9')
				cur.memory = map[cur.y][cur.x] - '0';
			else if (map[cur.y][cur.x] == '<')
				cur.index = Left;
			else if (map[cur.y][cur.x] == '>')
				cur.index = Right;
			else if (map[cur.y][cur.x] == '^')
				cur.index = UP;
			else if (map[cur.y][cur.x] == 'v')
				cur.index = Down;
			else if (map[cur.y][cur.x] == '_')
				cur.index = cur.memory == 0 ? Right : Left;
			else if (map[cur.y][cur.x] == '|')
				cur.index = cur.memory == 0 ? Down : UP;
			else if (map[cur.y][cur.x] == '@') {
				ans = 1;
				break;
			}
			else if (map[cur.y][cur.x] == '?') {
				for (int i = 0; i < 4; i++) {
					int ny = (cur.y + dy[i] + R) % R;
					int nx = (cur.x + dx[i] + C) % C;
					if (visit[ny][nx][i][cur.memory]) continue;
					visit[ny][nx][i][cur.memory] = 1;
					q.push({ ny, nx, cur.memory, i });
				}
				continue;
			}
			else if (map[cur.y][cur.x] == '-')
				cur.memory = cur.memory == 0 ? 15 : cur.memory -= 1;
			else if (map[cur.y][cur.x] == '+')
				cur.memory = cur.memory == 15 ? 0 : cur.memory += 1;

			int nx = (cur.x + dx[cur.index] + C) % C;
			int ny = (cur.y + dy[cur.index] + R) % R;
			if (visit[ny][nx][cur.index][cur.memory]) continue;
			visit[ny][nx][cur.index][cur.memory] = 1;
			q.push({ ny, nx, cur.memory, cur.index });
		}


		printf("#%d %s\n", test, ans ? "YES" : "NO");
	}
	return 0;
}

