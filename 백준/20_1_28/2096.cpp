#include <stdio.h>
#include <algorithm>


int Map[3];
int max_visited[100001][3];
int min_visited[100001][3];



int main() {
	int N;
	scanf("%d\n", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d %d %d", &Map[0], &Map[1], &Map[2]);

		max_visited[i][0] = std::max(max_visited[i - 1][0], max_visited[i - 1][1]) + Map[0];
		max_visited[i][1] = std::max(std::max(max_visited[i - 1][0], max_visited[i - 1][1]), max_visited[i - 1][2]) + Map[1];
		max_visited[i][2] = std::max(max_visited[i - 1][1], max_visited[i - 1][2]) + Map[2];

		min_visited[i][0] = std::min(min_visited[i - 1][0], min_visited[i - 1][1]) + Map[0];
		min_visited[i][1] = std::min(std::min(min_visited[i - 1][0], min_visited[i - 1][1]), min_visited[i - 1][2]) + Map[1];
		min_visited[i][2] = std::min(min_visited[i - 1][1], min_visited[i - 1][2]) + Map[2];
	}
	printf("%d %d\n", std::max(std::max(max_visited[N][0], max_visited[N][1]), max_visited[N][2]), std::min(std::min(min_visited[N][0], min_visited[N][1]), min_visited[N][2]));

	return 0;
}