#include <iostream>
using namespace std;

int N, ans;
int check[101];
int Map[21][21];
int bfs_visited[21][21];
const int dx[4] = { 1,-1,-1,1 };
const int dy[4] = { 1,1,-1,-1 };

void dfs(int sx, int sy, int x, int y, int index) {
	
	int nx = x + dx[index];
	int ny = y + dy[index];

	if (sx == nx && sy == ny) {//ó������ ���ư�����
		ans = ans < bfs_visited[y][x] ? bfs_visited[y][x] : ans;
		return;
	}

	if (!bfs_visited[ny][nx] && ny >= 0 && ny < N && nx >= 0 && nx < N && !check[Map[ny][nx]]) { //�湮���߰� �ߺ��ȵǰ� �� ���� �ȿ� ������
		bfs_visited[ny][nx] = bfs_visited[y][x] + 1;
		check[Map[ny][nx]]++;
		dfs(sx, sy, nx, ny, index);
		bfs_visited[ny][nx] = 0;
		check[Map[ny][nx]]--;
	}

	index = (index + 1) % 4;

	if (index == 0) return;
	nx = x + dx[index];
	ny = y + dy[index];

	if (sx == nx && sy == ny) { //ó������ ���ư�����
		ans = ans < bfs_visited[y][x] ? bfs_visited[y][x] : ans;
		return;
	}

	if (!bfs_visited[ny][nx] && ny >= 0 && ny < N && nx >= 0 && nx < N) { //������ �ٲ㼭 �湮
		if (check[Map[ny][nx]]) return; //�ߺ��Ǹ� ����
		bfs_visited[ny][nx] = bfs_visited[y][x] + 1;
		check[Map[ny][nx]]++;
		dfs(sx, sy, nx, ny, index);
		bfs_visited[ny][nx] = 0;
		check[Map[ny][nx]]--;
	}
}

int main()
{
	int T; 
	scanf("%d", &T);

	for (int t = 1; t <= T; t++) {
		ans = 0;
		scanf("%d", &N);

		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				scanf("%d", &Map[i][j]);

		for (int y = 0; y < N - 2; y++)
			for (int x = 1; x < N - 1; x++) {
				bfs_visited[y][x] = 1;
				check[Map[y][x]] = 1;
				dfs(x, y, x, y, 0);
				check[Map[y][x]] = 0;
				bfs_visited[y][x] = 0;
			}

		printf("#%d %d\n", t, ans == 0 ? -1 : ans);
	}
	return 0;
}