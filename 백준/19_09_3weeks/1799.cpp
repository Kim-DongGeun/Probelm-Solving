#include <iostream>
#include <algorithm>
using namespace std;

struct Info
{
	int x;
	int y;
};

int N;
int Map[11][11];
int ans = 0;
int visited[11][11] = { 0, };
Info white[56], black[56];
int whiteSize = 0, blackSize = 0;


 

bool check(int x, int y) {
	int tempX = x;
	int tempY = y;

	while (1) {
		tempY++;
		tempX++;
		if (tempY >= N || tempX >= N)  break;
		if (Map[tempY][tempX] == 2) return false;
	}

	tempX = x;
	tempY = y;
	while (1) {
		tempY--;
		tempX--;
		if (tempX < 0 || tempY < 0) break;
		if (Map[tempY][tempX] == 2) return false;
	}

	tempX = x;
	tempY = y;
	while (1) {
		tempY--;
		tempX++;
		if (tempX >= N || tempY < 0) break;
		if (Map[tempY][tempX] == 2) return false;
	}

	tempX = x;
	tempY = y;
	while (1) {
		tempY++;
		tempX--;
		if (tempX < 0 || tempY >= N) break;
		if (Map[tempY][tempX] == 2) return false;
	}
	return true;
}

void dfs(int num, int size, int count, Info* arr) {

	for (int i = num; i < size; i++) {
		int y = arr[i].y;
		int x = arr[i].x;

		if (check(x,y)) {
			Map[y][x] = 2;
			dfs(i + 1, size, count + 1, arr);
			Map[y][x] = 1;
		}
	}

	ans = max(ans, count);
}

int main() {
	scanf_s("%d", &N);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			scanf_s("%d", &Map[i][j]);
			if (Map[i][j] == 1) {
				if ((i + j) % 2 == 0)
					white[whiteSize++] = { j,i };
				else
					black[blackSize++] = { j,i };
			}
		}

	dfs(0, whiteSize, 0, white);
	int ANS = ans;
	ans = 0;
	dfs(0, blackSize, 0, black);
	ANS += ans;

	printf("%d\n", ANS);
	return 0;
}