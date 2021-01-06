/*
	idea : 현재상태에서 갈수있는 방향과 다음상태에 들어갈수있는 방향을 체크해줌
*/
#include <iostream>
using namespace std;

int N, M, R, C, L;
int map[51][51];
int check[51][51];
int ans[51][51];
int IN[7][4] = { {1,1,1,1}, 
				 {0,1,0,1},
				 {1,0,1,0},
				 {0,0,1,1},
				 {0,1,1,0},
				 {1,1,0,0},
				 {1,0,0,1} };
int OUT[7][4] = { {1,1,1,1},
				  {0,1,0,1},
				  {1,0,1,0},
				  {1,1,0,0},
				  {1,0,0,1},
				  {0,0,1,1},
				  {0,1,1,0} };
int dx[4] = { 1,0,-1,0 }; // right : 0 up : 1 left : 2 down : 3
int dy[4] = { 0, -1, 0, 1 };

void dfs(int y, int x, int hour) {
	if (hour > L) return;
	ans[y][x] = 1;
	
	for (int i = 0; i < 4; i++) {
		if (!OUT[map[y][x]-1][i]) continue;
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue; //맵밖으로갈때
		if (!IN[map[ny][nx]-1][i] || !map[ny][nx]) continue; //길이없거나 갈수없을때
		if (check[ny][nx]) continue; //방문한곳이면

		ans[ny][nx] = 1;
		check[ny][nx] = hour;
		dfs(ny, nx, hour + 1);
		check[ny][nx] = 0;
	}
}

int main()
{
	int T;
	scanf("%d", &T);

	for (int t = 1; t <= T; t++) {
		scanf("%d %d %d %d %d", &N, &M, &R, &C, &L);
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++) {
				scanf("%d", &map[i][j]);
				check[i][j] = 0;
				ans[i][j] = 0;
			}

		check[R][C] = 1;
		ans[R][C] = 1;
 		dfs(R, C, 2);
		check[R][C] = 0;

		int sum = 0;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				if (ans[i][j]) sum++;

		printf("#%d %d\n", t, sum);
	}
	return 0;
}