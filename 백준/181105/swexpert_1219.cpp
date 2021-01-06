/*
	기본 bfs문제
*/
#include <iostream>
#include <queue>
using namespace std;

int check[100];
int map[100][100];

int main()
{
	for (int t = 1; t <= 10; t++) {
		int test, N, from, to;
		scanf("%d %d", &test, &N);

		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++)
				map[i][j] = 0;
			check[i] = 0;
		}

		for (int i = 0; i < N; i++) {
			scanf("%d %d", &from, &to);
			map[from][to] = 1;
		}

		queue<int> q;
		bool found = false;
		check[0] = 1;
		q.push(0);
		while (!q.empty()) {
			int cur = q.front();
			q.pop();

			if (cur == 99) {
				found = true;
				break;
			}

			for (int i = 0; i < 100; i++) {
				if (map[cur][i] == 1 && !check[i]) {
					q.push(i);
					check[i] = 1;
				}
			}
		}
		printf("#%d %d\n", t, found ? 1 : 0);
	}
	return 0;
}