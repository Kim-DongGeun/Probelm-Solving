#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

struct pos { int x, y, active, cnt; };
const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,-1,0,1 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M, wall = 0, count = 0;
	int Map[51][51];
	vector<pos> virus;
	

	cin >> N >> M; // 입력
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			cin >> Map[i][j];
			if (Map[i][j] == 2) virus.push_back({ j,i,0,0 });
			else if (Map[i][j] == 1) wall++;
		}

	vector<int> order(virus.size(), 0);
	for (int i = 0; i < M; i++) {
		order[order.size() - 1 - i] = 1;
	}

	count = N * N - wall - virus.size(); // 빈칸 개수 구하기
	int ans = INT32_MAX;
	do {
		int visited[52][52];
		fill(&visited[0][0], &visited[51][51], -1);
		int tempCount = count;

		int cnt = -1;
		queue<pos> q;

		for (int i = 0; i < order.size(); i++) // 임의의 3개 바이러스 활성화
			if (order[i]) {
				virus[i].active = 1;
				q.push(virus[i]);
				visited[virus[i].y][virus[i].x] = 0;
			}

		while (!q.empty()) { // 바이러스 전파
			pos cur = q.front();
			q.pop();

			if (tempCount <= 0) {
				cnt = cnt < cur.cnt ? cur.cnt : cnt;
				continue;
			}

			if (cur.active == 1) {
				for (int i = 0; i < 4; i++) {
					int nx = cur.x + dx[i];
					int ny = cur.y + dy[i];
					if (nx < 0 || ny < 0 || nx >= N || ny >= N || Map[ny][nx] == 1 || visited[ny][nx] != -1) continue;
					visited[ny][nx] = visited[cur.y][cur.x] + 1;
					q.push({ nx, ny , 1, cur.cnt + 1 });
					if(Map[ny][nx] == 0) tempCount--;
				}
			}
		}

		for (int i = 0; i < order.size(); i++) // 원상복구
			if (order[i])
				virus[i].active = 0;
		if(cnt != -1) // 최소 시간 저장
			ans = ans > cnt ? cnt : ans;
	} while (next_permutation(order.begin(), order.end()));

	if (ans == INT32_MAX)
		printf("-1\n");
	else
		printf("%d\n", ans);
	return 0;
}