#include <iostream>
using namespace std;

char map[101][101];
int check[101][101] = { 0 };
int N;

const int dx[4] = { 1 , 0, -1, 0 };
const int dy[4] = { 0, -1, 0 ,1 };

void dfs(int x, int y, char mark) {
	for (int i = 0; i < 4; i++) {
		int nx = dx[i] + x;
		int ny = dy[i] + y;

		if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue; // �� ������ �����
		if (check[ny][nx] == 0 && map[ny][nx] == mark) { // Ž������ ���� ���̸鼭 ���� �����̸�
			check[ny][nx] = mark;
			dfs(nx, ny, mark);
		}
	}
}

int main() {
	scanf_s("%d", &N); // �Է�
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf_s(" %c", &map[i][j]); 


	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (check[i][j] == 0) { // �湮�������� dfs
				dfs(j, i, map[i][j]);
				ans++;
			}
		}
	}

	printf("%d ", ans);
	ans = 0;
	for (int i = 0; i < N; i++) // �湮�Ѱ��� �ٽ� �ʱ�ȭ�ϸ鼭 G�� R�� �ٲ�
		for (int j = 0; j < N; j++) {
			check[i][j] = 0;
			if (map[i][j] == 'G') map[i][j] = 'R';
		}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (check[i][j] == 0) { // �湮�������� dfs
				dfs(j, i, map[i][j]);
				ans++;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}