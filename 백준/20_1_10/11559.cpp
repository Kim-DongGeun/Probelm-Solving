#include <iostream>
#include <cstring>
using namespace std;

char Map[12][6];
bool check[12][6];

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,-1,0,1 };

int boomCnt = 0;

void dfs(int x, int y, char flag) {
	for (int i = 0; i < 4; i++) {
		int nx = dx[i] + x;
		int ny = dy[i] + y;

		if (nx < 0 || nx >= 6 || ny < 0 || ny >= 12 || check[ny][nx] || Map[ny][nx] != flag) continue;

		boomCnt++;
		check[ny][nx] = true;
		dfs(nx, ny, flag);
	}
}

int main() {
	
	for (int i = 0; i < 12; i++)
		for (int j = 0; j < 6; j++)
			scanf_s(" %c", &Map[i][j]);

	int ans = 0;
	while (true) {
		bool find = false;
		for (int i = 11; i >= 0; i--) { // 찾기
			int cnt = 0;
			for (int j = 0; j < 6; j++) {
				if (Map[i][j] == '.') cnt++;
				else {
					if (!check[i][j]) {
						memset(check, false, sizeof(check)); // 초기화
						boomCnt = 1;
						check[i][j] = true;
						dfs(j, i, Map[i][j]);
						if (boomCnt >= 4) {
							find = true;
							for (int k = 0; k < 12; k++) // 맵 바꾸기
								for (int l = 0; l < 6; l++)
									if (check[k][l]) Map[k][l] = '.';
						}
					}
				}
			}
			if (cnt == 5) break;
		}

		if (find) ans++;
		else break;

		for (int i = 11; i >= 0; i--) { // 내리기
			int cnt = 0;
			for (int j = 0; j < 6; j++) {
				if (Map[i][j] != '.') {
					int tempY = i + 1;
					for(;tempY <= 11 && Map[tempY][j] == '.'; tempY++)
						swap(Map[tempY][j], Map[tempY - 1][j]);
				}
			}
			if (cnt == 6) break;
		}
		
	}
	printf("%d\n", ans);
	return 0;
}

