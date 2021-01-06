#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int Map[101][101] = { 0, };
map<int, int> m;
vector<pair<int, int>> arr;

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second)
		return a.first < b.first;
	else return a.second < b.second;
}

void calR() {
	for (int i = 1; i <= 100; i++) {
		m.clear();
		arr.clear();
		for (int j = 1; j <= 100; j++) {
			m[Map[i][j]]++;
		}
		for (int j = 1; j <= 100; j++) {
			if (m.count(j)) arr.push_back({ j, m[j] });
		}
		sort(arr.begin(), arr.end(), cmp);
		for (int j = 1; j <= arr.size(); j++) {
			Map[i][2 * j - 1] = arr[j - 1].first;
			Map[i][2 * j] = arr[j - 1].second;
		}
		for (int j = 2 * arr.size() + 1; j <= 100; j++) {
			Map[i][j] = 0;
		}
			
	}
}

void calC() {
	for (int i = 1; i <= 100; i++) {
		m.clear();
		arr.clear();
		for (int j = 1; j <= 100; j++) {
			m[Map[j][i]]++;
		}
		for (int j = 1; j <= 100; j++) {
			if (m.count(j)) arr.push_back({ j, m[j] });
		}
		sort(arr.begin(), arr.end(), cmp);
		for (int j = 1; j <= arr.size(); j++) {
			Map[2 * j - 1][i] = arr[j - 1].first;
			Map[2 * j][i] = arr[j - 1].second;
		}
		for (int j = 2 * arr.size() + 1; j <= 100; j++) {
			Map[j][i] = 0;
		}
	}
}

int main() {
	int r, c, k;

	cin >> r >> c >> k;
	for (int i = 1; i <= 3; i++)
		for (int j = 1; j <= 3; j++)
			cin >> Map[i][j];

	if (Map[r][c] == k) {
		printf("%d\n", 0);
		return 0;
	}
	for (int t = 1; t <= 100; t++) {
		int indexR = 0, indexC = 0;
		for (int i = 1; i <= 100; i++) {
			for (int j = 1; j <= 100; j++) {
				if (Map[i][j] == 0) break;
				indexC = max(indexC, j);
			}
		}

		for (int i = 1; i <= 100; i++) {
			for (int j = 1; j <= 100; j++) {
				if (Map[j][i] == 0) break;
				indexR = max(indexR, j);
			}
		}

		if (indexR >= indexC)
			calR();
		else 
			calC();

		if (Map[r][c] == k) {
			printf("%d\n", t);
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}