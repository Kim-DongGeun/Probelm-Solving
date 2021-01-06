#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int Map[51][51];
vector<pair<int, int>> home;
vector<pair<int, int>> chicken;

int main() {
	int N, M;
	scanf_s("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf_s("%d", &Map[i][j]);
			if (Map[i][j] == 1) { // 집일떄
				home.push_back(make_pair(i, j));
			}
			else if (Map[i][j] == 2) { // 치킨집일때
				chicken.push_back(make_pair(i, j));
			}
		}
	}

	vector<int> chickenCheck(chicken.size(), 0);

	for (int i = 0; i < M; i++)
		chickenCheck[i] = 1;

	reverse(chickenCheck.begin(), chickenCheck.end());

	int ans = INT32_MAX;
	do {
		int chickenDisOfCity = 0;
		for (int i = 0; i < home.size(); i++) {
			int chickenDis = INT32_MAX;
			for (int j = 0; j < chicken.size(); j++) {
				if (chickenCheck[j] == 1) {
					chickenDis = (abs(home[i].first - chicken[j].first) + abs(home[i].second - chicken[j].second)) < chickenDis ?
						abs(home[i].first - chicken[j].first) + abs(home[i].second - chicken[j].second) : chickenDis;
				}
			}
			chickenDisOfCity += chickenDis;
		}
		ans = chickenDisOfCity < ans ? chickenDisOfCity : ans;
	} while (next_permutation(chickenCheck.begin(), chickenCheck.end()));

	printf("%d\n", ans);
	return 0;
}