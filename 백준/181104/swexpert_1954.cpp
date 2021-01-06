#include <iostream>
using namespace std;

int map[10][10];

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int N;
int index = 0;

void draw(int y, int x, int value) {
	map[y][x] = value;

	int ny = y + dy[index];
	int nx = x + dx[index];

	if (ny < 0 || ny >= N || nx < 0 || nx >= N || map[ny][nx]) {
		index = (index + 1) % 4;
		ny = y + dy[index];
		nx = x + dx[index];

		if (map[ny][nx]) return;
	}

	draw(ny, nx, value + 1);
}

int main()
{
	int T;
	scanf("%d", &T);

	for (int t = 1; t <= T; t++) {
		scanf("%d", &N);

		index = 0;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++) {
				map[i][j] = 0;
			}

		draw(0, 0, 1);
		printf("#%d\n", t);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++)
				printf("%d ", map[i][j]);
			printf("\n");
		}
	}
	return 0;
}