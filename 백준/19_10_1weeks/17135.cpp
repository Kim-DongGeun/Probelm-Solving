#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
using namespace std;

struct Info
{
	int x;
	int y;
	int index;

	bool operator<(Info i) const {
		if (this->y > i.y)
			return true;
		else if (this->y == i.y)
			return this->x < i.x;
		else
			return false;
	}
};

int N, M, D;
int Map[17][16];
vector<Info> enemyLocationArr;
vector<Info> tempEnemyLocationArr;


bool cmp(const Info& I1, const Info& I2) {
	if (I1.y > I2.y) {
		return true;
	}
	else if (I1.y == I2.y) {
		return I1.x < I2.x;
	}
	else {
		return false;
	}
}
bool CMP(const Info& I1, const Info& I2) {
	if (I1.x < I2.x) {
		return true;
	}
	return false;
}


int main() {
	enemyLocationArr.clear();
	scanf_s("%d %d %d", &N, &M, &D);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf_s("%d", &Map[i][j]);
			if (Map[i][j] == 1) {
				enemyLocationArr.push_back({ j,i, 0 });
			}
		}
	}
	const int archerY = N;
	int archerX[3] = { 0, };
	set<Info> deadEnemy;
	int index = 0;
	int ans = 0;
	int cnt = 0;

	vector<int> archerLocationArr(M, 0);
	archerLocationArr[M - 3] = 1;
	archerLocationArr[M - 2] = 1;
	archerLocationArr[M - 1] = 1;
	sort(enemyLocationArr.begin(), enemyLocationArr.end(), cmp);

	do {
		cnt = 0;
		index = 0;
		tempEnemyLocationArr = enemyLocationArr;
		for (int i = 0; i < M; i++) {
			if (archerLocationArr[i] == 1) archerX[index++] = i;
		}
		while (tempEnemyLocationArr.size()) {
			for (int j = 0; j < 3; j++) {
				int currentMin = D;
				vector<Info> currentIndex;
				for (int i = 0; i < tempEnemyLocationArr.size(); i++) {
					if (abs(tempEnemyLocationArr[i].y - archerY) + abs(tempEnemyLocationArr[i].x - archerX[j]) <= D) {
						if (currentMin > abs(tempEnemyLocationArr[i].y - archerY) + abs(tempEnemyLocationArr[i].x - archerX[j])) {
							currentIndex.clear();
							currentIndex.push_back({ tempEnemyLocationArr[i].x, tempEnemyLocationArr[i].y, i });
							currentMin = abs(tempEnemyLocationArr[i].y - archerY) + abs(tempEnemyLocationArr[i].x - archerX[j]);

						}
						else if (currentMin == abs(tempEnemyLocationArr[i].y - archerY) + abs(tempEnemyLocationArr[i].x - archerX[j])) {
							currentIndex.push_back({ tempEnemyLocationArr[i].x, tempEnemyLocationArr[i].y, i });
						}
					}
				}
				if (!currentIndex.empty()) {
					sort(currentIndex.begin(), currentIndex.end(), CMP);
					deadEnemy.insert(currentIndex[0]);
				}
			}
			for (auto iter = deadEnemy.begin(); iter != deadEnemy.end(); iter++) {
				for (auto Iter = tempEnemyLocationArr.begin(); Iter != tempEnemyLocationArr.end(); Iter++) {
					if ((*iter).x == (*Iter).x && (*iter).y == (*Iter).y) {
						tempEnemyLocationArr.erase(Iter);
						cnt++;
						break;
					}
				}
			}
			deadEnemy.clear();
			for (int i = 0; i < tempEnemyLocationArr.size(); i++) {
				if (tempEnemyLocationArr[i].y == N - 1) {
					tempEnemyLocationArr.erase(tempEnemyLocationArr.begin() + i);
					i--;
				}
				else tempEnemyLocationArr[i].y++;
			}

		}
		ans = max(ans, cnt);
	} while (next_permutation(archerLocationArr.begin(), archerLocationArr.end()));

	printf("%d\n", ans);
	
	return 0;
}

