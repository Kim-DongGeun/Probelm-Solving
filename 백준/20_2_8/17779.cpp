#include <iostream>
using namespace std;

int Map[21][21];
int N, sum = 0;;
int ans = INT32_MAX;


void input() {
	cin >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++) {
			cin >> Map[i][j];
			sum += Map[i][j];
		}
}

void solve() {
	for (int x = 2; x <= N - 1; x++) {
		for (int y = 1; y <= N - 2; y++) {
			for (int d1 = 1; d1 <= N; d1++) {
				for (int d2 = 1; d2 <= N; d2++) {
					if (x + d1 + d2 <= N && y - d1 >= 1 && y + d2 <= N) {
						int visited[21][21] = { 0, };
						int MIN = INT16_MAX;
						int MAX = 0;
						int people[6] = { 0, };
						int tempSum = sum;

						for (int i = 1; i < x + d1; i++) { // 1번구역
							for (int j = 1; j <= y; j++) {
								visited[i][j] = 1;
							}
						}

						for (int i = 1; i <= x + d2; i++) { // 2번구역
							for (int j = y + 1; j <= N; j++) {
								visited[i][j] = 2;
							}
						}

						for (int i = x + d1; i <= N; i++) { // 3번구역
							for (int j = 1; j < y - d1 + d2; j++) {
								visited[i][j] = 3;
							}
						}

						for (int i = x + d2 + 1; i <= N; i++) { // 4번구역
							for (int j = y - d1 + d2; j <= N; j++) {
								visited[i][j] = 4;
							}
						}
						// 5구역 경계선
						for (int i = 0; i <= d1; i++) {
							visited[x + i][y - i] = 5;
						}

						for (int i = 0; i <= d2; i++) {
							visited[x + i][y + i] = 5;
						}

						for (int i = 0; i <= d2; i++) {
							visited[x + d1 + i][y - d1 + i] = 5;
						}

						for (int i = 0; i <= d1; i++) {
							visited[x + d2 + i][y + d2 - i] = 5;
						}

						// 인구 수 계산
						for (int i = 1; i < x + d1; i++) {
							for (int j = 1; j <= y; j++) {
								if (visited[i][j] == 5) break;
								people[visited[i][j]] += Map[i][j];
							}
						}
						tempSum -= people[1];

						for (int i = 1; i <= x + d2; i++) {
							for (int j = N; j >= y + 1; j--) {
								if (visited[i][j] == 5) break;
								people[visited[i][j]] += Map[i][j];
							}
						}
						tempSum -= people[2];

						for (int i = x + d1; i <= N; i++) {
							for (int j = 1; j < y - d1 + d2; j++) {
								if (visited[i][j] == 5) break;
								people[visited[i][j]] += Map[i][j];
							}
						}
						tempSum -= people[3];

						for (int i = x + d2 + 1; i <= N; i++) {
							for (int j = N; j >= y - d1 + d2; j--) {
								if (visited[i][j] == 5) break;
								people[visited[i][j]] += Map[i][j];
							}
						}
						tempSum -= people[4];
						people[5] = tempSum;

						for (int i = 1; i <= 5; i++) {
							MAX = MAX < people[i] ? people[i] : MAX;
							MIN = MIN > people[i] ? people[i] : MIN;
						}
						ans = ans > (MAX - MIN) ? (MAX - MIN) : ans; // 차이 최소값계산
					}
				}
			}
		}
	}

}

int main() {
	input();
	solve();

	printf("%d\n", ans);
	return 0;
}
