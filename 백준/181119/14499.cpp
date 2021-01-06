#include <iostream>
using namespace std;

int map[21][21];
int dice[4][3] = { 0 };

const int dx[4] = { 1,-1,0,0 }; // right left up down
const int dy[4] = { 0,0,-1,1 };

void spin(int x, int y, int order) {
	int temp;
	switch (order)
	{
	case 1: //right
		temp = dice[3][1];
		dice[3][1] = dice[1][2];
		dice[1][2] = dice[1][1];
		dice[1][1] = dice[1][0];
		dice[1][0] = temp;
		break;
	case 2: //left
		temp = dice[3][1];
		dice[3][1] = dice[1][0];
		dice[1][0] = dice[1][1];
		dice[1][1] = dice[1][2];
		dice[1][2] = temp;
		break;
	case 3: //up
		temp = dice[0][1];
		dice[0][1] = dice[1][1];
		dice[1][1] = dice[2][1];
		dice[2][1] = dice[3][1];
		dice[3][1] = temp;
		break;
	case 4: //down
		temp = dice[3][1];
		dice[3][1] = dice[2][1];
		dice[2][1] = dice[1][1];
		dice[1][1] = dice[0][1];
		dice[0][1] = temp;
		break;
	default:
		break;
	}
}

int main()
{
	int N, M, x, y, K;
	scanf("%d %d %d %d %d", &N, &M, &y, &x, &K);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
		}

	int order;
	for (int i = 0; i < K; i++) {
		scanf("%d", &order);

		int nx = x + dx[order - 1];
		int ny = y + dy[order - 1];

		if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;

		spin(nx, ny, order);

		if (map[ny][nx] == 0) map[ny][nx] = dice[3][1]; //맵이 0이면 주사위의 밑부분이 복사된다.
		else  { //맵이 0이 아니면 바닥면에 복사되고 맵은 0이 된다.
			dice[3][1] = map[ny][nx];
			map[ny][nx] = 0;
		}

		x = nx; y = ny;
		printf("%d\n", dice[1][1]);
	}
	return 0;
}