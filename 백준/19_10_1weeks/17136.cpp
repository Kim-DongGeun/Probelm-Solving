#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

struct Info
{
	int x;
	int y;
};

int dfs_visited[11][11] = { false, };
int Map[11][11] = { 0, };
int paperCntArr[6] = { 0,5,5,5,5,5 };
vector<Info> locationOfOneArr;
int ans = INT16_MAX;
bool notAns = true;

int checkArr(int x, int y, int gap) {
	if (x + gap > 10 || y + gap > 10) return false;
	for (int i = y; i < y + gap; i++)
		for (int j = x; j < x + gap; j++)
			if (Map[i][j] == 0 || dfs_visited[i][j]) return false;
	return true;
}

void changeVisited(int x, int y, int maxIndex, bool flag) {
	for (int i = y; i < y + maxIndex; i++)
		for (int j = x; j < x + maxIndex; j++)
			dfs_visited[i][j] = flag;
}


void dfs(int cnt, int currentIndex, int oneCnt) {
	int x = currentIndex % 10;
	int y = currentIndex / 10;
	
	if (oneCnt == locationOfOneArr.size()) {
		notAns = false;
		//ans = min(ans, cnt);
		if (ans > cnt)
			ans = cnt;
		return;
	}
	if (currentIndex == 100 || cnt >= ans) return;
	if (dfs_visited[y][x] || Map[y][x] == 0) dfs(cnt, currentIndex + 1, oneCnt); // 방문했으면 다음꺼
	else {
		if (paperCntArr[1]) {
			dfs_visited[y][x] = true;
			paperCntArr[1]--;
			dfs(cnt + 1, currentIndex + 1, oneCnt + 1);
			dfs_visited[y][x] = false;
			paperCntArr[1]++;
		}

		if (paperCntArr[2]) {
			if (checkArr(x, y, 2)) {
				changeVisited(x, y, 2, true);
				paperCntArr[2]--;
				dfs(cnt + 1, currentIndex + 1, oneCnt + 4);
				changeVisited(x, y, 2, false);
				paperCntArr[2]++;
			}
		}

		if (paperCntArr[3]) {
			if (checkArr(x, y, 3)) {
				changeVisited(x, y, 3, true);
				paperCntArr[3]--;
				dfs(cnt + 1, currentIndex + 1, oneCnt + 9);
				changeVisited(x, y, 3, false);
				paperCntArr[3]++;
			}
		}

		if (paperCntArr[4]) {
			if (checkArr(x, y, 4)) {
				changeVisited(x, y, 4, true);
				paperCntArr[4]--;
				dfs(cnt + 1, currentIndex + 1, oneCnt + 16);
				changeVisited(x, y, 4, false);
				paperCntArr[4]++;
			}
		}

		if (paperCntArr[5]) {
			if (checkArr(x, y, 5)) {
				changeVisited(x, y, 5, true);
				paperCntArr[5]--;
				dfs(cnt + 1, currentIndex + 1, oneCnt + 25);
				changeVisited(x, y, 5, false);
				paperCntArr[5]++;
			}
		}
	}
}

int main() {
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++) {
			scanf_s("%d", &Map[i][j]);
			if (Map[i][j] == 1) locationOfOneArr.push_back({ j,i });
		}


	if (locationOfOneArr.size() == 0) {
		printf("0\n");
		return 0;
	}

	dfs(0,0,0);

	if (notAns) printf("-1\n");
	else printf("%d\n", ans);

	return 0;
}