#include <iostream>
using namespace std;

int Map[51][51];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, M, T;
	int x, d, k;
	cin >> N >> M >> T;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			cin >> Map[i][j];

	for (int i = 0; i < T; i++) {
		cin >> x >> d >> k;

		for (int a = 1; a * x <= N; a++) {
			if (d == 0) { // 시계 방향
				for (int c = 0; c < k % M; c++) {
					int temp = Map[a * x][M];
					for (int b = M-1; b >= 1; b--) {
						Map[a * x][b + 1] = Map[a * x][b];
					}
					Map[a * x][1] = temp;
				}
			}
			else { // 반시계 방향
				for (int c = 0; c < k % M; c++) {
					int temp = Map[a * x][1];
					for (int b = 2; b <= M; b++) {
						Map[a * x][b - 1] = Map[a * x][b];
					}
					Map[a * x][M] = temp;
				}
			}
		}

		bool overdo = false;
		bool visited[51][51] = { false, };
		for (int a = 1; a <= N; a++) { // 인접체크해서 없애기
			for (int b = 1; b <= M; b++) {
				bool out = false;
				if (Map[a][b] == 0) continue;
				if (Map[a][b] == Map[a][b + 1 > M ? 1 : b + 1]) {
					out = true;
					overdo = true;
					visited[a][b + 1 > M ? 1 : b + 1] = true;
				}
				if (Map[a][b] == Map[a][b - 1 == 0 ? M : b - 1]) {
					out = true;
					overdo = true;
					visited[a][b - 1 == 0 ? M : b - 1] = true;
				}
				if (a != N && Map[a][b] == Map[a + 1][b]) {
					out = true;
					overdo = true;
					visited[a + 1][b] = true;
				}
				if (out) visited[a][b] = true;
			}
		}
		for (int a = 1; a <= N; a++) { // 인접체크해서 없애기
			for (int b = 1; b <= M; b++) {
				if (visited[a][b]) Map[a][b] = 0;
			}
		}
		if (!overdo) {
			int sum = 0, cnt = 0;;
			for (int a = 1; a <= N; a++) { // 전체합 구하기
				for (int b = 1; b <= M; b++) {
					if (Map[a][b] != 0) {
						sum	+= Map[a][b];
						cnt++;
					}
				}
			}
			for (int a = 1; a <= N; a++) { // 평균보다 작으면 +1 크면 -1
				for (int b = 1; b <= M; b++) {
					if (Map[a][b] != 0) {
						if ((float)Map[a][b] < (float)sum / cnt)
							Map[a][b]++;
						else if((float)Map[a][b] > (float)sum / cnt) Map[a][b]--;
					}
				}
			}

		}

	}

	int sum = 0;
	for (int a = 1; a <= N; a++) { // 전체합 구하기
		for (int b = 1; b <= M; b++) {
			sum += Map[a][b];
		}
	}
	printf("%d\n", sum);
	return 0;
}