#include <iostream>
#include <string>
#include <string.h>
using namespace std;

char Map[12][12];
bool visited[12][12];
int T, N, M, ans;

bool Check(int row, int col) {
	if (visited[row][col - 1] || visited[row][col + 1] || visited[row - 1][col + 1] || visited[row - 1][col - 1]) return false;
	else if (Map[row][col - 1] == 'x' || Map[row][col + 1] == 'x' || Map[row - 1][col + 1] == 'x' || Map[row - 1][col - 1] == 'x') return false;
	else return true;
}

void dfs(int row) {
	if (row == N) {
		ans++;
		return;
	}

	for (int col = 0; col < M; col++) {
		visited[row][col] = true;
		if (Check(row, col)) dfs(row + 1);
		visited[row][col] = false;
	}
}

int main() {
	string input;
	cin >> T;
	while (T--) {
		cin >> N >> M;
		for (int i = 1; i <= N; i++) {
			cin >> input;
			for (int j = 1; j <= M; j++) {
				Map[i][j] = input[j - 1];
			}
		}
		ans = 0;
		memset(visited, false, sizeof(visited));
		dfs(0);
		printf("%d\n", ans);
	}
	return 0;
}