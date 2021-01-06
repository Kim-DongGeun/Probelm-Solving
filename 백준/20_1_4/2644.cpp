#include <iostream>
#include <queue>
using namespace std;

struct Data { int cur, cnt; };

int main() {
	int n, m, from, to;
	vector<vector<int>> Map(101);
	int parent, child;
	bool check[101] = {false};


	cin >> n;
	cin >> from >> to;
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> parent >> child;
		Map[parent].push_back(child);
		Map[child].push_back(parent);
	}

	int ans = -1;
	queue<Data> q;
	q.push({ from, 0 });
	check[from] = true;
	while (!q.empty()) {
		Data temp = q.front();
		q.pop();

		if (temp.cur == to) {
			ans = temp.cnt;
			break;
		}

		for (int i = 0; i < Map[temp.cur].size(); i++) {
			if (!check[Map[temp.cur][i]]) {
				q.push({ Map[temp.cur][i], temp.cnt + 1 });
				check[Map[temp.cur][i]] = true;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}