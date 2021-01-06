#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int map[101][101];
int check[101];

int main()
{
	for (int t = 1; t <= 10; t++) {
		int N, start, from ,to;
		scanf("%d %d", &N, &start);

		for (int i = 0; i < 101; i++) {
			check[i] = 0;
			for (int j = 0; j < 101; j++)
				map[i][j] = 0;
		}

		for (int i = 0; i < N / 2; i++) {
			scanf("%d %d", &from, &to);
			map[from][to] = 1;
		}

		queue<int> q;
		q.push(start);
		check[start] = 1;
		while (!q.empty()) {
			int cur = q.front();
			q.pop();

			for (int i = 0; i < 101; i++)
			{
				if (check[i] || !map[cur][i]) continue;

				check[i] = check[cur] + 1;
				q.push(i);
			}
		}

		int ans = 0, max = 0;
		for (int i = 0; i < 101; i++)
		{
			if (check[i] > max) {
				max = check[i];
				ans = i;
			}
			else if (check[i] == max && ans < i) ans = i;
		}


		printf("#%d %d\n", t, ans);
	}
	return 0;
}